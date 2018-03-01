
class Coeur{
private:
  String mot;
  bool loading; // détermine si le mot est affichable ou non
public:
  void Ecrire(); // Ecrit le caractére
  void Afiche(); // Affiche le mot 
  void Refresh(); // Réinisialise le mot
  int Test();     // Test si le mot est lisible ou non 
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


Coeur bon; // variable de test

void setup() { 
Serial.begin(9600);
}

void loop() {
  while(Serial.available() and bon.Test()==1){
  bon.Ecrire();
  }
  bon.Refresh();
  
}
