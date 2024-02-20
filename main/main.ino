

// https://howtomechatronics.com/tutorials/arduino/how-to-control-stepper-motor-with-a4988-driver-and-arduino/

#include "driver/sensor.h"
#include "driver/motor.h"

// void setup(){
//     Serial.begin(9600);
//     sensorInit();
//     motorInit();
// }

int main(){
    // initial
    Serial.begin(9600);
    sensorInit();
    motorInit();

    // loop
    while (1){
        float sensorValue = readSensor();
        spinMotor(true, 100);
    }
}
// void loop(){
//     // read sensorvalue from pin 
//     float sensorValue = readSensor();
//     spinMotor(true, 100);

// }