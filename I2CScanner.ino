#include <Wire.h>

void setup() {
  byte x = 0;
  Serial.begin(9600);
  while(!Serial){ delay(1000); }
  Serial.println();
  Serial.println("I2C Address Scanner.");

  Wire.begin();
  for(byte i=0; i<255; i++){
    Wire.beginTransmission(i);
    if(Wire.endTransmission()==(byte)0){
      /*
       * 0:success
       * 1:data too long to fit in transmit buffer
       * 2:received NACK on transmit of address
       * 3:received NACK on transmit of data
       * 4:other error
      */
      Serial.print ("- address DEX: ");
      Serial.print (i, DEC);
      Serial.print (" HEX: (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      x++;
      delay(300);
    }
  }
  Serial.print("(");
  Serial.print(x, DEC);
  Serial.println(") detected.");
}

void loop(){
}
