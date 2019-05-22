int pirpin=4;
int outpin=2;
void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
pinMode(3,INPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if((digitalRead(pirpin))==HIGH)
  {
  digitalWrite(2,HIGH);
  Serial.println("Human Detected");
  delay(100);
  }
  else
  {
   digitalWrite(2,LOW);
   delay(100);
   Serial.println("waiting for presence");
  }
  

}
