# Smart-ICU-Patient-Monitor
Smart ICU Patient Monitoring Pole – AI &amp; IoT-based real-time patient monitoring system for ICUs. This project simulates heart rate, body temperature, and oxygen level readings using Arduino/ESP32 sensors and displays live data on a web dashboard built with Python Flask. Ideal for low-cost, scalable ICU monitoring solutions.
# Smart ICU Patient Monitoring Pole

## Overview
This project simulates a Smart ICU Patient Monitoring Pole using IoT sensors and a real-time dashboard.  
The Arduino/ESP32 sends heart rate, temperature, and oxygen data to a Flask web dashboard.

## Setup

### Arduino/ESP32
1. Open `Arduino_Code/patient_monitor.ino`.
2. Enter your WiFi credentials.
3. Update `serverName` with your PC's local IP where Flask runs.
4. Upload code to your ESP32/Arduino.

### Dashboard
1. Install dependencies: `pip install flask`
2. Run: `python app.py`
3. Open `http://localhost:5000` in your browser to view data.

## Demo
Simulated sensor data updates every 5 seconds on the dashboard.

