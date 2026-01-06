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

# Flashing the S2 Mini with ESPHome

## Overview
In this part of the project, we configured and flashed the S2 Mini using ESPHome.
The goal was to correctly program the microcontroller so that it could read the SHT3X sensor and transmit the data via Wi-Fi.
During this process, we received support from my junior colleague Alexander Petry, who assisted with creating the required configuration files and carrying out the flashing process.

## Installing ESPHome
To get started, ESPHome had to be installed locally on the computer.
This was done via the Command Prompt (CMD) or PowerShell using the following command:

```bash
pip install esphome
```

After installation, it was verified that ESPHome was installed correctly by checking the version number:

```bash
esphome version
```

When the version was displayed correctly, the installation was successful and the flashing of the S2 Mini could begin.

## Flashing the S2 Mini
The S2 Mini was connected to the computer via USB.
Next, the YAML configuration file was executed and flashed to the board using the command below:

```bash
esphome run .\HTSensor.yaml
```

During this step, the firmware was automatically generated, compiled, and uploaded to the S2 Mini.
After successful flashing, the microcontroller could immediately be tested using ESPHome’s **log function**:

```bash
esphome logs .\HTSensor.yaml
```

These logs allowed us to verify whether the sensor was successfully transmitting data and whether the Wi-Fi connection was established.

## YAML Configuration File
Together with Alexander, the following **YAML-file** was created for the S2 Mini.
The file contains the configuration for the Wi-Fi connection, the sensor, logging, and the automatic deep-sleep functionality to save energy.

```yaml
esphome:
  name: envsensor17 #box number
  friendly_name: envsensor17
  on_boot:
    priority: -10
    then:
      - delay: 15s  #  give Wi-Fi and sensor time to initialize before sleep
      - deep_sleep.enter: deep_sleep_ctrl

esp32:
  board: lolin_s2_mini
  framework:
    type: arduino

logger:

api:
  password: "1"

ota:
  - platform: esphome
    password: "1"

wifi:
  ssid: "batSenseWifi"
  password: "batSenseWifi123-_-"
  fast_connect: true   # speeds up reconnection for fixed Wi-Fi networks

captive_portal:

i2c:
  sda: 33
  scl: 35
  scan: true

sensor:
  - platform: sht3xd
    temperature:
      name: "envsensor17 Temperature"
    humidity:
      name: "envsensor17 Humidity"
    address: 0x44
    update_interval: 10s

deep_sleep:
  id: deep_sleep_ctrl
  sleep_duration: 5min
```

## Observations
- The flashing process went smoothly and without errors.
- After startup of the S2 Mini, temperature and humidity values were read correctly.
- The deep-sleep functionality worked as expected, which is essential for energy efficiency during long-term field use.
- The Wi-Fi connection to the batSenseWifi network was established reliably and remained stable during the test period.

## Result
- The S2 Mini was successfully flashed with a fully functional ESPHome configuration.
- The sensor communicates reliably via I²C and Wi-Fi.
- This configuration will serve as the base firmware for the further rollout of environmental sensors within the project.
