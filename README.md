# Obstacle Avoidance Robot with Ultrasonic Sensor

## Description
This project is an **Arduino-based obstacle avoidance robot** that uses an **ultrasonic sensor** to detect obstacles and adjust its movement accordingly. A **servo motor** is used to scan the environment and make decisions about the best path forward.

## Components Used
- **Arduino Board**
- **Servo Motor (SM)**
- **Ultrasonic Sensor (HC-SR04)**
- **Motor Driver**
- **Two DC Motors**
- **Wheels**
- **Power Supply**

## Wiring Connections
| Component | Pin | Description |
|-----------|-----|-------------|
| Left Motor | LA: 7, LB: 8 | Controls left motor movement |
| Right Motor | RA: 10, RB: 11 | Controls right motor movement |
| Motor Speed | ENA: 6, ENB: 5 | PWM speed control |
| Ultrasonic Sensor | Trig: 2, Echo: 4 | Measures distance |
| Servo Motor | Pin 9 | Controls scanning angle |

## Features
- **Obstacle Detection:** Uses an ultrasonic sensor to measure the distance to obstacles.
- **Autonomous Navigation:** Moves forward if no obstacle is detected, otherwise makes a decision.
- **Servo Scanning:** Rotates left and right to determine the best path.
- **Directional Movement:** Moves forward, backward, left, or right based on the environment.
