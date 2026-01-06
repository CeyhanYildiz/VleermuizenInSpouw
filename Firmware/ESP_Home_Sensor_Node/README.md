# ESPHome Sensor Node – Usage and Flashing

This section explains how the ESPHome configuration for the sensor node works
and how to flash the firmware onto the S2 Mini (ESP32-S2) within this project.

---

## 1.What does this ESPHome configuration do?

The ESPHome configuration for this node ensures that the S2 Mini:

- connects to Wi-Fi;
- reads the SHT30/SHT3X sensor via I²C;
- exposes temperature and relative humidity as entities;
- (optionally) uses deep sleep to save battery power;
- supports OTA updates and logging via ESPHome.

The main configuration is located in:

- `Firmware/ESP_Home_Sensor_Node/device(NMR).yaml`

---

## 2. Files and structure

In this repository:

- `VleermuizenInSpouw/Firmware`
  - Step-by-step explanation on how to flash the S2 Mini (background information and screenshots).
  - ESPHome configuration for the S2 Mini:
    - board type (esp32-s2 / S2 Mini)
    - Wi-Fi settings
    - SHT30/SHT3X sensor (I²C)
    - logger, API, OTA, deep sleep (if configured)


---

## 3. Preparation

1. **Required hardware**
   - S2 Mini (ESP32-S2)
   - SHT30/SHT3X-sensor
   - Wi-Fi network (SSID + password)

2. **Software**
   - Python + `pip`
   - Install ESPHome:
     ```
     pip install esphome
     ```
   - Optional: ESPHome Dashboard (via Home Assistant or standalone)

---

## 4. Configuring Wi-Fi and sensor settings


- **Configuring Wi-Fi and sensor settings**:
wifi:
ssid: "JOUW_SSID"
password: "JOUW_WACHTWOORD"

- **Sensor configuration** (example):
i2c:
sda: <GPIO_SDA>
scl: <GPIO_SCL>
scan: true

sensor:
- platform: sht3xd
temperature:
name: "Spouwmuur Temperature"
humidity:
name: "Spouwmuur Humidity"
address: 0x44
update_interval: 10s


Only adjust what differs in your setup (SSID, password, pins, names).

---

## 5. First-time flashing (via USB)

1. Connect the S2 Mini to your PC via USB.
2. In a terminal, navigate to the project directory:
3. Flash the node using ESPHome
4. Select the correct serial port when ESPHome prompts you.

ESPHome:
- compile the firmware;
- upload it to the S2 Mini.

---

## 6. Viewing logs and testing

After flashing, you can view live logs:en:

esphome logs Sensor.yaml

Verify that:
- the node connects to your Wi-Fi network;
- the SHT30/SHT3X sensor provides values;
- (if configured) deep sleep works correctly (the node goes to sleep and wakes up again).

---

## 7. OTA-updates (wireless)

After the initial USB flash, you can upload changes to `Sensor.yaml`wirelessly:

esphome run Sensor.yaml

ESPHome will detect the node on your network and perform an OTA update.

---

## 8. Integration into the BatSense system

The sensors defined in Sensor.yaml (e.g. Cavity Wall Temperature,
Cavity Wall Humidity) appear as entities in ESPHome / Home Assistant
or can be read by the central BatSense components according to the
architecture agreed upon in the team project.

---

## 9. Common issues

- **Node does not appear on Wi-Fi**  
  → Check the SSID and password in Sensor.yaml.
- **No sensor values**  
  → Check the I²C pins and wiring. 
- **No logs**  
  → heck the serial port or network connection, then try again:
    ```
    esphome logs Sensor.yaml
    ```
