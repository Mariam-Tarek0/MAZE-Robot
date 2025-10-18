# MAZE-ROBOT

This project presents a mobile-controlled robot designed to navigate through a maze using manual control via a smartphone.  
The robot can move in all directions, allowing the user to guide it through the maze efficiently while avoiding obstacles.

## Hardware Requirements

-  **Robotic car kit.**
-  **Arduino NANO.**
-  **Motor Driver L298n.**
-  **2 DC Motors.**
-  **Caster wheel.**
-  **Power Supply.**
-  **3 Ultrasonic Sensors.**
-  **Connecting Wiers.**

## Features
- Controlled wirelessly using a mobile app (Bluetooth or Wi-Fi)  
- Forward, backward, left, and right motion control  
- Capable of navigating maze paths through manual control  
- Compact and lightweight design  
- Optional obstacle detection for collision avoidance  

## Working Principle
1. The robot pairs with a smartphone via Bluetooth/Wi-Fi.  
2. When the user presses a button on the app, a command is sent to the microcontroller.  
3. The microcontroller controls the motor driver to move the robot accordingly.  
4. The user manually guides the robot through the maze until reaching the exit.

## Software Requirements

-  **Arduino IDE.**
-  **Any additional libraries or dependencies specified in the code.**
