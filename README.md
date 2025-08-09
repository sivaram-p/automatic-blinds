# Automated Hall Blinds with People Detection

Automated hall blinds system using Arduino, ultrasonic sensor for people detection, and LDR for light sensing. Adjusts blinds automatically based on presence and light levels, with real-time distance and light readings shown on Serial Monitor.

This project uses an **Arduino**, an **LDR sensor**, and an **ultrasonic sensor** to automatically control blinds.  
If an object/person is detected within a **7 cm range** of the ultrasonic sensor, the system checks the light level and opens or closes the blinds accordingly.

---

## 📌 Features
- **People/Object Detection** – Ultrasonic sensor detects objects within a short range (7 cm by default).
- **Automatic Light Control** – LDR sensor measures ambient light to decide blind position.
- **Servo Motor Control** – Opens or closes blinds smoothly.
- **Serial Monitor Feedback** – Shows live distance and light readings.
- **Energy Efficient** – Operates only when presence is detected.

---

## 🛠 Components Required
| Component | Quantity | Description |
|-----------|----------|-------------|
| Arduino Uno / Nano | 1 | Main controller |
| LDR Sensor | 1 | Detects light intensity |
| Ultrasonic Sensor (HC-SR04) | 1 | Detects presence within 7 cm |
| Servo Motor | 1 | Controls blinds |
| Resistor (e.g., 10kΩ) | 1 | For LDR voltage divider |
| Jumper Wires | - | For connections |
| Breadboard / PCB | 1 | Circuit assembly |

## Project Images
<p align="center">
  <img src="images/images1.jpg" alt="Project Image 1" width="45%">
  <img src="images/images2.jpg" alt="Project Image 2" width="45%">
</p>
<p align="center">
  <img src="images/images3.jpg" alt="Project Image 3" width="45%">
</p>

[![Watch the video](images/images2.jpg)](https://drive.google.com/file/d/111M2clpo4o4EK6LZJRgMXDi_AQRVTMFY/view?usp=sharing)