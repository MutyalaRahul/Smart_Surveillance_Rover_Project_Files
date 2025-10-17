Smart Surveillance Rover Using MSP430G2553 and Arduino UNO

Overview:
An autonomous rover that avoids obstacles using MSP430G2553 (main controller)
and Arduino UNO (secondary controller) with L298N motor driver and HC-SR04.

Core Components:
- MSP430G2553: Main control logic, PWM generation
- Arduino UNO: Secondary MCU for monitoring and expansion
- L298N: Motor driver for direction and speed
- HC-SR04: Ultrasonic distance measurement
- 12V DC Motors (x2): Movement
- Power Supply: 12V motor + 9V logic
- Switch, Chassis, Caster Wheel, Jumper Wires

Connection Summary:
MSP430 → L298N
P1.6 → IN1
P1.7 → IN2
P2.0 → IN3
P2.1 → IN4
3.3V → ENA, ENB (PWM)

MSP430 → HC-SR04
P1.4 → TRIG
P1.5 → ECHO

MSP430 ↔ Arduino
P1.1 ↔ D0 (RX)
P1.2 ↔ D1 (TX)
GND ↔ GND

Power Setup:
- 12V to L298N (motor power)
- 9V to Arduino VIN & MSP430 regulator
- Common Ground for all components

Specifications:
MSP430 Voltage: 3.3V
Arduino Voltage: 5V
Motor Driver Input: 7V–35V
Motor Voltage: 12V
PWM Frequency: 5–10kHz
Duty Cycle: 40–90%

Working:
1. MSP430 triggers HC-SR04 and measures distance.
2. MSP430 controls L298N for movement logic.
3. Arduino receives telemetry or alerts and logs data.
4. Robot navigates autonomously avoiding obstacles.
