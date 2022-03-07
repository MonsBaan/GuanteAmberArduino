#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define BUTTON_PIN 7
#define BUTTON_PIN2 9

boolean brightenBool;

const int buttonPin = BUTTON_PIN;
int buttonState = 0;
const int buttonPin2 = BUTTON_PIN2;
int buttonState2 = 0;
Adafruit_NeoPixel strips[] = { Adafruit_NeoPixel(2, PIN2, NEO_GRB + NEO_KHZ800), Adafruit_NeoPixel(1, PIN3, NEO_GRB + NEO_KHZ800),
                               Adafruit_NeoPixel(1, PIN4, NEO_GRB + NEO_KHZ800), Adafruit_NeoPixel(1, PIN5, NEO_GRB + NEO_KHZ800),
                               Adafruit_NeoPixel(1, PIN6, NEO_GRB + NEO_KHZ800) };

uint8_t brightLevel;

int inPin1 = 11;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 5; i++) {
    strips[i].begin();
    strips[i].show();
  }
  brightenBool = false;
  brightLevel = 0;

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  Serial.println(buttonState);
  Serial.println(buttonState2);

  if (brightLevel <= 0) {
    brightenBool = true;
    delay(2000);
  } else if (brightLevel >= 255) {
    brightenBool = false;
  }

  if (brightenBool == true) {
    brightLevel++;
  } else if (brightenBool == false) {
    brightLevel--;
  }

  if(buttonState == 1 && buttonState2 == 1){
  setLightsToBrightness1(brightLevel);
  setLightsToBrightness2(brightLevel);
  setLightsToBrightness3(0);
  setLightsToBrightness4(0);
  setLightsToBrightness5(0);
  }else if (buttonState2 == 1){
  setLightsToBrightness1(brightLevel);
  setLightsToBrightness2(brightLevel);
  setLightsToBrightness3(brightLevel);
  setLightsToBrightness4(0);
  setLightsToBrightness5(0);
  }else if (buttonState == 1){
  setLightsToBrightness1(brightLevel);
  setLightsToBrightness2(brightLevel);
  setLightsToBrightness3(brightLevel);
  setLightsToBrightness4(brightLevel);
  setLightsToBrightness5(0);

  }else{
  setLightsToBrightness1(brightLevel);
  setLightsToBrightness2(brightLevel);
  setLightsToBrightness3(brightLevel);
  setLightsToBrightness4(brightLevel);
  setLightsToBrightness5(brightLevel);
  }


  delay(5);
}



void setLightsToBrightness1(int brightness) {
  strips[0].setBrightness(brightness);
  strips[0].setPixelColor(0, 219, 99, 0);
  strips[0].setPixelColor(1, 61, 87, 255);
  strips[0].show();
}
void setLightsToBrightness2(int brightness) {
  strips[1].setBrightness(brightness);
  strips[1].setPixelColor(0, 30, 237, 19);
  strips[1].show();
}
void setLightsToBrightness3(int brightness) {
  strips[2].setBrightness(brightness);
  strips[2].setPixelColor(0, 4, 0, 255);
  strips[2].show();
}
void setLightsToBrightness4(int brightness) {
  strips[3].setBrightness(brightness);
  strips[3].setPixelColor(0, 255, 68, 0);
  strips[3].show();
}
void setLightsToBrightness5(int brightness) {
  strips[4].setBrightness(brightness);
  strips[4].setPixelColor(0, 255, 0, 225);
  strips[4].show();
}
