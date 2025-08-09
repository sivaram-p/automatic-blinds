#include <Servo.h> // Include Servo library

const int trigPin = 9;     // Ultrasonic sensor trig
const int echoPin = 10;    // Ultrasonic sensor echo
const int servoPin = 11;   // Servo motor pin
const int presenceThreshold = 6;  // cm threshold for presence detection
const int maxDistance = 400;       // Max range for HC-SR04 (~400 cm)

// Moving average variables for detecting small deflections
const int numReadings = 5;  // Number of readings for averaging
int readings[numReadings];  // Array to store recent distance readings
int readIndex = 0;          // Index of current reading
long total = 0;             // Running total for averaging
int averageDistance = 0;    // Averaged distance

long duration;
int distanceCm;
Servo myServo; // Create Servo object

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin); // Attach servo to pin 11
  myServo.write(0);       // Initialize blinds closed (0 degrees)

  // Initialize readings array to 0
  for (int i = 0; i < numReadings; i++) {
    readings[i] = 0;
  }
}

void loop() {
  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo duration with timeout (30ms = ~500 cm max range)
  duration = pulseIn(echoPin, HIGH, 30000);

  // Calculate distance
  if (duration == 0 || duration > 23529) { // 23529 µs = ~400 cm
    distanceCm = -1; // Indicate error or out-of-range
  } else {
    distanceCm = duration * 0.034 / 2; // Speed of sound: 34 cm/ms, divide by 2 for round-trip
  }

  // Update moving average for small deflections
  total = total - readings[readIndex]; // Subtract oldest reading
  readings[readIndex] = (distanceCm == -1) ? readings[(readIndex - 1 + numReadings) % numReadings] : distanceCm; // Use previous valid reading if error
  total = total + readings[readIndex]; // Add new reading
  readIndex = (readIndex + 1) % numReadings; // Advance index
  averageDistance = total / numReadings; // Calculate average

  // Control blinds based on presence
  bool personDetected = (averageDistance > 0 && averageDistance < presenceThreshold);
  if (personDetected) {
    myServo.write(90); // Open blinds (90 degrees)
  } else {
    myServo.write(0);  // Close blinds (0 degrees)
  }

  // Print status for debugging
  Serial.print("Raw Distance: ");
  if (distanceCm == -1) {
    Serial.print("Error/Out of Range");
  } else {
    Serial.print(distanceCm);
    Serial.print(" cm");
  }
  Serial.print(", Avg Distance: ");
  Serial.print(averageDistance);
  Serial.print(" cm, Blinds: ");
  Serial.println(personDetected ? "Open" : "Closed");

  // Detect small deflections (e.g., change of ±5 cm between consecutive averages)
  static int lastAverage = averageDistance;
  int deflection = abs(averageDistance - lastAverage);
  if (deflection > 5 && averageDistance > 0) {
    Serial.print("Deflection Detected: ");
    Serial.print(deflection);
    Serial.println(" cm change");
  }
  lastAverage = averageDistance;

  delay(500); // Adjust for responsiveness
}
