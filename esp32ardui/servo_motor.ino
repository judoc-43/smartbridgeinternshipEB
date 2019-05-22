#include <Servo.h>


Servo ser;
int pos=0;
void setup() {
  // put your setup code here, to run once:
ser.attach(27);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(pos=0;pos<=180;pos=pos+1)
  {
    ser.write(pos);
    Serial.println(pos);
    delay(100);
    
    
   }
   for(pos=180;pos>=0;pos--)
   {
    ser.write(pos);
    Serial.println(pos);
    delay(100);
    
    }

}
