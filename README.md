# Steel Worker Safety Kit

## Overview
The **Steel Worker Safety Kit** is an IoT-based safety solution designed to monitor environmental conditions such as temperature, gas levels, and sound levels in industrial workplaces. It provides real-time alerts and a web interface for data visualization to enhance worker safety.

---

## Features
- **Real-Time Monitoring:** Tracks temperature, gas, and sound levels using DHT22, MQ2, and sound sensors.
- **Alert System:** Blinking LEDs indicate hazards when thresholds are exceeded.
- **Web Dashboard:** Responsive UI for live data visualization and hazard alerts.
- **Wi-Fi Enabled:** Connects via ESP32 to deliver updates on a local web server.

---

## Components
1. **ESP32 Microcontroller**
2. **DHT22 Sensor** - Temperature monitoring
3. **MQ2 Gas Sensor** - Gas detection
4. **Sound Sensor** - Noise level detection
5. **LED Indicators** - Visual hazard alerts

---

## Setup Instructions
1. Clone the repository and upload the code to the ESP32 using Arduino IDE.
2. Connect the sensors and LEDs as per the pin configuration in the code.
3. Power the ESP32 and connect to your Wi-Fi network (update `ssid` and `password` in the code).
4. Access the web dashboard via the ESP32's IP address displayed in the Serial Monitor.

---

## Usage
- Monitor live data on the web interface.
- Observe hazard alerts (heat, gas, or sound) through blinking LEDs and dashboard notifications.

---

## Thresholds (Customizable)
- **Temperature:** >32.7°C
- **Gas Level:** >380 PPM
- **Sound Level:** >1850 Hz

---

## License
This project is open-source and can be customized or extended as needed.

---

Ensure safe operations by using the **Steel Worker Safety Kit** in industrial environments!
