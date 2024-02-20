#include "driver/sensor.h"
#include "driver/motor.h"

int main(){
    // initial component
    Serial.begin(9600);
    sensorInit();
    motorInit();

    // loop
    while (1){
        // read sensorvalue from pin A0
        float sensorValue = readSensor();
        Serial.println(sensorValue);
        spinMotor(true, sensorValue);
    }
}
