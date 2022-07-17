#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); // CONNECT BT RX PIN TO ARDUINO 11 PIN | CONNECT BT TX PIN TO ARDUINO 10 PIN

char tiltDirection;
int motorInput1 = 2;
int motorInput2 = 3;
int motorInput3 = 4;
int motorInput4 = 5;
#include<Servo.h>
int pos=180;
Servo myservo;
void setup() {
myservo.attach(13);
 myservo.write(pos);
  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);
  pinMode(motorInput3, OUTPUT);
  pinMode(motorInput4, OUTPUT);

  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);

  Serial.begin(115200);      // Serial communication is activated at 38400 baud/s.
  BTSerial.begin(9600);    // HC-05 default speed in AT command more
}
void loop() {
  if (BTSerial.available()) {   
    tiltDirection = BTSerial.read();
    Serial.println(tiltDirection);
    if(tiltDirection == 'B'){
      Serial.println(" reverse");
       reverse();
    }else if(tiltDirection == 'F'){
      Serial.println("Forward");
      forward();
    }else if(tiltDirection == 'L'){
      Serial.println("Left");
      left();
    }else if(tiltDirection == 'R'){
      Serial.println("Right");
      right();
    }else if(tiltDirection == 'S'){
      Serial.println("Stop");
      stopCar();
    }
    if (tiltDirection==0){
      gripperon();
      }
       else if (tiltDirection==1){
      gripperoff();
      }
  }
}
void forward()
{
  /*The pin numbers and high, low values might be different depending on your connections */
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
}
void reverse()
{
  /*The pin numbers and high, low values might be different depending on your connections */
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);
}
void right()
{
  /*The pin numbers and high, low values might be different depending on your connections */
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);
}
void left()
{
  /*The pin numbers and high, low values might be different depending on your connections */
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
}

void stopCar() {
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);
}
void gripperon(){
   
    myservo.write(180);              
    delay(15);   }
  void gripperoff(){
      myservo.write(0);              
    delay(15);
}
