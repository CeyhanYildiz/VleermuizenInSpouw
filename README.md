# Bat Detection in Cavity Walls

## Overview
This project aims to develop a system that can **detect bats in cavity walls**.  
Bats frequently use cavity walls as habitats and migration corridors.  
By monitoring their activity, this project contributes both to **bat conservation** and to **building practices** that account for ecological concerns.

## Motivation
- **Ecological**: Support the protection of vulnerable bat species.  
- **Architectural**: Provide better guidelines for renovation and insulation projects while respecting bat habitats.  

## Objectives

### Must-Haves
- Build and deliver functional hardware modules.  
- Document the project in an **Application Note**.  
- Maintain clear project documentation in this repository (README, source code, setup instructions).  
- Conduct code reviews via GitHub.  

### Nice-to-Haves
- Design and produce a custom PCB.  

## System Approach
The detection system combines **thermal imaging, acoustic monitoring, and environmental sensors** to map how bats use cavity walls and to identify influencing factors.

### Key Components
- **ESP32-S2 Mini**: microcontroller for sensor data collection and wireless communication.  
- **Raspberry Pi Pico**: supporting data acquisition.  
- **IR Camera**: thermal imaging of bat activity.  
- **Audio Recorder**: ultrasonic bat call detection.  
- **Sensors**: temperature, humidity, and pressure monitoring.  
- **Wireless & SD storage**: data backup and redundancy.  

## Development Process
1. Analyze current issues (battery limitations, condensation, wireless reliability).  
2. Work in teams of 2–3 students.  
3. Prototype and test sensor modules.  
4. Improve iteratively based on test results and feedback.  

## Deliverables
- Functional hardware modules.  
- Application Note (system design, operation, limitations).  
- GitHub repository including:  
  - Source code  
  - README documentation  
  - Setup instructions  
- Optional: PCB design.  

## Firmware / Web Server
The ESP32-S2 Mini reads temperature and humidity from an **SHT3x sensor** and serves the data via a simple web interface.

### Features
- Connects to Wi-Fi (SSID: `YourWIFI`, Password: `PASSWORD`)  
- Reads temperature and humidity via I²C (SDA: 33, SCL: 35)  
- Hosts a web server on port 80  
- Displays sensor readings in real-time on a web page  
- Prints readings to Serial Monitor for debugging  
- Shows assigned IP address for easy access  

### Code
The full Arduino firmware can be found here:  
[ESP32-S2 Mini SHT3x Web Server Firmware](./firmware/ESP32_S2_Mini/ESP32_S2_Mini.ino)

### Usage
1. Connect the SHT3x sensor to the ESP32-S2 Mini (SDA → 33, SCL → 35).  
2. Upload the firmware to the board using Arduino IDE.  
3. Open Serial Monitor at **115200 baud** to see Wi-Fi connection progress, IP address, and sensor readings.  
4. Access the ESP32 web server in a browser using the displayed IP address.  

### Notes
- If the SHT3x sensor is not detected, try I²C address `0x45`.  
- Ensure the iPhone hotspot is active and allows new connections.  
- This interface provides a simple way to monitor environmental conditions inside cavity walls in real-time.  

## Getting Started
### Requirements
- ESP32-S2 Mini development board  
- Raspberry Pi Pico (optional for extended acquisition)  
- IR camera module (for thermal detection)  
- Audio recording module (ultrasonic bat calls)  
- SHT3x or other environmental sensors  
- SD card module or wireless data storage option  
