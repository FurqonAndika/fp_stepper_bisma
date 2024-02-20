#define sensorpin A0


void sensorInit(){
    pinMode(sensorpin,INPUT);
}

float readSensor(){
    float data = 0;
    int looping = 10;
    for (int x; x<looping; x++){
        data +=analogRead(sensorpin)
    }
    return data/looping;
}
