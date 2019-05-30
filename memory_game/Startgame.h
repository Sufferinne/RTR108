class Startgame {

  private:


  public:
    void startdisplay() {
      display.clearDisplay();
      display.setCursor(7, 7);
      display.setTextSize(2);
      display.println("Memory");
      display.setCursor(19, 27);
      display.println("Game");
      display.display();
    }

};
