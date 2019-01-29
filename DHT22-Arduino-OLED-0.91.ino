#include <DHT.h>
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#define DHTPIN 2
#define DHTTYPE DHT22

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0); 
DHT dht(DHTPIN, DHTTYPE);

void setup(void) {
  u8g2.begin();
  Serial.begin(9600); 
  dht.begin();
}

void loop(void) {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  u8g2.clearBuffer();
  u8g2.setFont( u8g2_font_helvB10_tr);
  u8g2.setCursor(5, 15);
  u8g2.print("Temp. :  ");
  u8g2.print(t);
  u8g2.print(" *C");
  u8g2.setCursor(5, 30);
  u8g2.print("Humi. :  ");
  u8g2.print(h);
  u8g2.print(" %");
  u8g2.sendBuffer();
  delay(2000);
}

