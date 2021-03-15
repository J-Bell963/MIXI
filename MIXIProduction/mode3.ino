//mode 3
boolean mode3Lit = false;
boolean mode3Buttons[] = {false, false, false, false, false, false};
int mode3Pots[] = {0, 0, 0, 0};
int mode3PotTol = 5;

void mode3() {
  if (!mode3Lit) {
    mode3Lit = true;
    thirdColor();
  }

  for (int i = 0; i < 8; i++) {//read toggles buttons only 
    int thisButton = buttonStates[i];
    if (buttonStates[i] == 1 && i != 3 && i != 7) {
      mode3Buttons[i] = !mode3Buttons[i];
      if (mode1Buttons[i]) {
        usbMIDI.sendControlChange(i + 40, 127, 1);
      }
      else {
        usbMIDI.sendControlChange(i + 40, 0, 1);
      }
    }

    if (buttonStates[i] == 1 && i == 7) {//mode change 
      mode = 1;
      mode3Lit = false;
    }

    if (thisButton == 1 && i == 3) {//mode change 
      mode = 2;
      mode3Lit = false;
            Serial.println("pushed");

    }
  }

  for (int i = 0; i < 4; i++) {//read potentiometers 
    int thisPot = potStates[i];
    if (abs(thisPot - mode3Pots[i]) > mode3PotTol) {
      usbMIDI.sendControlChange(i + 48, thisPot, 1);
      mode3Pots[i] = thisPot;
    }
  }
}

void thirdColor() {//sets button colors
  if (mode3Lit == true) {
    strip.setPixelColor(0, 255, 0, 0);
    strip.setPixelColor(1, 0, 0, 255);
    strip.setPixelColor(2, 0, 0, 255);
    strip.setPixelColor(3, 0, 0, 255);;
    strip.setPixelColor(4, 0, 255, 0);
    strip.setPixelColor(5, 0, 0, 255);
    strip.setPixelColor(6, 0, 0, 255);
    strip.setPixelColor(7, 0, 0, 255);;
  }
  strip.show();
}
