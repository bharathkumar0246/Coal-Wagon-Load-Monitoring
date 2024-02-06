
#include <Arduino.h>
#include "HX711.h"
#include <Wire.h>
#include <LCD_I2C.h>

#define LED1_PIN 33
#define LED2_PIN 25

const int LOADCELL_DOUT_PIN = 5;
const int LOADCELL_SCK_PIN = 18;

LCD_I2C lcd(0x27, 16, 2);
HX711 scale;

int reading;
int lastReading;
#define CALIBRATION_FACTOR 0.41923

// function to display weight 
int displayWeight(int weight){ 
    // Overload Condition - Weight greater than or equal to 1500 grams
    if(weight >= 1500){
        digitalWrite(LED2_PIN, HIGH);
        digitalWrite(LED1_PIN, LOW);
        for(int i = 0; i < 2; i++){
            lcd.print("   Overload!!");
            delay(500);
            lcd.clear(); // for blinking of LCD
            delay(500);
        }
        return 0;
    }

    // Weight printed in grams if less than 1000 grams
    if(weight < 1000){
        digitalWrite(LED1_PIN, HIGH);
        digitalWrite(LED2_PIN, LOW);
        lcd.print("     Weight");
        lcd.setCursor(5,1);
        lcd.print(weight);
        lcd.print(" ");
        lcd.print("g   ");
        Serial.print("Weight: ");
        Serial.print(weight);
        Serial.println(" g");
        return 0;
    }

    // Weight printed in kilograms if greater than or equal to 100 grams
    if(weight >= 1000){
        digitalWrite(LED1_PIN, HIGH);
        digitalWrite(LED2_PIN, LOW);
        lcd.print("     Weight");
        lcd.setCursor(4,1);
        lcd.print(weight/1000);
        lcd.print(" ");
        lcd.print("kg  ");
        Serial.print("Weight: ");
        Serial.print(weight);
        Serial.println(" g");
        return 0;
    }
}

// Setting up the components
void setup() {  
    Serial.begin(115200);
    lcd.begin(); 
    lcd.backlight();
    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);
    scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
    scale.set_scale(CALIBRATION_FACTOR);  // setting up the load cell with its calibration factor
}

// Code to run repeatedly
void loop() {
    reading = round(scale.get_units());
    displayWeight(reading); // calling displayweight function
    delay(1000);
    lastReading = reading;
}  
