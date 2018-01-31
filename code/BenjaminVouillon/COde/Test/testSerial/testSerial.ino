char a;
void setup() {
  Serial.begin(9600);
}

void loop() {
  a=Serial.read();
  delay(1000);
  Serial.print(a);
  
}
