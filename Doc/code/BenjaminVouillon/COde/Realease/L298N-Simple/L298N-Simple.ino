#include <L298N.h>
String mot;
char ordre;
int vit = 200;
char car;         // caractére de la requête

//pin definition
#define EN 3
#define IN1 4
#define IN2 2
//create a motor instance
L298N motorGauche(EN, IN1, IN2);
L298N motorDroite(5, 6, 7);
void setup() {

  //used for display information
  Serial.begin(9600);

  
}

void loop() {
  motorDroite.setSpeed(vit); // definie la vitesse des moteurs
  motorGauche.setSpeed(vit);
  
  while(Serial.available() > 0){         //////////// permet de prendre la requête entière
    car=Serial.read();
    mot=String(mot+car);        // important de convertire une char en string
    }
    
    
    
  switch(ordre){                         //////////// permet de traiter l'ordre
    
    case 'f':                           //// Forward
      Serial.println(ordre == 'f');
      
      motorDroite.forward();
      motorGauche.forward();
      break;
    case 'b':                           //// Backward
      Serial.println(ordre == 'b');
      motorGauche.backward();
      motorDroite.backward();
      break;
    case 's':                           //// Stop
      Serial.println(ordre == 's');
      motorGauche.stop();
      motorDroite.stop();
      break;
    case 'd':                          //// tourne à droite
      motorDroite.stop();
      break;
    case 'g':                          //// tourne à gauche
      motorGauche.stop();
      break;
    case 't':                          //// tourne sur lui-même
      motorGauche.backward();
      motorGauche.forward();
      break;
  }
  mot="";
}
