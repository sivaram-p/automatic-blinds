#include <Servo.h>

#define LDR_PIN A0
#define TRIG_PIN 9
#define ECHO_PIN 8
#define SERVO_PIN 5

int lightThreshold = 500;
int presenceDistance = 7; 
int servoOpenAngle = 0;
int servoCloseAngle = 90;

Servo blindServo;
int currentAngle = 0;

void setup() {
  Serial.begin(9600);
  blindServo.attach(SERVO_PIN);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  blindServo.write(servoOpenAngle);
  currentAngle = servoOpenAngle;
}

void loop() {
  int lightLevel = analogRead(LDR_PIN);
  int distance = getDistance();

  Serial.print("Distance (cm): ");
  Serial.print(distance);
  Serial.print(" | Light Level: ");
  Serial.println(lightLevel);

  if (distance <= presenceDistance) {
    if (lightLevel > lightThreshold) {
      closeBlinds();
    } else {
      openBlinds();
    }
  }
  delay(300);
}

int getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

void openBlinds() {
  if (currentAngle != servoOpenAngle) {
    blindServo.write(servoOpenAngle);
    currentAngle = servoOpenAngle;
    Serial.println("Blinds OPEN");
  }
}

void closeBlinds() {
  if (currentAngle != servoCloseAngle) {
    blindServo.write(servoCloseAngle);
    currentAngle = servoCloseAngle;
    Serial.println("Blinds CLOSED");
  }
}