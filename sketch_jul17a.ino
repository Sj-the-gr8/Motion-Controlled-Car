//BT Module uploaded to HC-50
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); 
#define LED_PIN 13 
bool blinkState = false;
const int xpin = A3;                  
const int ypin = A2;
int X ,Y;
void setup() {
  // join I2C bus (I2Cdev library doesn't do this automatically)
 Serial.begin(115200);
  BTSerial.begin(9600);  
  pinMode(LED_PIN, OUTPUT);
  pinMode(7, INPUT);
}
void loop() {
  delay(500);
  X=analogRead(xpin);
  Y=analogRead(ypin);
    Serial.print(X);
    Serial.print("\t");
    Serial.println(Y);
    BTSerial.write(digitalRead(7));
   if (Y>=350&&Y<=395){
  Serial.println("forward");
   BTSerial.write('F');

  }
else if (Y>=270&&Y<=300){
Serial.println("back");
 BTSerial.write('B');
  }

else if (X>=370&&X<=400){
  Serial.println("right");
   BTSerial.write('R');
  }

else if (X>=200&&X<=310){
  Serial.println("left");
   BTSerial.write('L');
 }
  
else {
  Serial.println("stop");
  BTSerial.write('S');
  }
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);
  }
