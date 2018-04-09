#include <WS2812FX.h>
#include <MsTimer2.h>

#define LED_COUNT 30
#define LED_PIN 6

WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
volatile char mode='B';
volatile int vitesse=200;
volatile String couleur="0x660099";
bool Bordre;

void setup() {
  Serial.begin(9600);
  
  ws2812fx.init();
  ws2812fx.setBrightness(100);
  ordre();

  MsTimer2::set(10, runLED); // 500ms period
  MsTimer2::start();
}

void loop() {
  if(Bordre){
    ordre();
    Bordre=false;
  }

  Serial.print("JAVANCE");
  delayMicroseconds(2000000);
  Serial.print("JRECULE");
  

}

void ordre(){
  
  switch (mode) {
    case 'R':
      ws2812fx.setMode(FX_MODE_RAINBOW_CYCLE);
      //R=MODE ARCENCIEL RAINBOW_CYCLE
      break;
    case 'C':
      ws2812fx.setMode(FX_MODE_BLINK);
      //C=MODE CLIGNOTEMENT BLINK
      break;
    case 'S':
      ws2812fx.setMode(FX_MODE_STATIC);
      //S=MODE FIXE STATIC
      break;
    case 'B':
      ws2812fx.setMode(FX_MODE_BREATH);
      //B=MODE RESPIRATION BREATH
      break;
    case 'F':
      ws2812fx.setMode(FX_MODE_LARSON_SCANNER);
      //F=MODE BALAYAGE LARSON_SCANNER
      break;
      
    default:
      ws2812fx.setMode(FX_MODE_STATIC);
      ws2812fx.setColor(0x000000);
      // if nothing else matches, do the default
      // default is optional
      break;
  }
  
  ws2812fx.setSpeed(vitesse);
  ws2812fx.setColor(0x660099);
  ws2812fx.start();
}

void runLED(){
  ws2812fx.service();
}

