---

# Firmware / Web Server  
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

<img width="1405" height="592" alt="image" src="https://github.com/user-attachments/assets/f73642c5-87ae-47f3-b6f9-bfc8f7a8d6d1" />

### Notes
- If the SHT3x sensor is not detected, try I²C address `0x45`.  
- Ensure the iPhone hotspot is active and allows new connections.  
- This interface provides a simple way to monitor environmental conditions inside cavity walls in real-time.  

---

# ESPHome Configuration (Alternative Firmware Option)

As an alternative to the Arduino firmware, this project also supports **ESPHome**, which offers automatic Wi-Fi setup, deep sleep, OTA updates, and seamless integration with Home Assistant.

This configuration is ideal for **low-power long-term monitoring** in cavity walls.

## File Structure
```

projectfolder/
├── base.yaml        # Base configuration (Wi-Fi, sensor, deep sleep, board setup)
└── device1.yaml     # Device-specific config (name + include)

````

### base.yaml
Contains:
- ESP32-S2 Mini board settings  
- Wi-Fi configuration  
- SHT3x sensor (I²C: SDA 33, SCL 35)  
- ESPHome API, Logger, OTA  
- Deep sleep controller  

### device1.yaml
```yaml
substitutions:
  devicename: envsensor1

<<: !include base.yaml
````

---

## Setting Up ESPHome

### 1️⃣ Configure Wi-Fi (Important)

Before flashing, open **base.yaml** and update:

```yaml
wifi:
  ssid: "JOUW_WIFI_NAAM"
  password: "JOUW_WIFI_WACHTWOORD"
  fast_connect: true
```

⚠️ **The ESP will not connect without valid Wi-Fi credentials.**

---

## Flashing Options

### Option A — ESPHome Web Flasher (Recommended)

1. Go to [https://web.esphome.io](https://web.esphome.io)
2. Click **Connect**
3. Select the ESP32-S2 Mini port
4. Click **Install**
5. Upload `device1.yaml`

---

### Option B — ESPHome in Home Assistant

1. Open **ESPHome**
2. Click **New Device**
3. Select **Upload YAML**
4. Choose `device1.yaml`
5. Install → Select serial port

---

### Option C — ESPHome CLI

```bash
esphome run device1.yaml
```

ESPHome compiles and automatically asks for the serial port.

---

## Behavior of This ESPHome Firmware

* Reads temperature & humidity from SHT3x (address 0x44)
* Logs measurements to ESPHome / Home Assistant
* Waits 15 seconds → enters deep sleep
* Wakes every 1 minute for a new measurement
* Supports OTA updates
* Extremely low-power, suitable for long-term deployments

---

## Troubleshooting

* Sensor not detected → try address `0x45`
* Ensure SDA = 33, SCL = 35
* Try a shorter I²C cable

---

## Getting Started

### Requirements

* ESP32-S2 Mini development board
* Raspberry Pi Pico (optional for extended acquisition)
* IR camera module (thermal detection)
* Audio recording module (ultrasonic bat calls)
* SHT3x or similar environmental sensors
* SD card module or wireless data storage option

---
