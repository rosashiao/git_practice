#include<LiquidCrystal_I2C.h>
#include <Wire.h> 
#include <DHT.h>
#define pin 2 //定義DHT data pin角
#define DHTTYPE DHT11
LiquidCrystal_I2C lcd(0x27,16,2); //宣告LCD物件
DHT dht2 (pin,DHTTYPE); //宣告DHT物件

void setup() {
  lcd.init(); //初始化LCD 
  lcd.backlight(); //開啟背光
  lcd.print("I AM DETECTOR"); //顯示I AM DETECTOR
  delay(1000);  //延遲一秒
  dht2.begin();
}

void loop() {
  lcd.clear(); //清除顯示的文字
  lcd.setCursor(0, 0);// (column,row)
  lcd.print("Tem:"); //顯示Tem
  lcd.setCursor(4, 0);// (column,row)
  lcd.print(dht2.readTemperature()); //顯示溫度值
  lcd.setCursor(0, 1);// (column,row)
  lcd.print("Hum:"); //顯示Hum
  lcd.setCursor(4, 1);// (column,row)
  lcd.print(dht2.readHumidity()); //顯示溫度值
  delay(1000); //延遲一秒
}
