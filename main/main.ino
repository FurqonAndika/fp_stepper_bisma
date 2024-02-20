

// https://howtomechatronics.com/tutorials/arduino/how-to-control-stepper-motor-with-a4988-driver-and-arduino/

#include "driver/sensor.h"
void setup(){
    Serial.begin(9600);
    sensorInit();
}

void loop(){
    float sensorValue = readSensor();

    

}