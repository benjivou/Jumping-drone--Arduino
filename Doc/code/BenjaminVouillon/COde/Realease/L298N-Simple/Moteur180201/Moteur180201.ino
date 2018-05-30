#include <L298N.h>


String mot;               // String brut de commande
String ordre;             // commande de controle
String arg;               // argument de commande
int argBin;               // donne la valeur binaire d'un argument
int val;                  // valeur de la commande

int vit = 200;    // vitesse, puissance électrique
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
  motorDroite.setSpeed(vit);    // definie la vitesse des moteurs
  motorGauche.setSpeed(vit);
}

void loop() {

  if (Serial.available()>0){        // permet de ne faire des changement qur quand on lui demande


    while(Serial.available() > 0){         //////////// permet de prendre la requête entière
      car=Serial.read();
      mot=String(mot+car);        // important de convertire une char en string
      }
      //// Maintenant il faut étudier l'ordre (lettre arg(!,#) int) dans le mot

    while (mot!=""){                        // j'étudie le mot caractére par caractére
      ordre=mot[1];                         // je stocke le premiercaractére
      mot.remove(0,1);                      // j'efface le premier caractére

      switch(ordre.toInt()){                        //////////// permet de traiter un ordre
        case 102:                           //// Forward    'f'
          arg=String(mot[1],BIN);                         // je stocke le premier caractére
          argBin=arg.toInt();
          switch(argBin){

            case 36:                               // set la vitesse    '$'
              mot.remove(0,1);                      // j'efface le premier caractére car c'est un dollar

              arg="";
              val=0;                                // valeur de base 0

              argBin = String(mot[1],BIN).toInt();
              while(argBin<97){                     // valeur décimal en ASCII inférieur à 'a'
                arg+=String(mot[1]);                // je recré la valeur
                mot.remove(0,1);                    // je retire la valeur du mot de départ 
                argBin = String(mot[1],BIN).toInt();// je test la valeur de la prochaine variable
              }
              vit=arg.toInt();                      // je récupére ma valeur
    
              motorDroite.setSpeed(vit);    // definie la vitesse des moteurs
              motorGauche.setSpeed(vit);
              }
          motorDroite.forward();
          motorGauche.forward();
          break;
        case 98:                           //// Backward  'b'

          motorGauche.backward();
          motorDroite.backward();
          break;
        case 115:                           //// Stop 's'

          motorGauche.stop();
          motorDroite.stop();
          break;
        case 100:                          //// tourne à droite 'd'
          motorDroite.stop();
          break;
        case 103:                          //// tourne à gauche  'g'
          motorGauche.stop();
          break;
        case 116:                          //// tourne sur lui-même 't'
          motorGauche.backward();
          motorGauche.forward();
          break;
      }
    }
    mot="";
  }
}
