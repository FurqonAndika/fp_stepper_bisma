#include "driver/sensor.h"
#include "driver/motor.h"

void setup(){
    // initial component
    Serial.begin(9600);
    // Serial.println("system start");
    sensorInit();
    motorInit();


}
int pos = 0;
unsigned long elapsed =0;
int counter = 0;
    // loop
void loop(){
        // read sensorvalue from pin A0
        float sensorValue = readSensor();
        
        sensorValue = map(sensorValue,180,900,0,255);
        if(sensorValue<0)sensorValue=0;
        // Serial.println(sensorValue);
        



        // if (millis()-elapsed>1000){
        //   counter +=1;
        //   if (counter%2==0)spinMotor(true, 100);
        //   else {
        //     spinMotor(false,100);
        //   }
        //   elapsed = millis();
        // }



        if (pos !=sensorValue){
            int step;
            if(sensorValue-pos>0){
                if (pos<255){
                    step = sensorValue-pos;
                    spinMotor(true, step);
                    pos = pos+step;
                    if (pos>255)pos=255;
                }
            }
            else {
                if (pos>0){
                    step = pos - sensorValue;
                    spinMotor(false, step);
                    pos = pos-step;
                    if(pos<0)pos=0;
                }
            }
            
        }
        Serial.println(pos);

      
 
    
}
