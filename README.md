# 🌿 AutoIrrigator

**AutoIrrigator** is a customizable, Arduino-powered irrigation system designed to automate plant watering based on user-defined intervals and durations. Whether you're growing herbs on a windowsill or managing a small garden, this DIY solution helps ensure consistent hydration with minimal effort and maximum control.

---

## 🛠️ Project Overview

This project combines hardware simplicity with functional flexibility. Using two potentiometers, users can set:
- **Watering Interval** – how often the plants should be watered.
- **Watering Duration** – how long each watering session should last.

The system uses a relay to control a solenoid valve, which regulates water flow. All components are housed in a **custom-designed 3D-printed casing**, offering both protection and aesthetic appeal.

---

## 🔩 Hardware Components

- **Arduino Uno/Nano** – Microcontroller for timing and control logic.
- **2 Potentiometers** –  
  - One for setting the interval between watering cycles.  
  - One for setting the duration of each watering session.
- **Relay Module** – Safely switches the solenoid valve on and off.
- **Solenoid Valve** – Controls the flow of water to the plants.
- **3D-Printed Casing** – Designed and printed by the creator to house all components securely and neatly.
- **5V power supply** – To power the Arduino and the relay.
- **12V power supply** – To power the solenoid valve.

---
## 🔩 Circuit Diagram

![wiring diagram](https://github.com/thecrazyphysicist369/automatic-irrigator/blob/main/circuit.png)
---

## ⚙️ Features

- Fully adjustable watering schedule via physical knobs.
- Simple analog interface—no need for apps, Wi-Fi, or cloud services.
- Compact and durable enclosure suitable for indoor or outdoor use.
- Easily extendable for additional sensors (e.g., soil moisture) or multiple watering zones.

---

## 📁 Repository Contents

- `AutoIrrigator.ino` – Arduino sketch for controlling the system.
- `wiring_diagram.png` – Visual guide for hardware connections.
- `casing_design.stl` – STL file for 3D printing the enclosure.
- `setup_instructions.md` – Step-by-step guide to assemble and configure the system.
- `components_list.md` – Detailed list of required parts and links to purchase.

---

## 🌱 Applications

- Home gardening automation
- Maker and hobbyist projects
- STEM education and classroom demos
- Low-cost irrigation for remote or off-grid setups

---

## 📷 Gallery

![Printed case top](https://github.com/thecrazyphysicist369/automatic-irrigator/blob/main/IMG_8554.jpg)

---

## 🤝 Contributing

Feel free to fork the repo, suggest improvements, or add features like moisture sensors, LCD displays, or IoT integration.

---

## 📜 License

This project is open-source under the MIT License. See `LICENSE` for details.

---

