#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h> 

LiquidCrystal_I2C lcd(0x27, 16, 2);
RTC_DS3231 rtc;
Servo servo;

const int irSensorPin = 2;
const int feedButtonPin = 3;
const int sqwPin = 4; 
const int portionSize = 5; 
int feedCount = 0;
int remainingFood = 100; 

void setup() 
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  servo.attach(9);
  pinMode(irSensorPin, INPUT);
  pinMode(feedButtonPin, INPUT_PULLUP);
  pinMode(sqwPin, INPUT_PULLUP); 

  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, setting the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  rtc.writeSqwPinMode(DS3231_SquareWave1Hz);

  lcd.setCursor(0, 0);
  lcd.print("Feed count: 0");
  lcd.setCursor(0, 1);
  lcd.print("Food Left: 100");
}

void loop() 
{
  DateTime now = rtc.now();
  static uint32_t lastTimeUpdate = 0;
  if (millis() - lastTimeUpdate >= 1000) {
    lastTimeUpdate = millis();
    lcd.setCursor(0, 0);
    lcd.print("Time: ");
    lcd.print(now.hour(), DEC);
    lcd.print(':');
    lcd.print(now.minute(), DEC);
    lcd.print(':');
    lcd.print(now.second(), DEC);
  }

  if (digitalRead(irSensorPin) == HIGH) {
    dispenseFood();
  }
  if (digitalRead(feedButtonPin) == LOW) {
    dispenseFood();
    delay(1000); 
  }
  if (digitalRead(sqwPin) == LOW) {
    // Perform actions based on SQW signal. I have not used this 
  }

  lcd.setCursor(0, 1);
  lcd.print("Food Left: ");
  lcd.print(remainingFood);
}

void dispenseFood()
{
  if (remainingFood > 0) 
  {
    for (int pos = 0; pos <= 90; pos += 1) { 
      servo.write(pos); 
      delay(20); 
    }
    delay(portionSize * 1000); 
    for (int pos = 90; pos >= 0; pos -= 1) { 
      servo.write(pos); 
      delay(20); 
    }
    feedCount++;
    remainingFood--;
    lcd.setCursor(11, 0);
    lcd.print(feedCount);
  } 
  else
  {
    lcd.setCursor(0, 1);
    lcd.print("Out of Food!");
  }
}