//-- MOTEUR A --
int ENA=3; //ConnectÃ© Ã  Arduino pin 5(sortie pwm)
int IN1=4; //ConnectÃ© Ã  Arduino pin 2
int IN2=2; //ConnectÃ© Ã  Arduino pin 3

//-- MOTEUR B --
int ENB=5; //ConnectÃ© Ã  Arduino pin 6(Sortie pwm)
int IN3=7; //ConnectÃ© Ã  Arduino pin 4
int IN4=6; //ConnectÃ© Ã  Arduino pin 7

void setup() {
 pinMode(ENA,OUTPUT);//Configurer les broches comme sortie
 pinMode(ENB,OUTPUT);
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 digitalWrite(ENA,LOW);// Moteur A - Ne pas tourner (dÃ©sactivation moteur)
 digitalWrite(ENB,LOW);// Moteur B - Ne pas tourner (dÃ©sactivation moteur)

 // Direction du Moteur A
 digitalWrite(IN1,HIGH); 
 digitalWrite(IN2,LOW);

 // Direction du Moteur B
 // NB: en sens inverse du moteur A
 digitalWrite(IN3,HIGH);
 digitalWrite(IN4,LOW);
}

void loop() {
  // Moteur A - Plein rÃ©gime
  analogWrite(ENA,1024);     // eteind le moteur
  analogWrite(ENB,0);   // moteur petit régime
  delay(1000);
  analogWrite(ENA,0);  // moteur à fond
  analogWrite(ENB,1024);
  digitalWrite(13,HIGH);
  delay(4000);
  digitalWrite(13,LOW);
  
  
  
}



