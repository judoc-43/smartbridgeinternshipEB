int eco=5;
int triger=4;
long duration;
int distance;
void setup() {
  // put your setup code here, to run once:
pinMode(eco,INPUT);
pinMode(triger,OUTPUT);
pinMode(2,OUTPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(triger,LOW);
delay(2);
digitalWrite(triger,HIGH);
delay(1000);
digitalWrite(triger,LOW);
duration= pulseIn(eco,HIGH);
distance= duration*0.032/2;
Serial.println("distance:");
Serial.println(distance);
if(distance>140)
{
  digitalWrite(2,HIGH);
}
else if (6<distance>23)
{
  digitalWrite(6,HIGH);
}
else if(25<distance>100)
{
  digitalWrite(8,HIGH);
}
else
{
  digitalWrite(2,LOW);
}



}
