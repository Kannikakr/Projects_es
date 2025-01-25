# Embedded system projects 

# Project 1 : Automated Pest and irrigation system

### objective:
The objective of this project is to develop an automated system using Arduino to
manage irrigation and pest control in agricultural settings. The system intelligently
adjusts water usage and pesticide application based on real-time data from soil
moisture levels, environmental conditions (temperature and humidity), and pest activity.
The primary goals are to optimize water resources, minimize pesticide use, ensure
healthy crop growth, and promote environmental sustainability.

### Overview:
The automated agricultural system is designed to monitor environmental conditions and
soil moisture in real time, and it takes action to irrigate the crops or apply pesticides
based on sensor data. The system employs various sensors and actuators controlled by
an Arduino microcontroller. A Liquid Crystal Display (LCD) provides real-time feedback,
and alerts are triggered when specific conditions are met.

### Components Used:
1. Arduino Microcontroller
2. Moisture Sensor (using a Potentiometer)
3. DHT Sensor (DHT11)
4. PIR Sensor
5. LDR (Light-Dependent Resistor)
6. Servo Motor
7. RTC Module (DS3231)
8. LCD Display (I2C)
9. LED and Buzzer.

### Materials and Methods:

● Microcontroller: Arduino Uno

● Sensors: DHT11 for temperature and humidity, potentiometer for soil moisture,
PIR sensor for motion detection, and LDR for light detection.

● Actuators: Servo motor for controlling irrigation, LED and buzzer for alerts.

● Modules: RTC (DS3231) for timekeeping, LCD (I2C) for real-time data display.

### Working of Each Sensor:
1. <b>Moisture Sensor (Using Potentiometer)</b>:

    ● Objective: Measure the moisture level in the soil.

    ● Working:

    ○ A potentiometer is used to sense the soil moisture level by detecting theresistance between two probes inserted into the soil. The moisture content affects the resistance, which in turn affects the voltage output of the potentiometer.

    ○ The Arduino reads this voltage as an analog signal and converts it into a moisture value. If the moisture level falls below a certain threshold, the
system activates the irrigation system (via a servo motor) and triggers an
alert (LED and buzzer).

2. <b>DHT Sensor (DHT11)</b>:

   ● Objective: Measure the temperature and humidity of the environment.

   ● Working:

   ○ The DHT11 sensor reads the temperature and humidity from the
surrounding environment using a thermistor and a capacitive humidity
sensor.

    ○ The sensor outputs the temperature and humidity data to the Arduino,
which then determines if environmental conditions are within acceptable
ranges. If temperature or humidity levels drop below set thresholds, the
system can trigger the irrigation system.

3. <b>PIR Sensor</b>:

   ● Objective: Detect motion in the vicinity, such as the movement of pests.

   ● Working:

   ○ The PIR (Passive Infrared) sensor detects infrared radiation from moving
objects like pests.

   ○ When a pest moves within the sensor's range, the PIR outputs a HIGH
signal to the Arduino, indicating the presence of a pest. This signal can be
used to trigger pest control mechanisms or raise an alert.

4. <b>LDR (Light-Dependent Resistor)</b>:

   ● Objective: Detect the presence of larger pests based on changes in light
intensity.

   ● Working:

   ○ The LDR sensor measures the ambient light level. If a large pest blocks
the light, the resistance of the LDR changes, which causes a drop in the
voltage read by the Arduino.

   ○ A significant drop in light intensity (below a certain threshold) indicates the
presence of a pest, which can trigger pest control mechanisms or alerts.

5.<b> RTC Module (DS3231)</b>:

    ● Objective: Keep track of the current time for scheduling purposes.

    ● Working:

    ○ The RTC (Real-Time Clock) module provides accurate timekeeping,allowing the system to perform time-based operations such as scheduled irrigation or pesticide application.

    ○ The Arduino reads the current time from the RTC module and displays it on the LCD, along with sensor data.

### System Operations:
1. <b>Moisture and Environmental Monitoring</b>:

   ○ The system continuously monitors the soil moisture using the
