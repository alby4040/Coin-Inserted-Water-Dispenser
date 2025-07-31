# Coin-Inserted-Water-Dispenser
 practical and cost-effective system that provides clean drinking water in public areas through a coin-operated mechanism, powered by Arduino-based automation.

📌 Overview
This project presents an automated water dispensing system activated upon the insertion of a valid coin. It is designed for public utility in parks, campuses, and transit areas to promote sustainable access to water and reduce plastic bottle waste.

Users insert a coin, place their water bottle, and the system dispenses a measured amount of water based on the coin’s value.

🎯 Features
💰 Accepts multiple coin values (₹1, ₹2)

👋 IR sensor detects bottle placement

💧 Accurate water flow using flow sensor

🧠 Controlled by Arduino Uno

🔠 LCD displays user instructions

⚙️ Relay-controlled water pump

♻️ Encourages bottle reuse and eco-friendly hydration

🛠️ Components Used
Component	   Specification
Arduino Uno	 ATmega328P, 5V
Coin Sensor	 Multi-coin acceptor
IR Sensor	   LM393-based
Flow Sensor	 S201 or equivalent
Water Pump	 2.5–6V, 80–120 L/H
LCD Display	 16x2 with I2C
Power Supply 5V & 12V regulated

⚙️ Working Principle
Coin inserted → detected and validated by the coin sensor.

IR sensor checks for bottle presence.

On validation, LCD shows message and pump is activated.

Flow sensor monitors dispensed quantity.

Once the preset volume is reached, pump turns off automatically.


WORKING MODEL 


<img width="663" height="804" alt="Screenshot 2025-07-31 183028" src="https://github.com/user-attachments/assets/283dfb90-2e96-44f8-b825-92c61301c404" />

