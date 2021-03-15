void startUp() { //warm up opening 
  colorWipe(strip.Color(255,   0,   0), 100);
  strip.setBrightness(50);
  mode = 1;
}

void colorWipe(uint32_t color, int wait) {
  for (int j = 0; j < 10; j++) { // run 10 loop times
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, color);
      strip.show();
      delay(wait);
    }
    strip.clear();
    strip.show();
    wait = wait - 10;
  }
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();

  }
  delay(1000);//stay on for 1 second

  //fade opening out into mode 1
  int x = 50;
  for (int a = 0; a < 50; a++){
  for (int z = 50; z > 0; z--) {
    strip.setBrightness(x);
    strip.show();
  }
  x = x - 1;
  }
}
