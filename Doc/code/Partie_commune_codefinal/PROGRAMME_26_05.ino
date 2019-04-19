#include <L298N.h>    // Controle moteur
#include <Servo.h>    // Commande servo
#include <MsTimer2.h> // Interrupteur logique
#include <WS2812FX.h> // Controle des Leds
#include <SoftwareSerial.h>  //Software Serial Port

#define LED_COUNT 33
#define LED_PIN 11
#define SAUT 10
#define EN 4
#define IN1 5
#define IN2 6
#define RxD  3   //Pin 10 pour RX, PB2 sur votre board, a brancher sur le TX du HC-06
#define TxD 2    //Pin 11 pour TX, PB3 sur votre board, a brancher sur le RX du HC-06
#define EN1 7
#define IN3 8
#define IN4 9
Servo myservo;
SoftwareSerial BTSerie(RxD,TxD);



WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);// Led controleur
volatile char mode='B';     //mode de fct led
volatile int vite=200;   // vite de clignotement
volatile String couleur="0x660099"; //couleur led
bool Bordre;

/*Début de requête des blocs*/
const String moteur = (String) 'm';
const String led = (String) 'l';
const String saut = (String) 's';

/// caractére d'ordre ////
const String avance = (String) 'f';
const String recule = (String) 'b';
const String gauche = (String) 'l';
const String droite = (String) 'd';
const String vitesse = (String) 'v';
const String stoppe = (String) 's';

/// limite d'utilisation ///
const int vmax = 180;    // 180 car sinon risque de bruler les moteurs

/// caractére de comportement Led ///
const String Rainbow= (String) 'R';
const String Cligno= (String) 'C';
const String Static= (String) 'S';
const String Breath= (String) 'B';
const String Larson= (String) 'F';

////Variables ///////


int vit = 0;    // vitesse, puissance électrique


//creation moteurs
L298N motorGauche(EN, IN1, IN2);
L298N motorDroite(EN1, IN3, IN4);


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

Coeur bon; // variable de test


/////////////////////////Distribue les commandes et les arguments////////////////////

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
void Led(String arg, String module) {
  ordre(arg,module);
};



void Saut() {
  //// j'utilise le bloc saut
  myservo.write(0);
  Serial.println("JEVAISEN0");
  delay(1000); // délai à modifier en fonction du temps réel pour le servo a effectuer une demi rotation.
  Serial.println("JEVAISEN180");
  myservo.write(180);
};



void ordre(String mode,String coul){
    if(mode== Rainbow ){
      ws2812fx.setMode(FX_MODE_RAINBOW_CYCLE);
      //R=MODE ARCENCIEL RAINBOW_CYCLE
    }
    else if(mode== Cligno){
      ws2812fx.setMode(FX_MODE_BLINK);
      //C=MODE CLIGNOTEMENT BLINK
    }
    else if(mode== Static){
      ws2812fx.setMode(FX_MODE_STATIC);
      //S=MODE FIXE STATIC
    }
    else if(mode== Breath){
      ws2812fx.setMode(FX_MODE_BREATH);
      //B=MODE RESPIRATION BREATH
    }
    else if(mode== Larson){
      ws2812fx.setMode(FX_MODE_LARSON_SCANNER);
      //F=MODE BALAYAGE LARSON_SCANNER
    }else{
      ws2812fx.setMode(FX_MODE_STATIC);
      ws2812fx.setColor(0x000000);
      // if nothing else matches, do the default
      // default is optional
      }


  ws2812fx.setSpeed(vite);
  ws2812fx.setColor(0x660099);
  ws2812fx.start();
};
void runLED(){
  ws2812fx.service();
};
void setup() {
  Serial.begin(9600);
  motorDroite.setSpeed(vit);    // definie la vitesse des moteurs
  motorGauche.setSpeed(vit);
  myservo.attach(SAUT);

    // Configuration du bluetooth
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  BTSerie.begin(9600);
  delay(50);
    // Configuration LED
  ws2812fx.init();
  ws2812fx.setBrightness(100);
  ordre("","");

  MsTimer2::set(10, runLED); // 500ms period
  MsTimer2::start();
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
