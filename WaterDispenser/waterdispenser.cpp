 #include <Wire.h>
 #include <LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line
 display
 int coinSensorPin = 2;
 int irSensorPin = 3;
 int flowSensorPin = 5;
 int pumpPin = 6;
 volatile boolean isCoinDetected = false;
 int coinValue = 0;
 int coinCounter = 0;
 int waterAmount = 0;
 unsigned long previousTime = 0;
 const long intervalDuration = 3000;
 const int pulseDelayDuration = 1000;
 volatile int pulseCount = 0;
 float flowRate = 0;
 float flowMilliLitres = 0;
 long totalMilliLitres = 0;
 unsigned long oldTime;
 void coinInterrupt() {
 isCoinDetected = true;
 coinCounter++;
 Serial.println(coinCounter);
 }
void setup() {
 pinMode(coinSensorPin, INPUT);
 pinMode(irSensorPin, INPUT);
 pinMode(flowSensorPin, INPUT);
 pinMode(pumpPin, OUTPUT);
 attachInterrupt(digitalPinToInterrupt(coinSensorPin), coinInterrupt, FALLING);
 Serial.begin(19200);
 lcd.init();
 lcd.backlight();
 lcd.setCursor(0, 0);
 lcd.print("Micro Project");
 lcd.setCursor(0, 1);
 lcd.print("GROUP 3");
 }
 void loop() {
 unsigned long currentTime = millis();
 if (currentTime- previousTime >= intervalDuration) {
 if (isCoinDetected) {
 delay(pulseDelayDuration);
 if ((coinCounter >= 3 && coinCounter <= 6) (coinCounter >= 20 && coinCounter <=
 40) (coinCounter >= 120 && coinCounter <= 160)) {
 coinValue = 1;
 } else if ((coinCounter >= 7 && coinCounter <= 11) (coinCounter >= 44 &&
 coinCounter <= 110) (coinCounter >= 220 && coinCounter <= 280)) {
 coinValue = 2;
 } else {
 coinValue = 0;
 }
 Serial.print("Coin value: ");
 Serial.println(coinValue);
 coinCounter = 0;
 isCoinDetected = false;

 }
 if (coinValue == 1 || coinValue == 2) {
 if (digitalRead(irSensorPin) == LOW) {
 lcd.clear();
 if (coinValue == 1) {
 lcd.print("1 rupee inserted");
 waterAmount = 50;
 } else if (coinValue == 2) {
 lcd.print("2 rupee inserted");
 waterAmount = 100;
 }
 delay(2000);
 lcd.clear();
 dispenseWater(waterAmount, coinValue);
 } else {
 lcd.clear();
 lcd.print("Please place the");
 lcd.setCursor(0, 1);
 lcd.print("bottle");
 delay(2000);
 lcd.clear();
 }
 coinValue = 0;
 }
 previousTime = currentTime;
 }
 }
 void dispenseWater(int ml, int rupeeValue) {
 unsigned long startTime = millis();
 unsigned long dispenseDuration;if (rupeeValue == 1) {
 
 dispenseDuration = (ml / 50.0) * 60000;
 } else if (rupeeValue == 2) {
 dispenseDuration = (ml / 100.0) * 60000;
 } else {
 Serial.println("Invalid coin value!");
 return;
 }
 while (millis()- startTime < dispenseDuration) {
 attachInterrupt(digitalPinToInterrupt(flowSensorPin), pulseCounter, FALLING);
 if ((millis()- oldTime) > 1000) {
 detachInterrupt(digitalPinToInterrupt(flowSensorPin));
 flowRate = (pulseCount * 60.0) / (millis()- oldTime);
 oldTime = millis();
 flowMilliLitres = flowRate * 1000;
 totalMilliLitres += flowMilliLitres;
 pulseCount = 0;
 attachInterrupt(digitalPinToInterrupt(flowSensorPin), pulseCounter, FALLING);
 }
 digitalWrite(pumpPin, HIGH);
 }
 digitalWrite(pumpPin, LOW);
 }
 void pulseCounter() {
 pulseCount++;
 }
 