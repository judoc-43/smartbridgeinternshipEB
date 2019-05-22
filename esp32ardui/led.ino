int inpin=4;
int outpin=2;
void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
pinMode(3,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(inpin)==LOW)
  {
  digitalWrite(2,HIGH);
  delay(100);
  }
  else
  {
   digitalWrite(2,LOW);
   delay(100);
  }
  

}
