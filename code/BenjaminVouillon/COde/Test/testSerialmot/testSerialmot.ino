char a;
String mot="";
char truc="heijljdl";
void setup() {
  Serial.begin(9600);
}



void loop() {
 /* if (Serial.available()>0){// permet de n'afficher dans le terminal des trucs que si le buffer est plein
  a=Serial.read();
  Serial.println(a);}
*/
  while(Serial.available() > 0){
    a=Serial.read();
    mot=String(mot+a);  // important de convertire une char en string
    }
    Serial.println(mot);
    mot="";
    
  }

