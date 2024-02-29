#define sensorpin A0

void sensorInit(){
    pinMode(sensorpin,INPUT);
}

float readSensor(){
    float  data= 0;
    int looping = 10;
    int time = 5;
    for (int x=0; x<looping; x++){
        data +=analogRead(sensorpin);
        delay(time);
        // total need delay*looping time ms for read all value 
    }
    // return average value
    if ((data/looping)<0) return 0;    
    else if ((data/looping)>900)return 900;
    else{
        return float(data/looping);
    }
    
}
