class Light {

  private:
    int startpause = 100;
    int speedLigth = 2;
    int brighter = 200;
    int startBrighter = brighter;
    int darker = 0;
    int startDarker = darker;

  public:
    void startlight(int pin) {
      if (startpause > 0) {
        analogWrite(pin, 0);
        startpause--;
      }
      else if (darker <= (startBrighter + speedLigth - 1)) {
        analogWrite(pin, darker);
        darker = darker + speedLigth;
      }
      else if (brighter >= (startDarker - speedLigth + 1)) {
        analogWrite(pin, brighter);
        brighter = brighter - speedLigth;
      }
      else {
        brighter = startBrighter;
        darker = startDarker;
      }
    }

    void restart() {
      brighter = startBrighter;
      darker = startDarker;
    }

};