potentiometer and the environmental conditions (temperature and
humidity) using the DHT11 sensor.

   ○ If the soil moisture level is below the threshold, or if the
temperature/humidity levels fall outside the desired range, the system
activates the servo motor to start irrigation. Simultaneously, the LED and
buzzer provide visual and audible alerts.

2.<b>Pest Detection</b>:

    ○ The system uses the PIR sensor and LDR to detect the presence of pests.The PIR sensor detects motion, while the LDR detects large pests basedon light intensity changes.

    ○ If pests are detected, the system displays a warning on the LCD. This could be expanded to trigger pest control mechanisms, such as activating a pesticide sprayer via the servo motor.

3.<b> Real-Time Display</b>:

    ○ The LCD provides real-time feedback, showing temperature, humidity, moisture levels, pest detection status, and the current time from the RTCmodule. This information helps users monitor the system and make informed decisions.

![Image](https://github.com/user-attachments/assets/7c12e78d-112d-457a-be45-b21d7f7df1c6)

# Projects : Smart Pet Feeder

### Objective : 
The project aims to create an automated pet feeder using Arduino, integrating a servo motor for
dispensing food, an IR sensor for detecting the presence of the pet, a push button for manual
feeding, and an RTC module to control feeding times accurately. The system also includes an
LCD display for real-time feedback.

### Components Used : 

1. Arduino Board: Central controller for the system.
2. LiquidCrystal_I2C: 16x2 LCD for displaying time and feeding status.
3. RTC Module (DS3231): Real-Time Clock to keep track of time and manage scheduled
feeding.
4. Servo Motor: Mechanism to dispense food.
5. IR Sensor: Detects the presence of the pet.
6. Push Button: Allows manual feeding.
7. Various Wires : For connections.

### Circuit Diagram Connections:

1. LCD (I2C):

   ○ VCC to 5V \
   ○ GND to GND \
   ○ SDA to A4 \
   ○ SCL to A5 
2. RTC (DS3231): 

   ○ VCC to 5V \
   ○ GND to GND \
   ○ SDA to A4 \
   ○ SCL to A5 \
   ○ SQW to Digital Pin 4 (optional, for time-based actions)

3. Servo Motor: 

   ○ Signal to Pin 9 \
   ○ VCC to 5V \
   ○ GND to GND 

4. IR Sensor: 

   ○ Signal to Pin 2 \
   ○ VCC to 5V \
   ○ GND to GND

### Working :
This Arduino sketch controls a food dispensing system using an LCD, a real-time clock (RTC),
an infrared (IR) sensor, a button, and a servo motor. Here’s a breakdown:

1. Libraries and Initialization:

   ○ Includes libraries for I2C LCD, Servo, and RTC. \
   ○ Initializes LCD at address 0x27, RTC, and Servo.
2. Pin Definitions:

   ○ irSensorPin: Detects presence to trigger feeding. \
   ○ feedButtonPin: Manual feed button. \
   ○ sqwPin: Square Wave pin for RTC.
3. Setup Function:

   ○ Initializes serial communication and LCD. \
   ○ Configures pins and attaches the servo. \
   ○ Checks RTC functionality and sets the time if needed. \
   ○ Displays initial feed count and food amount on the LCD.
4. Loop Function:

   ○ Updates the LCD with the current time from RTC every second.\
   ○ Check IR sensor and button to trigger food dispensing. \
   ○ Displays remaining food on LCD.
5. Dispense Food Function:

   ○ Operates the servo to dispense food. \
   ○ Increases feed count and decreases food amount. \
   ○ If food is exhausted, display "Out of Food!" on the LCD. 
   
### Conclusion :
Arduino-based food dispensing systems effectively integrate a real-time clock, LCD display, IR
sensor, button, and servo motor to automate and manage feeding. The system tracks and
displays the current time, monitors food levels, and responds to user inputs to dispense food. By
using an IR sensor and a manual button, it provides flexible feeding options, while the LCD
screen keeps users informed about the feed count and remaining food. The RTC ensures
accurate timekeeping for any time-based functions. Overall, this setup offers a practical solution
for automated feeding with real-time monitoring and user interaction.