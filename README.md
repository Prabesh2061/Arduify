# Ardify – Arduino LED Control with Potentiometer

[![Tinkercad Simulation](https://img.shields.io/badge/Tinkercad-Simulate-blue)](https://www.tinkercad.com/things/97JWZVqkdDX-arduify)
[![GitHub License](https://img.shields.io/badge/License-MIT-green)](LICENSE)

A simple Arduino project simulating LED brightness control using a potentiometer, built and tested in Tinkercad.

---

## 📌 Overview
**Ardify** is an Arduino-based project that demonstrates analog input and output by controlling an LED's brightness with a potentiometer. This project is ideal for beginners learning about sensors, actuators, and basic Arduino programming.

**Tinkercad Project:** [Open in Tinkercad](https://www.tinkercad.com/things/97JWZVqkdDX-arduify)

---

## 🛠 Components
| Component         | Quantity | Notes                     |
|-------------------|----------|---------------------------|
| Arduino Uno       | 1        | Microcontroller board     |
| Breadboard        | 1        | For prototyping           |
| LED               | 1        | Output indicator          |
| 220Ω Resistor     | 1        | Current limiting          |
| Potentiometer     | 1        | Analog input              |
| Jumper Wires      | Several  | Connections               |

---

## 📐 Circuit Diagram
![Circuit Schematic](circuit.png)
*(Replace with your exported Tinkercad schematic or simulation screenshot.)*

---

## 💡 How It Works
1. **Input:** The Arduino reads the analog voltage from the potentiometer (0-1023).
2. **Processing:** The value is mapped to a PWM output range (0-255).
3. **Output:** The LED brightness changes proportionally to the potentiometer position.

---

## 📝 Code
```cpp
// Ardify - LED Brightness Control with Potentiometer

const int POT_PIN = A0;    // Potentiometer connected to analog pin A0
const int LED_PIN = 9;     // LED connected to digital pin 9 (PWM)

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(POT_PIN);          // Read potentiometer value
  int outputValue = map(sensorValue, 0, 1023, 0, 255); // Map to PWM range
  analogWrite(LED_PIN, outputValue);              // Set LED brightness
}
