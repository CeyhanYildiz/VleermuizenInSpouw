# Bat Detection in Cavity Walls
By Ceyhan Yildiz and Quinten Mathijs
## Project Structure (Overview)
- [Docs](https://github.com/CeyhanYildiz/VleermuizenInSpouw/tree/main/Docs)This folder contains datasheets
- [Firmware](https://github.com/CeyhanYildiz/VleermuizenInSpouw/tree/main/Firmware) This folder contains everything about the ESP and ESPHome
- [Media](https://github.com/CeyhanYildiz/VleermuizenInSpouw/tree/main/Media) This folder contains screenschots, setups, schematics etc.

## Overview
This project aims to develop a system that can **detect bats in cavity walls**.  
Bats frequently use cavity walls as habitats and migration corridors.  
By monitoring their activity, this project contributes both to **bat conservation** and to **building practices** that account for ecological concerns.

## Motivation
- **Ecological**: Support the protection of vulnerable bat species.  
- **Architectural**: Provide better guidelines for renovation and insulation projects while respecting bat habitats.  

## Objectives
The objective of this subproject is to deliver a functional, reproducible sensor node that:
- can measure temperature and relative humidity inside a cavity wall using an SHT30/SHT3X sensor;
- can operate autonomously on battery power, using deep sleep to save energy;
- logically connects each sensor to the ESP32-S2 via ESPHome;
- transmits the measured values via Wi-Fi to a central system (e.g. Home Assistant or a backend from BatSenseEmbedded);
- is sufficiently documented (hardware and firmware) so that another student can rebuild the node and integrate it into the BatSense system.

## Key Components
- **ESP32-S2 Mini**: microcontroller for sensor data collection and wireless communication.  
- **Raspberry Pi Pico**: supporting data acquisition.  
- **IR Camera**: thermal imaging of bat activity.  
- **Audio Recorder**: ultrasonic bat call detection (Apodemus Pippyg). 
- **Sensors**: temperature, humidity, and pressure monitoring (SHT30/SHT3X).

## Results
The following results were achieved with this sensor node:
- **Functional hardware module:**
The combination of the S2 Mini, PowerBoost 500 Charger, and SHT30/SHT3X results in a stable system that can be placed inside a cavity wall.
- **Stable environmental measurements:**
Temperature and humidity values are read out reliably via ESPHome.
- **Wi-Fi communication:**
The node connects to the configured Wi-Fi network and publishes the sensor values as entities.
- **Integration with a central system:**
The data can be read and logged by a higher-level platform (for example Home Assistant or a central server within BatSenseEmbedded).

The number of working modules, test duration, and stability tests depend on the specific measurements and setups carried out during the project. These can be supplemented with graphs, logs, and screenshots in the documentation and in the central project report.



