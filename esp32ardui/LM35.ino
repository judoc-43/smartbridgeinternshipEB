int tempvalue;
int ledval;

void setup() {
  // put your setup code here, to run once
pinMode(4,INPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  tempvalue=analogRead(4);
  ledval=tempvalue*330/2048;
  Serial.println(ledval);
}
