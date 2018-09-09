// Den stora arduinokoden till Kamera-slidern. En work in progress.
// Board: Arduino Nano?

#include <CameraStepper.h>
#include <Servo.h>

#define STEPS 200

CameraStepper motor(STEPS, 4, 5, 6, 7);
Servo servo;

int stepsLength, motorSpeed, maxMotorSpeed;
double pivotDist;
byte minPos, maxPospos, pos;
bool pause;

void setup(){
    Serial.begin(9600);
    stepsPerLength = 3000;  // Ändra detta när vi vet hur många steg den tar för att åka hela vägen bort till batterisidan.
    minPos = 0;
    maxPos = stepsPerLength;
    pos = minPos;           // Startpos är alltid längst mot "hjärnan"?
}

void loop(){
    configureBeforeRun();
    if(run){
        if(startFromLeft){
            //Kör bort motorn till maxPos, alltså mot batterisidan.
            //Byt direction på motorn
        }
        run = 0;
        //Sätt servo till rätt pos enl matteformel
        delay(1000);
        while(!pause){
            motor.stepOne(startFromLeft);
            ++pos;
            //Uppdatera servopos enl nån matteformel som beror av pos (ta hänsyn till vilken riktning man kör i)
            delay(stepDelay);
        }
        if(!startFromLeft){
            //Kör tillbaka till minPos
        }
    }
}

void configureBeforeRun(){

}

void SerialEvent(){
    byte pivotDistM, pivotDistCm;
    delay(10);
    if(Serial.available() == 10){                //Ange inställningar
        motorSpeed = (byte) Serial.read();
        pivotDistM = (byte) Serial.read();
        pivotDistCm = (byte) Serial.read();
    }
    if(Serial.available() = 'g'){                // Run with previous settings
        run = 1;
    }
}