//mode 1
boolean mode1Lit = false;
boolean mode1Buttons[] = {false, false, false, false, false, false};
int mode1Pots[] = {0, 0, 0, 0};
int mode1PotTol = 5;



void mode1() {
  if (!mode1Lit) {
    mode1Lit = true;
    firstColor();
  }

  for (int i = 0; i < 8; i++) { //read toggle buttons only
    int thisButton = buttonStates[i];
    if (thisButton == 1 && i != 3 && i != 7) {
      mode1Buttons[i] = !mode1Buttons[i];
      if (mode1Buttons[i]) {
        usbMIDI.sendControlChange(i, 127, 1);
      }
      else {
        usbMIDI.sendControlChange(i, 0, 1);
      }
    }

    if (thisButton == 1 && i == 7) {//mode button
      mode = 2;
      mode1Lit = false;
      Serial.println("pushed");
    }

    if (thisButton == 1 && i == 3) {//mode button
      mode = 3;
      mode1Lit = false;
      Serial.println("3");

    }
  }

  for (int i = 0; i < 4; i++) {//read potentiometers 
    int thisPot = potStates[i];
    if (abs(thisPot - mode1Pots[i]) > mode1PotTol) {
      usbMIDI.sendControlChange(i + 8, thisPot, 1);
      mode1Pots[i] = thisPot;
    }
  }
}

void firstColor() {//sets colors for buttons 
  if (mode1Lit == true) {
    strip.setPixelColor(0, 0, 255, 0);
    strip.setPixelColor(1, 255, 0, 0);
    strip.setPixelColor(2, 255, 0, 0);
    strip.setPixelColor(3, 255, 0, 0);;
    strip.setPixelColor(4, 0, 0, 255);
    strip.setPixelColor(5, 255, 0, 0);
    strip.setPixelColor(6, 255, 0, 0);
    strip.setPixelColor(7, 255, 0, 0);;
  }
  strip.show();

}
