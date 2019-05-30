class Menu {

  private:
    int blinktime = 25;
    int blinktime_ = 5;
    int blinkTime = blinktime;
    int blinkTime_ = blinktime_;
    int previous_diff;
    int previous_choice;

    boolean change = false;

  public:
    void choice_diff(int diff) {
      if (previous_diff != diff) {
        blinktime = blinkTime;
        blinktime_ = blinkTime_;
      }
      previous_diff = diff;
      display.clearDisplay();
      display.setCursor(9, 8);
      display.setTextSize(1);
      display.println("Difficulty:");
      display.println();
      if (diff == 1) {
        symblink();
        display.println(" Easy");
        display.println("  Medium");
        display.println("  Hard");
      }
      else if (diff == 2) {
        display.println("  Easy");
        symblink();
        display.println(" Medium");
        display.println("  Hard");
      }
      else {
        display.println("  Easy");
        display.println("  Medium");
        symblink();
        display.println(" Hard");
      }
    }

    void startmenu(int choice) {
      if (previous_choice != choice) {
        blinktime = blinkTime;
        blinktime_ = blinkTime_;
      }
      previous_choice = choice;
      display.clearDisplay();
      display.setCursor(19, 0);
      display.setTextSize(2);
      display.write(27);
      display.write(24);
      display.write(25);
      display.write(26);
      display.println();
      display.setTextSize(1);
      display.println();
      if (choice == 1) {
        symblink();
        display.println(" Start");
        display.println("  Difficulty");
        display.println("  Exit");
      }
      else if (choice == 2) {
        display.println("  Start");
        symblink();
        display.println(" Difficulty");
        display.println("  Exit");
      }
      else {
        display.println("  Start");
        display.println("  Difficulty");
        symblink();
        display.println(" Exit");
      }
    }

    void pausemenu(int choice) {
      if (previous_choice != choice) {
        blinktime = blinkTime;
        blinktime_ = blinkTime_;
      }
      previous_choice = choice;
      display.clearDisplay();
      display.setCursor(13, 0);
      display.setTextSize(2);
      display.println("Pause");
      display.setTextSize(1);
      display.println();
      if (choice == 1) {
        symblink();
        display.println(" Back");
        display.println("  Difficulty");
        display.println("  Exit");
      }
      else if (choice == 2) {
        display.println("  Back");
        symblink();
        display.println(" Difficulty");
        display.println("  Exit");
      }
      else {
        display.println("  Back");
        display.println("  Difficulty");
        symblink();
        display.println(" Exit");
      }
    }

    void symblink() {
      if (blinktime_ == 0 && blinktime == 0) {
        blinktime = blinkTime;
        blinktime_ = blinkTime_;
      }
      if (blinktime > 0) {
        display.write(16);
        blinktime--;
      }
      else if (blinktime_ > 0) {
        display.print(" ");
        blinktime_--;
      }
    }

    void setprevious_diff(int prev) {
      previous_diff = prev;
    }

    void setprevious_choice(int prev) {
      previous_choice = prev;
    }

};
