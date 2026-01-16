
---

## **docs/setup_guide.md**

```markdown
# Ardify – Setup Guide

This guide will help you set up the Ardify Music Player with Lighting in Tinkercad and on physical hardware.

---

## 🛠 Prerequisites

### For Tinkercad Simulation
- A web browser
- A [Tinkercad account](https://www.tinkercad.com/)

### For Physical Hardware
- Arduino Uno
- Breadboard
- Piezo Buzzer
- 16x2 LCD Display
- LEDs (3x)
- 220Ω Resistors (3x)
- Push Buttons (2x)
- Jumper wires
- Arduino IDE

---

## 💻 Tinkercad Simulation Setup

1. **Open the Project**
   - Go to the [Ardify Tinkercad project](https://www.tinkercad.com/things/97JWZVqkdDX-arduify).
   - Click "Copy & Tinker."

2. **Start the Simulation**
   - Click "Start Simulation."
   - Use the buttons to navigate and play songs.

3. **Modify the Code (Optional)**
   - Click on the Arduino block to edit the code.
   - Add your own melodies or lighting effects.

---

## 🔧 Physical Hardware Setup

1. **Assemble the Circuit**
   Follow the schematic:
   ![Circuit Schematic](../circuit/circuit.png)
   - Connect the LCD, buttons, piezo, and LEDs as shown.

2. **Upload the Code**
   - Open the Arduino IDE and paste the code from [ardify.ino](../code/ardify.ino).
   - Select **Tools > Board > Arduino Uno** and the correct port.
   - Click "Upload."

3. **Test Your Circuit**
   - Use the buttons to select and play songs.
   - The LCD will display the current song, and the LEDs will flash with the music.

---

## ⚠️ Troubleshooting

| Issue                          | Possible Cause                | Solution                                      |
|--------------------------------|-------------------------------|-----------------------------------------------|
| LCD not displaying             | Wiring or contrast issue      | Check connections and adjust potentiometer.   |
| No sound from piezo           | Incorrect pin or code         | Verify piezo connection and melody code.     |
| LEDs not lighting up          | Loose connection or wrong pin | Double-check LED and resistor wiring.         |

---

## 🎓 Next Steps
- Add more songs or custom lighting patterns.
- Experiment with different sensors or displays.
- Share your creations with the community!

---

## 📬 Need Help?
Open an issue on [GitHub](https://github.com/yourusername/ardify/issues).
