#include <Bounce2.h>
//button array creation
int buttonPins[] = {5, 6, 7, 8, 9, 10, 11, 12};
int buttonStates[] = {0, 0, 0, 0, 0, 0, 0, 0};
Bounce * buttons = new Bounce[8];
//potentiometers array creation
int potPins[] = {A0, A1, A2, A3};
int potStates[] = {0, 0, 0, 0};
//libraries 
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(8, 4, NEO_RGB + NEO_KHZ800);

//global variables
int mode = 0;

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.clear();
  initializeButtons();
  initLEDs();
  delay(2000);
  Serial.println("Ready!");
}

void loop() {
  updateButtons();
  updatePots();

  switch (mode) { // switch case
    case 0: startUp(); break;
    case 1: mode1(); break;
    case 2: mode2(); break;
    case 3: mode3(); break;
  }
}
