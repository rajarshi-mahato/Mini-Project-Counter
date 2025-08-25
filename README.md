# Mini Project – Counter
# Description
A simple project to display digits (0–9) with the ability to up-count and down-count between numbers.
The digits are controlled remotely using the Blynk App (via smartphone or desktop).

# 📌  Features
1. Display any digit (0–9) of your choice.
2. Increment (Up-count) or decrement (Down-count) digits.
3. Remote control through the Blynk IoT app.
4. Compact hardware setup using ESP32 and servo-driven display.

# 🛠️ Components Used
1. ESP32 (microcontroller + Wi-Fi)
2. 16-channel PWM Servo Shield
3. 7 Servo Motors (to form digits 0–9)
4. Power Supply
5. Buck Converter

# ⚡ Working Principle

The ESP32 communicates with the Blynk App, receiving commands for digit display and counting.
Servo motors are arranged to form segments of a digital number.
According to the command, servos adjust their position to represent the desired digit (0–9).
The counter can increase or decrease the displayed number seamlessly.

# 📱 Control via Blynk
Install the Blynk IoT App (Android/iOS or Desktop).
Connect the project to your Blynk account via Wi-Fi.
Use app buttons/sliders to send commands for:
1. Set digit
2. Count up
3. Count down

# 🚀 Future Improvements
1. Add multi-digit display (e.g., 2-digit or 3-digit counters).
