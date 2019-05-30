class Rand {

  private:
    int easy = 4;
    int medium = 8;
    int hard = 12;
    int times;
    int rand_number[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int prev_rand_number;
    int number = 0;
    int timeshow = 100;
    int starttimeshow = timeshow;
    int showpause = 20;
    int startshowpause = showpause;

    boolean first_time = true;
    boolean status_rand = true;
    boolean status_show = true;
    boolean status_check = true;
    boolean status_win = false;
    boolean status_gameover = false;

  public:
    void startrand(int diff) {
      firsttimerand(diff);
      if (times == 0) {
        status_rand = false;
      }
      else if (times > 0) {
        rand_number[number] = random(1, 5);
        if (number == 0) {
          number++;
        }
        else if (rand_number[number - 1] != rand_number[number]) {
          number++;
          times --;
        }
      }
    }

    void randshow(int diff) {
      firsttimerand(diff);
      if (number == times) {
        status_show = false;
      }
      else if (number < times && timeshow > 0) {
        timeshow--;
        display.clearDisplay();
        display.setTextSize(7);
        if (rand_number[number] == 1) {
          display.setCursor(24, -1);
          display.write(27);
        }
        else if (rand_number[number] == 2) {
          display.setCursor(24, -4);
          display.write(24);
        }
        else if (rand_number[number] == 3) {
          display.setCursor(24, -4);
          display.write(25);
        }
        else if (rand_number[number] == 4) {
          display.setCursor(24, -1);
          display.write(26);
        }
      }
      else if (timeshow == 0 && showpause > 0) {
        showpause--;
        display.clearDisplay();
      }
      else if (timeshow == 0 && showpause == 0) {
        timeshow = starttimeshow;
        showpause = startshowpause;
        number++;
      }
    }

    void checkrand(int diff, int gamebutton) {
      firsttimerand(diff);
      display.clearDisplay();
      if (number == times - 1) {
        status_check = false;
        status_win = true;
      }
      else if (number < times && gamebutton == rand_number[number]) {
        number++;
      }
      else if (number < times && gamebutton != rand_number[number]) {
        status_check = false;
        status_gameover = true;
      }
    }

    void dispcheckrand () {
      display.clearDisplay();
      display.setTextSize(7);
      if (number != 0) {
        if (rand_number[number - 1] == 1) {
          display.setCursor(24, -1);
          display.write(27);
        }
        else if (rand_number[number - 1] == 2) {
          display.setCursor(24, -4);
          display.write(24);
        }
        else if (rand_number[number - 1] == 3) {
          display.setCursor(24, -4);
          display.write(25);
        }
        else if (rand_number[number - 1] == 4) {
          display.setCursor(24, -1);
          display.write(26);
        }
      }
    }

    void restartrand() {
      first_time = true;
      status_rand = true;
      status_show = true;
      status_check = true;
      status_win = false;
      status_gameover = false;
      number = 0;
    }

    void firsttimerand(int diff) {
      if (first_time == true) {
        if (diff == 1) {
          times = easy;
        }
        else if (diff == 2) {
          times = medium;
        }
        else {
          times = hard;
        }
        first_time = false;
      }
    }

    int statusrand() {
      return status_rand;
    }

    int statusshow() {
      return status_show;
    }

    int statuscheck() {
      return status_check;
    }

    int statuswin() {
      return status_win;
    }

    int statusgameover() {
      return status_gameover;
    }
};
