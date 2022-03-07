#include <Adafruit_NeoPixel.h>


#define PINBOTON1 7
#define PINBOTON2 9
#define PINBOTON3 10



float patterns [] [3] = {
  { 0, 0, 50 },  // NUCLEO
  { 0, 50, 100 },  // PALMA
  { 0, 50, 0 },  // HABILIDAD 1
  { 0, 0, 50 },  // HABILIDAD 2
  { 255, 102, 0 },  // HABILIDAD 3
  { 128, 0, 255 },  // HABILIDAD 4
};
float patternsSEL [] [3] = {
  { 0, 255, 0 },  // HABILIDAD 1
  { 0, 0, 255 },  // HABILIDAD 2
  { 255, 128, 0 },  // HABILIDAD 3
};


const int pinBoton1 = PINBOTON1;
int estadoBoton1 = 0;
const int pinBoton2 = PINBOTON2;
int estadoBoton2 = 0;
const int pinBoton3 = PINBOTON3;
int estadoBoton3 = 0;

Adafruit_NeoPixel nucleoStrip = Adafruit_NeoPixel(1, 2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel palmaStrip = Adafruit_NeoPixel(1, 3, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel habStrips[] = { Adafruit_NeoPixel(1, 6, NEO_GRB + NEO_KHZ800), Adafruit_NeoPixel(1, 5, NEO_GRB + NEO_KHZ800), Adafruit_NeoPixel(1, 4, NEO_GRB + NEO_KHZ800)};

int lastPressed = 0;

int contHabilidad = 0;
int contSel = 0;
bool atqNormal = true;

float brightness1 = 0;
bool brightness1Dir = false;

float brightness2 = 100;
bool brightness2Dir = false;

float brightness3 = 50;
bool brightness3Dir = false;

float brightness4 = 150;
bool brightness4Dir = false;

float brightness5 = 250;
bool brightness5Dir = false;

void setup() {
  Serial.begin(9600);

  pinMode(pinBoton1, INPUT_PULLUP);
  pinMode(pinBoton2, INPUT_PULLUP);
  pinMode(pinBoton3, INPUT_PULLUP);

  nucleoStrip.begin();
  palmaStrip.begin();
  habStrips[0].begin();  
  habStrips[1].begin();  
  habStrips[2].begin();
}

void loop() {
  //LUZ NUCLEO
  if(brightness1Dir){
      brightness1 += 0.1f;
  }else{
      brightness1 -= 0.05f;
  }
  if(brightness1 > 255){
    brightness1Dir = false;
  }else if(brightness1 < 0){
    brightness1Dir = true;
  }
  
  //LUZ PALMA
  if(brightness2Dir){
      brightness2 += 0.08f;
  }else{
      brightness2 -= 0.05f;
  }
  if(brightness2 > 255){
    brightness2Dir = false;
  }else if(brightness2 < 0){
    brightness2Dir = true;
  }

  //LUZ HAB1
  if(brightness3Dir){
      brightness3 += 0.03f;
  }else{
      brightness3 -= 0.05f;
  }
  if(brightness3 > 255){
    brightness3Dir = false;
  }else if(brightness3 < 0){
    brightness3Dir = true;
  }

  //LUZ HAB2
  if(brightness4Dir){
      brightness4 += 0.03f;
  }else{
      brightness4 -= 0.05f;
  }
  if(brightness4 > 255){
    brightness4Dir = false;
  }else if(brightness4 < 0){
    brightness4Dir = true;
  }

  //LUZ HAB3
  if(brightness5Dir){
      brightness5 += 0.03f;
  }else{
      brightness5 -= 0.05f;
  }
  if(brightness5 > 255){
    brightness5Dir = false;
  }else if(brightness5 < 0){
    brightness5Dir = true;
  }
  //------
  estadoBoton1 = digitalRead(pinBoton1);
  estadoBoton2 = digitalRead(pinBoton2);
  estadoBoton3 = digitalRead(pinBoton3);

  nucleoStrip.setPixelColor(0,patterns[0][0],patterns[0][1],patterns[0][2]);
  
if(contHabilidad == 0){
      contSel = 0;
      habStrips[0].setPixelColor(0,patterns[2][0],patterns[2][1],patterns[2][2]);
      if(atqNormal){
        palmaStrip.setPixelColor(0,patterns[1][0],patterns[1][1],patterns[1][2]);
      }else{
        palmaStrip.setPixelColor(0,patternsSEL[0][0],patternsSEL[0][1],patternsSEL[0][2]);
      }
      

      habStrips[1].setPixelColor(0,0,0,0);
      habStrips[2].setPixelColor(0,0,0,0);

    }else if(contHabilidad == 1){
      habStrips[2].setPixelColor(0,0,0,0);
      if(contSel >= 2){
        contSel = 0;
      }
      if(contSel == 0){
        habStrips[0].setPixelColor(0,patternsSEL[0][0],patternsSEL[0][1],patternsSEL[0][2]);
        habStrips[1].setPixelColor(0,patterns[3][0],patterns[3][1],patterns[3][2]);
      if(atqNormal){
        palmaStrip.setPixelColor(0,patterns[1][0],patterns[1][1],patterns[1][2]);
      }else{
        palmaStrip.setPixelColor(0,patternsSEL[0][0],patternsSEL[0][1],patternsSEL[0][2]);
      }        
      }else if(contSel == 1){
        habStrips[0].setPixelColor(0,patterns[2][0],patterns[2][1],patterns[2][2]);
        habStrips[1].setPixelColor(0,patternsSEL[1][0],patternsSEL[1][1],patternsSEL[1][2]);
      if(atqNormal){
        palmaStrip.setPixelColor(0,patterns[1][0],patterns[1][1],patterns[1][2]);
      }else{
        palmaStrip.setPixelColor(0,patternsSEL[1][0],patternsSEL[1][1],patternsSEL[1][2]);
      }  

      }
    }else if(contHabilidad == 2){
      if(contSel >=3){
        contSel = 0;
      }
      if(contSel == 0){
        habStrips[0].setPixelColor(0,patternsSEL[0][0],patternsSEL[0][1],patternsSEL[0][2]);
        habStrips[1].setPixelColor(0,patterns[3][0],patterns[3][1],patterns[3][2]);
        habStrips[2].setPixelColor(0,patterns[4][0],patterns[4][1],patterns[4][2]);
      if(atqNormal){
        palmaStrip.setPixelColor(0,patterns[1][0],patterns[1][1],patterns[1][2]);
      }else{
        palmaStrip.setPixelColor(0,patternsSEL[0][0],patternsSEL[0][1],patternsSEL[0][2]);
      } 

      }else if(contSel == 1){
        habStrips[0].setPixelColor(0,patterns[2][0],patterns[2][1],patterns[2][2]);
        habStrips[1].setPixelColor(0,patternsSEL[1][0],patternsSEL[1][1],patternsSEL[1][2]);
        habStrips[2].setPixelColor(0,patterns[4][0],patterns[4][1],patterns[4][2]);
      if(atqNormal){
        palmaStrip.setPixelColor(0,patterns[1][0],patterns[1][1],patterns[1][2]);
      }else{
        palmaStrip.setPixelColor(0,patternsSEL[1][0],patternsSEL[1][1],patternsSEL[1][2]);
      } 

      }else if(contSel == 2){
        habStrips[0].setPixelColor(0,patterns[2][0],patterns[2][1],patterns[2][2]);
        habStrips[1].setPixelColor(0,patterns[3][0],patterns[3][1],patterns[3][2]);
        habStrips[2].setPixelColor(0,patternsSEL[2][0],patternsSEL[2][1],patternsSEL[2][2]);
      if(atqNormal){
        palmaStrip.setPixelColor(0,patterns[1][0],patterns[1][1],patterns[1][2]);
      }else{
        palmaStrip.setPixelColor(0,patternsSEL[2][0],patternsSEL[2][1],patternsSEL[2][2]);
      } 

      }
    }else if(contHabilidad == 3){
        habStrips[0].setPixelColor(0,patterns[5][0],patterns[5][1],patterns[5][2]);
        habStrips[1].setPixelColor(0,patterns[5][0],patterns[5][1],patterns[5][2]);
        habStrips[2].setPixelColor(0,patterns[5][0],patterns[5][1],patterns[5][2]);
       if(atqNormal){
        palmaStrip.setPixelColor(0,patterns[1][0],patterns[1][1],patterns[1][2]);
      }else{
        palmaStrip.setPixelColor(0,patterns[5][0],patterns[5][1],patterns[5][2]);
      } 

    }

    
    
  if (estadoBoton1 == 0) {
    contarHabilidad();

  }else if (estadoBoton2 == 0) {
    delay(500);
    contSel++;
  }else  if(estadoBoton3 == 0){
    if(atqNormal){
      atqNormal=false;
    }else{
      atqNormal=true;
    }
    delay(500);
  }

  nucleoBrillo(brightness1);
  palmaBrillo(brightness2);
  palmaHab1(brightness3);
  palmaHab2(brightness4);
  palmaHab3(brightness5);

  habStrips[0].show();
  habStrips[1].show();
  habStrips[2].show();
  nucleoStrip.show();
  palmaStrip.show();
}

void nucleoBrillo(float brillo){
  nucleoStrip.setBrightness(brillo);
}
void palmaBrillo(float brillo){
  palmaStrip.setBrightness(brillo);
}
void palmaHab1(float brillo){
  habStrips[0].setBrightness(brillo);
}
void palmaHab2(float brillo){
  habStrips[1].setBrightness(brillo);
}
void palmaHab3(float brillo){
  habStrips[2].setBrightness(brillo);
}
void contarHabilidad(){
      contHabilidad++;

    if(contHabilidad > 3){
      contHabilidad = 0;
    }
    delay(500);
}
