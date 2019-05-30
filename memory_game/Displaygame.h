class Displaygame {

  private:
    int disppause = 10;
    int startdisppause = disppause;
    int disppause2 = startdisppause * 2;
    int times = 3;
    int starttimes = times;
    boolean stopdispstartgame;

  public:
    void gogame(int LIGHT_PIN) {
      if (!stopdispstartgame) {
        display.clearDisplay();
        display.setCursor(28, 10);
        display.setTextSize(4);
        if (disppause > 0) {
          disppause--;
          disppause2 = startdisppause * 2;
          display.println();
          analogWrite(LIGHT_PIN, 150);
        }
        else if (times == 3 && disppause2 > 0) {
          disppause2--;
          display.println("3");
          analogWrite(LIGHT_PIN, LOW);
        }
        else if (times == 2 && disppause2 > 0) {
          disppause2--;
          display.println("2");
          analogWrite(LIGHT_PIN, LOW);
        }
        else if (times == 1 && disppause2 > 0) {
          disppause2--;
          display.println("1");
          analogWrite(LIGHT_PIN, LOW);
        }
        else if (disppause2 == 0) {
          disppause = startdisppause;
          times--;
        }
        else if (times == 0) {
          stopdispstartgame = true;
          times = starttimes;
        }
      }
    }

    void restarttimes() {
      times = 3;
    }

    int statusdispstartgame() {
      return stopdispstartgame;
    }
    
    void restart() {
      disppause = startdisppause;
      disppause2 = startdisppause * 2;
      times = starttimes;
      stopdispstartgame = false;
    }
};
