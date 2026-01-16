# Ardify – Setup Guide

This guide will walk you through setting up the Ardify project both in Tinkercad and on physical hardware.

---

## 🛠 Prerequisites

### For Tinkercad Simulation
- A web browser (Chrome, Firefox, Edge, etc.)
- A [Tinkercad account](https://www.tinkercad.com/) (free)

### For Physical Hardware
- Arduino Uno
- Breadboard
- LED
- 220Ω Resistor
- Potentiometer (10kΩ recommended)
- Jumper wires
- Arduino IDE (download [here](https://www.arduino.cc/en/software))

---

## 💻 Tinkercad Simulation Setup

### 1. Open the Project
- Go to the [Ardify Tinkercad project](https://www.tinkercad.com/things/97JWZVqkdDX-arduify).
- Click "Copy & Tinker" to create your own editable version.

### 2. Start the Simulation
- Click "Start Simulation" in the top-right corner.
- Rotate the potentiometer to see the LED brightness change.

### 3. Modify the Code (Optional)
- Click on the Arduino block to open the code editor.
- Edit the code as desired and click "Start Simulation" again to test your changes.

---

## 🔧 Physical Hardware Setup

### 1. Assemble the Circuit
Follow the schematic below to connect your components:

![Circuit Schematic](../circuit/circuit.png)

- **Arduino Uno:**
  - Connect the middle pin of the potentiometer to **A0**.
  - Connect the outer pins to **5V** and **GND**.
- **LED:**
  - Connect the anode (long leg) to **pin 9** via a 220Ω resistor.
  - Connect the cathode (short leg) to **GND**.

### 2. Upload the Code
- Open the Arduino IDE.
- Copy and paste the code from [ardify.ino](../code/ardify.ino) into a new sketch.
- Connect your Arduino Uno to your computer via USB.
- Select the correct board and port:
  - **Tools > Board > Arduino Uno**
  - **Tools > Port > [Your Arduino Port]**
- Click the "Upload" button (→).

### 3. Test Your Circuit
- Once uploaded, rotate the potentiometer.
- The LED should change brightness smoothly.

---

## ⚠️ Troubleshooting

### Common Issues & Solutions

| Issue                          | Possible Cause                | Solution                                      |
|--------------------------------|-------------------------------|-----------------------------------------------|
| LED does not light up          | Loose connection or wrong pin | Double-check wiring and pin assignments.      |
| LED brightness does not change | Potentiometer not connected    | Ensure the potentiometer is connected to A0. |
| Code upload fails              | Wrong board/port selected     | Check Tools > Board and Tools > Port.         |

---

## 🎓 Next Steps
- Try adding more LEDs or using different sensors.
- Experiment with serial monitoring to print potentiometer values.
- Share your modifications with the community!

---

## 📬 Need Help?
If you encounter any issues or have questions, please [open an issue](https://github.com/yourusername/ardify/issues) on GitHub.
