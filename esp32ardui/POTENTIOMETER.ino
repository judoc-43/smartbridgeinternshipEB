int potvalue;
int ledval;

void setup() {
  // put your setup code here, to run once:
  pinMode(16,OUTPUT);
pinMode(4,INPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  potvalue=analogRead(4);
  Serial.println(potvalue);
  ledval=potvalue/4;
  analogWrite(16,ledval);
}
