# Embedded-Autonomous-Fire-Suppression-System-using-Sensor-Based-Navigation
An autonomous fire-fighting robot designed to detect and extinguish small-scale fires using flame sensors and a water pump mechanism. The system is built using Arduino Uno, L298N motor driver, BO motors, and infrared flame sensors. <br>

## Project Overview
Fire accidents in laboratories, offices, and small indoor environments can cause serious damage. This robot detects flames using three IR flame sensors (Left, Front, Right), navigates toward the fire source, and activates a water pump controlled by a servo motor to extinguish it autonomously. <br>
This project demonstrates practical implementation of embedded systems, motor control, and sensor-based automation.<br>

## Hardware Components
- Arduino Uno
- L298N (Dual H-Bridge)
- 3x Flame Sensors (Digital Output)
- 4x BO Motors
- Servo Motor
- 5V/6V Water Pump
- 18650 Li-ion Batteries (7.4V)
- 4x AA Batteries (6V)

## Working Principle
1.) Flame sensors continuously monitor for fire.
2.) If: 
   - Front sensor detects fire → Robot moves forward.
   - Left sensor detects fire → Robot turns left.
   - Right sensor detects fire → Robot turns right. 

3.) Once near the fire:
  - Robot stops.
  - Servo motor sweeps the nozzle.
  - Water pump activates to extinguish fire.

4.) Robot stops after suppression.

## How to Run
1.) Install Arduino IDE (v1.8.19 or above)
2.) Open fire_fighting_robot.ino
3.) Select board: Arduino Uno
4.) Upload code
5.) Power the robot

## Features
- Autonomous fire detection
- Direction-based navigation
- Servo-controlled water spraying
- Low-cost implementation
- Battery-powered portable system

## Limitations
- No obstacle avoidance
- Limited detection range (~1 meter)
= Limited water capacity
- Battery dependent

## Future Improvements
- Add Ultrasonic Sensor for obstacle avoidance
- Add Bluetooth/WiFi remote monitoring
- Add temperature sensor
- Increase water tank capacity
- Use ESP32 instead of Arduino

