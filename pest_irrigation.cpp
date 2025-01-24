#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>
#include <Servo.h>

#define LDRPIN A1 //  LDR sensor
#define DHTPIN 2 //  DHT sensor
#define DHTTYPE DHT11 // DHT11 or DHT22
#define MOISTUREPIN A0 // moisture sensor
#define LEDPIN 7 //  LED
#define BUZZERPIN 8 //  Buzzer
#define SERVOPIN 9 //  servo motor
#define PIRPIN 3 //  PIR sensor

LiquidCrystal_I2C lcd(0x27, 20, 4); // LCD with address 0x27, 20 columns and 4 rows
RTC_DS3231 rtc;
DHT dht(DHTPIN, DHTTYPE);
Servo myServo;

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUZZERPIN, OUTPUT);
  pinMode(PIRPIN, INPUT);
  myServo.attach(SERVOPIN);
  dht.begin();
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
}

void loop() {
  int moistureValue = analogRead(MOISTUREPIN);
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int pirState = digitalRead(PIRPIN);
  int ldrValue = analogRead(LDRPIN);
  DateTime now = rtc.now();

  
  Serial.print("Moisture: "); Serial.println(moistureValue);
  Serial.print("Temp: "); Serial.println(temperature);
  Serial.print("Humidity: "); Serial.println(humidity);
  Serial.print("PIR: "); Serial.println(pirState);

 
  if (moistureValue < 100 || temperature < 0.10 || humidity < 10) {
    digitalWrite(LEDPIN, HIGH);
    digitalWrite(BUZZERPIN, HIGH);
    myServo.write(90);
  } else {
    digitalWrite(LEDPIN, LOW);
    digitalWrite(BUZZERPIN, LOW);
    myServo.write(0);
  }

  bool pestDetected = (pirState == HIGH) || (ldrValue < 300);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature);
  lcd.print("C ");
  lcd.print("H:");
  lcd.print(humidity);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Moisture: ");
  lcd.print(moistureValue);

  lcd.setCursor(0, 2);
  lcd.print(pestDetected ? "Pest detected!" : "No pest detected");

  lcd.setCursor(0, 3);
  lcd.print("Time: ");
  lcd.print(now.hour());
  lcd.print(':');
  lcd.print(now.minute());
  lcd.print(':');
  lcd.print(now.second());

  delay(2000);
}
