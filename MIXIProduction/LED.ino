void initLEDs() {
  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(i, 255, 0, 255);
    strip.setBrightness(50);
    strip.show();
    delay(50);
  }
}
