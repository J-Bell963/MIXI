//mode 2
boolean mode2Lit = false;
boolean mode2Buttons[] = {false, false, false, false, false, false};
int mode2Pots[] = {0, 0, 0, 0};
int mode2PotTol = 5;


void mode2() {
  if (!mode2Lit) {
    mode2Lit = true;
    secondColor();
  }

  for (int i = 0; i < 8; i++) {//read toggle buttons only
    int thisButton = buttonStates[i];
    if (buttonStates[i] == 1 && i != 3 && i != 7) {
      mode2Buttons[i] = !mode2Buttons[i];
      if (mode2Buttons[i]) {
        usbMIDI.sendControlChange(i + 20, 127, 1);
      }
      else {
        usbMIDI.sendControlChange(i + 20, 0, 1);
      }
    }

    if (buttonStates[i] == 1 && i == 7) { // mode change
      mode = 1;
      mode2Lit = false;
    }

    if (thisButton == 1 && i == 3) {//mode change 
      mode = 3;
      mode2Lit = false;
            Serial.println("pushed");

    }
  }

  for (int i = 0; i < 4; i++) {// read potentiometers 
    int thisPot = potStates[i];
    if (abs(thisPot - mode2Pots[i]) > mode2PotTol) {
      usbMIDI.sendControlChange(i + 28, thisPot, 1);
      mode2Pots[i] = thisPot;
    }
  }
}

void secondColor() {
  if (mode2Lit == true) {//set button colors 
    strip.setPixelColor(0, 255, 0, 0);
    strip.setPixelColor(1, 0, 255, 0);
    strip.setPixelColor(2, 0, 255, 0);
    strip.setPixelColor(3, 0, 255, 0);;
    strip.setPixelColor(4, 0, 0, 255);
    strip.setPixelColor(5, 0, 255, 0);
    strip.setPixelColor(6, 0, 255, 0);
    strip.setPixelColor(7, 0, 255, 0);;
  }
    strip.show();

}
