#include <L298N.h>
#include <MsTimer2.h> 
/////////////////////////Recepteur d'ordre /////////////////////////////////
class Coeur{
private:
  String mot;
  bool loading; // détermine si le mot est affichable ou non
public:
  void Ecrire(); // Ecrit le caractére
  void Afiche(); // Affiche le mot 
  void Refresh(); // Réinisialise le mot
  int Test();     // Test si le mot est lisible ou non 
  String Retour();// Retourne le mot
};

void Coeur::Ecrire(){
  char car;
  
  car=Serial.read();  // catch mot 
  if (car=='$' or Serial.available()<0){      // caractére de fin de mot
    loading=0;          
  }else{              // je crée mon mot
  mot=String(mot+car);
}};
void Coeur::Afiche(){
  Serial.println(mot);
};

int Coeur::Test(){
  return loading;
};

void Coeur::Refresh(){
  mot="";
  loading=1;
}
String Coeur::Retour(){
  return mot;
}

/////////////////////////Distribue les commandes et les arguments////////////////////
/*Début de requête des blocs*/
const String moteur = (String) 'm';
const String led = (String) 'l';
const String saut = (String) 's';

/* Objectif de Splitter : Séparer le mot du coeur 
en  2 partie, une lettre arg et un mot qui sera une suite de chiffres
Et distribuer l'ordre aux différents modules du drone*/

void Split(String mot){ 
  
  String bloc="";
  // je catch le premier caractére du mot
  bloc=mot.substring(0,1);
  mot.remove(0,1);
  // je catch le module 
  String arg=mot.substring(0,1);
  mot.remove(0,1);

  
  // je dispache mon ordre dans le bon bloc
  if(bloc==moteur){
    Moteur(arg , mot);
  };
  if(bloc==led){
    Led(arg , mot);
  };
  if(bloc ==saut){
    Saut();
  };
};

////////////////////////// bloc de commandes///////////////////////////////////////
void Led(String arg,String module){
  //// j'utilise le bloc led
  Serial.println('l');
  Serial.println(arg);
  Serial.println(module);
};

void Moteur(String arg,String module){
  //// j'utilise le bloc moteur
  Serial.println('m');
  Serial.println(arg);
  Serial.println(module);
};

void Saut(){
  //// j'utilise le bloc saut
  Serial.println('s');
};

////Variables ///////

Coeur bon; // variable de test

//pin definition
#define EN 3
#define IN1 4
#define IN2 2
//create a motor instanc
L298N motorGauche(EN, IN1, IN2);
L298N motorDroite(5, 6, 7);

int vit = 255;    // vitesse, puissance électrique

void setup() { 
Serial.begin(57600);
 motorDroite.setSpeed(vit);    // definie la vitesse des moteurs
 motorGauche.setSpeed(vit);
}

void loop() {
  if(Serial.available()>0){
  delayMicroseconds(1000);                     // Bande passante en microseconde.
  while(Serial.available()>0 and bon.Test()==1){
  bon.Ecrire();
  }
  Split(bon.Retour());
  bon.Refresh();
}}


