#include <L298N.h>
#include <MsTimer2.h>
#include <SoftwareSerial.h>  //Software Serial Port    
#define RxD  3   //Pin 10 pour RX, PB2 sur votre board, a brancher sur le TX du HC-06
#define TxD 2    //Pin 11 pour TX, PB3 sur votre board, a brancher sur le RX du HC-06
SoftwareSerial BTSerie(RxD,TxD);  


/////////////////////////Recepteur d'ordre /////////////////////////////////
class Coeur {
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

void Coeur::Ecrire() {
  char car;

  car = BTSerie.read(); // catch mot
  if (car == '$' or Serial.available() < 0) { // caractére de fin de mot
    loading = 0;
  } else {             // je crée mon mot
    mot = String(mot + car);
  }
};
void Coeur::Afiche() {
  Serial.println(mot);
};

int Coeur::Test() {
  return loading;
};

void Coeur::Refresh() {
  mot = "";
  loading = 1;
}
String Coeur::Retour() {
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

void Split(String mot) {

  String bloc = "";
  // je catch le premier caractére du mot
  bloc = mot.substring(0, 1);
  mot.remove(0, 1);
  // je catch le module
  String arg = mot.substring(0, 1);
  mot.remove(0, 1);


  // je dispache mon ordre dans le bon bloc
  if (bloc == moteur) {
    Moteur(arg , mot);
  };
  if (bloc == led) {
    Led(arg , mot);
  };
  if (bloc == saut) {
    Saut();
  };
};

////////////////////////// bloc de commandes///////////////////////////////////////
void Led(String arg, String module) {
  //// j'utilise le bloc led
  Serial.println('l');
  Serial.println(arg);
  Serial.println(module);
};



void Saut() {
  //// j'utilise le bloc saut
  Serial.println('s');
};

////Variables ///////

Coeur bon; // variable de test

//pin definition
#define EN 4
#define IN1 5
#define IN2 6
//create a motor instanc
L298N motorGauche(EN, IN1, IN2);
L298N motorDroite(7, 8, 9);

int vit = 0;    // vitesse, puissance électrique
/// caractére d'ordre ////
const String avance = (String) 'f';
const String recule = (String) 'b';
const String gauche = (String) 'l';
const String droite = (String) 'd';
const String vitesse = (String) 'v';
const String stoppe = (String) 's';

/// limite d'utilisation ///
const int vmax = 180;    // 180 car sinon risque de bruler les moteurs


void setup() {
  Serial.begin(9600);
  motorDroite.setSpeed(vit);    // definie la vitesse des moteurs
  motorGauche.setSpeed(vit);

    // Configuration du bluetooth  
  pinMode(RxD, INPUT);  
  pinMode(TxD, OUTPUT);  
  BTSerie.begin(9600); 
  delay(100);
}

void loop() {
  if (BTSerie.available() > 0) {
     while (BTSerie.available()  and bon.Test() == 1) {
      bon.Ecrire();
    }
    Split(bon.Retour());
    bon.Refresh();
  }
}



void Moteur(String arg, String module) {
  /// je distribue l'argument
  if (arg == avance) {
    motorGauche.forward();
    motorDroite.forward();
  } else if (arg == recule) {
    motorGauche.backward();
    motorDroite.backward();
  } else if (arg == droite) {
    motorGauche.forward();
    motorDroite.backward();
  } else if (arg == gauche) {
    motorGauche.backward();
    motorDroite.forward();
  } else if (arg == vitesse) {
    vit = module.toInt();     //// je convertie le module en nombre
    if (vit > vmax) {       //// je limite la tension sinon les moteurs crame ( 9v ---> 6v)
      vit = vmax;
    };
    motorGauche.setSpeed(vit);
    motorDroite.setSpeed(vit);
  } else if (arg == stoppe) {
    motorGauche.stop();
    motorDroite.stop();
  };
};

