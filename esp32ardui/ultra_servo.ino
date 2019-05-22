#include <Servo.h>

const int trig = 4;
const int echo=5;
int dur;
int dist;
Servo ser;
int pos=0;
void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,INPUT);
ser.attach(27);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(4,LOW);
delay(2);
digitalWrite(4,HIGH);
delay(1000);
digitalWrite(4,LOW);
dur=pulseIn(5,HIGH);
dist=dur*0.034/2;
Serial.println("DISTANCE:");
Serial.println(dist);
if(dist<30)
{
  ser.write(90);
  delay(20);
  }
  else
  {
    ser.write(0);
    delay(20);
  }
}
