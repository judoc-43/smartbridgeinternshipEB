const int trig = 4;
const int echo=5;
int dur;
int dist;
void setup() {
  // put your setup code here, to run once:
pinMode(26,OUTPUT);
pinMode(27,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,INPUT);
Serial.begin(115200);
}

void loop() {
  digitalWrite(4,LOW);
delay(2);
digitalWrite(4,HIGH);
delay(1000);
digitalWrite(4,LOW);
dur=pulseIn(5,HIGH);
dist=dur*0.034/2;
Serial.println("DISTANCE:");
Serial.println(dist);
if(dist<15)
{
digitalWrite(26,LOW);
digitalWrite(27,LOW);
delay(1000);
}
else
{
digitalWrite(26,LOW);
digitalWrite(27,HIGH);
delay(1000);
}
}
