# automatic-blinds
created a automatic blind if person is detected in room
# Automated Blinds for Halls (Arduino Project)

An Arduino-powered system to automatically control window blinds in large halls based on **light intensity**, **time schedule**, and **people presence detection**.  
Perfect for auditoriums, classrooms, and conference halls to improve **energy efficiency** and **comfort**.

---

## 📌 Features
- **Automatic Light Sensing** – Adjusts blinds based on ambient light using an LDR sensor.
- **People Detection** – Uses an ultrasonic sensor to detect human presence and activate blinds only when needed.
- **Scheduled Operation** – Opens/closes blinds at specific times of the day.
- **Manual Override** – Control blinds via push buttons or remote.
- **Low Power Consumption** – Energy-efficient design.
- **Customizable Settings** – Thresholds and timings can be adjusted in code.

---

## 🛠 Components Required
| Component | Quantity | Description |
|-----------|----------|-------------|
| Arduino Uno / Nano | 1 | Main controller |
| LDR Sensor | 1 | Detects light intensity |
| Ultrasonic Sensor (HC-SR04) | 1 | Detects people presence |
| Servo Motor / Stepper Motor | 1 | Controls blinds |
| Motor Driver (if stepper used) | 1 | Drives the motor |
| Push Buttons | 2 | Manual up/down control |
| Resistors | 2 | For LDR and buttons |
| Jumper Wires | - | For connections |
| Breadboard / PCB | 1 | Circuit assembly |

---

## ⚙ Circuit Diagram
*(Insert your circuit image here)*  
![Circuit Diagram](docs/circuit.png)

---

## 📂 Project Structure