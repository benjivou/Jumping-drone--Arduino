#include <Servo.h>
Servo myservo;

void setup() {
  myservo.attach(9);

}

void loop() {
  myservo.write(0);
  delay(1000); // délai à modifier en fonction du temps réel pour le servo a effectuer une demi rotation. 
  myservo.write(180);
  delay(1000);

}
