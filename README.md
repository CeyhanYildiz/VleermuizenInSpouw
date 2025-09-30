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
- **ESP32**: microcontroller for data collection and wireless communication.  
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

## Getting Started
### Requirements
- ESP32 development board  
- Raspberry Pi Pico  
- IR camera module  
- Audio recording module  
- Environmental sensors (temperature, humidity, pressure)  
- SD card module or wireless data storage option  
