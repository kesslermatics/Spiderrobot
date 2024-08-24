# SpiderRobot

## Overview

SpiderRobot is a robotic project built with an Arduino and several servo motors to mimic the movement of a spider. The robot can perform actions such as standing, sitting, and winking, and it uses an ultrasonic sensor to measure the distance to objects in front of it. This project is a great introduction to working with servos, Arduino programming, and basic robotics.

## Components

- **1x Arduino Board**
- **12x Servo Motors**: Control the movement of the robot's legs.
- **1x Ultrasonic Sensor (HC-SR04)**: Measures distance to objects.
- **Jumper Wires and Breadboard**
- **External Power Supply**: Depending on the servos used, an external power source may be necessary.

## Pin Configuration

- **Trig Pin (Ultrasonic Sensor)**: A2
- **Echo Pin (Ultrasonic Sensor)**: A1
- **Servo Motor Pins**: Digital pins 2-13 are used to control the 12 servo motors.
  - **Servo Motor Layout**:
    - Motor 0: Pins 2, 3, 4
    - Motor 1: Pins 5, 6, 7
    - Motor 2: Pins 8, 9, 10
    - Motor 3: Pins 11, 12, 13

## Features

- **Stand**: Positions the robot in a standing posture using predefined servo angles.
- **Sit**: Lowers the robot into a sitting position by adjusting the servos.
- **Wink**: Performs a winking action with one of the legs, simulating a wink gesture.
- **Distance Measurement**: Uses an ultrasonic sensor to measure the distance to the nearest object and prints the value to the serial monitor.

## How It Works

1. **Setup**: The servos are initialized and attached to their respective pins, and the ultrasonic sensor is set up for distance measurement.
2. **Stand Function**: The robot adjusts its legs to a standing position.
3. **Distance Calculation**: The `calc_distance()` function triggers the ultrasonic sensor to measure the distance to an object in front of the robot.
4. **Wink Function**: The robot performs a winking action with one of its legs.
5. **Sit Function**: The robot lowers itself into a sitting position.
6. **Infinite Loop**: The robot halts further actions after completing the sequence.

## Installation and Setup

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/SpiderRobot.git
   cd SpiderRobot
   ```
2. **Upload the Code:**

  Open the SpiderRobot.ino file in the Arduino IDE.
  Connect your Arduino to your computer.
  Upload the code to the Arduino board.

3. **Wiring:**

  Connect the servo motors to the appropriate digital pins as specified in the pin configuration.
  Connect the ultrasonic sensor to pins A1 (Echo) and A2 (Trig).

4. **Power:**

  Ensure the servos are powered properly, either through the Arduino or with an external power supply.


## Usage

Once everything is set up and the code is uploaded:

The robot will start in a standing position.
It will measure the distance to an object and print the result to the serial monitor.
The robot will perform a winking action, followed by sitting down.
To see the distance measurements, open the serial monitor in the Arduino IDE at a baud rate of 9600.

## Customization

Servo Positions: Adjust the angles in the stand(), sit(), and wink() functions to modify the robot's movements.
Distance Thresholds: Add logic to perform different actions based on the distance measured by the ultrasonic sensor.

![Description of the GIF](demonstration.gif)
