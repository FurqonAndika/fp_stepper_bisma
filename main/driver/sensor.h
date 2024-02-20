#define sensorpin A0

void sensorInit(){
    pinMode(sensorpin,INPUT);
}

float readSensor(){
    float data = 0;
    int looping = 10;
    int time = 50;
    for (int x; x<looping; x++){
        data +=analogRead(sensorpin);
        delay(time);
        // total need delay*looping time ms for read all value 
    }
    // return average value
    return data/looping;
}
