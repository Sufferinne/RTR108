class Buttons {

  private:
    boolean interrupts_U = false;
    boolean interrupts_D = false;
    boolean interrupts_L = false;
    boolean interrupts_R = false;
    boolean interrupts_M = false;
    boolean times_U = false;
    boolean times_D = false;
    boolean times_L = false;
    boolean times_R = false;
    boolean times_M = false;
    boolean clicked_U = false;
    boolean clicked_D = false;
    boolean clicked_L = false;
    boolean clicked_R = false;
    boolean clicked_M = false;

  public:
    void up_button(int pin_U) {
      int knock_U = digitalRead(pin_U);
      if (knock_U == 0) {
        if (!times_U) {
          times_U = true;
          clicked_U = 1;
        }
        else {
          clicked_U = 0;
        }
        interrupts_U = true;

      }
      else if (interrupts_U == true) {
        interrupts_U = false;
        times_U = false;
      }
    }

    void down_button(int pin_D) {
      int knock_D = digitalRead(pin_D);
      if (knock_D == 0) {
        if (!times_D) {
          times_D = true;
          clicked_D = 1;
        }
        else {
          clicked_D = 0;
        }
        interrupts_D = true;

      }
      else if (interrupts_D == true) {
        interrupts_D = false;
        times_D = false;
      }
    }

    void left_button(int pin_L) {
      int knock_L = digitalRead(pin_L);
      if (knock_L == 0) {
        if (!times_L) {
          times_L = true;
          clicked_L = 1;
        }
        else {
          clicked_L = 0;
        }
        interrupts_L = true;

      }
      else if (interrupts_L == true) {
        interrupts_L = false;
        times_L = false;
      }
    }

    void right_button(int pin_R) {
      int knock_R = digitalRead(pin_R);
      if (knock_R == 0) {
        if (!times_R) {
          times_R = true;
          clicked_R = 1;
        }
        else {
          clicked_R = 0;
        }
        interrupts_R = true;

      }
      else if (interrupts_R == true) {
        interrupts_R = false;
        times_R = false;
      }
    }

    void middle_button(int pin_M) {
      int knock_M = digitalRead(pin_M);
      if (knock_M == 0) {
        if (!times_M) {
          times_M = true;
          clicked_M = 1;
        }
        else {
          clicked_M = 0;
        }
        interrupts_M = true;

      }
      else if (interrupts_M == true) {
        interrupts_M = false;
        times_M = false;
      }
    }

    int get_b_up() {
      return clicked_U;
    }
    
    int get_b_down() {
      return clicked_D;
    }

    int get_b_left() {
      return clicked_L;
    }

    int get_b_right() {
      return clicked_R;
    }

    int get_b_middle() {
      return clicked_M;
    }
};
