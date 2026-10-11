# microblitz!
microblitz is a custom PCB designed for an autonomous maze-solving robot inspired by the Micromouse competition, where robots navigate a maze and find the fastest path from start to finish.

The board integrates a microcontroller, distance sensors, and motor drivers.

Features
- Microcontroller: Teensy 4.0
- Distance sensing: 3–5 time-of-flight (ToF) sensors
- Motor control: Two DRV8212PDSGR motor drivers
- Power management: Reverse-polarity protection, buck conversion, and LDO voltage regulation

## Hardware Design
Microcontroller and Sensor Interface
The board uses a Teensy 4.0 as its main microcontroller. It interfaces with multiple time-of-flight sensors to measure distances to nearby walls and obstacles.

The robot uses VL53L4CD time-of-flight sensors from Pololu to detect its surroundings.

Motor Control
- Two DRV8212PDSGR motor drivers control the robot's left and right motors.

Power Management
- Reverse-polarity protection to help protect the circuit from incorrect power connections.
- Buck conversion (5V) to efficiently step down the input voltage.
- LDO regulation (3.3V) to provide a stable supply voltage for sensitive logic circuitry.

Navigation and Pathfinding
- microblitz is designed to map its surroundings and navigate a maze autonomously.
- The robot stores information about the maze in an array, and a pathfinding algorithm then uses this map to determine a route from the starting point to the destination, with the goal of finding the fastest path possible.

<img height="300" alt="image" src="https://github.com/user-attachments/assets/7aa2b549-a22a-4a0b-917f-95ba229ee678" /><img height="300" alt="image" src="https://github.com/user-attachments/assets/29e9de0a-f99d-4ac3-a39c-64b789801bcc" />

