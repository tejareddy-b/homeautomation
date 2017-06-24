#include<SoftwareSerial.h>
SoftwareSerial XBee(2,3); // RX, TX
void setup() {
  XBee.begin(9600);
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() { 
  // put your main code here, to run repeatedly:
  if (Serial.available())
  { // If data comes in from serial monitor, send it out to XBee
    XBee.write(Serial.read());
  }
  if (XBee.available())
  { // If data comes in from XBee, send it out to serial monitor
   char s = XBee.read();
   Serial.println(s);    
 if(s=='1')
 {
  digitalWrite(11,HIGH);
 }
 else if(s=='0')
 {
  digitalWrite(11,LOW);
 }
 if(s=='3')
 {
  digitalWrite(12,HIGH);
 }
 else if(s=='2')
 {
  digitalWrite(12,LOW);
 }
 if(s=='5')
 {
  digitalWrite(13,HIGH);
 }
 else if(s=='4')
 {
  digitalWrite(13,LOW);
 }
 }
}
