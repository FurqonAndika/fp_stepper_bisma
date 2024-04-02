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
bool rotate = false;


// 3.25/2  => angka 2 dari rasio 1:2
// 1.625*200==325
int countstep = 300;
    // loop
void loop(){
        // read sensorvalue from pin A0
        float sensorValue = readSensor();
        
        sensorValue = map(sensorValue,900,616,0,countstep);
        if(sensorValue<0)sensorValue=0;
        if(sensorValue>countstep)sensorValue=countstep;
        // Serial.println(sensorValue);

        // if (millis()-elapsed>1000){
        //   counter +=1;
        //   if (counter%2==0)spinMotor(true, 100);
        //   else {
        //     spinMotor(false,100);
        //   }
        //   elapsed = millis();
        // }

        rotate = false;
        
        if ((pos !=sensorValue)&&(abs(sensorValue-pos)>=3)){
          rotate = true;
            int step;
            if(sensorValue-pos>0){
                if (pos<countstep){
                    step = sensorValue-pos;
                    spinMotor(true, step);
                    pos = pos+step;
                    if (pos>countstep)pos=countstep;
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
        Serial.print(pos);
        Serial.print("  ");
          Serial.print(rotate);
        Serial.print("  ");
        Serial.println(sensorValue );

      
 
    
}
