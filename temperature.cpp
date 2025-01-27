#define LM35 A0

void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop() {
  int lmValue = analogRead(LM35);

  float celsius = (lmValue * 500.0) / 1023.0;

  float fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
  Serial.print("Temperature in Celsius: ");
  Serial.print(celsius);
  Serial.print(" °C, ");

  Serial.print("Temperature in Fahrenheit: ");
  Serial.print(fahrenheit);
  Serial.println(" °F");

  delay(1000);  
}