#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

//CLK --- Pin 2
//DIN --- Pin 4
//D/C --- Pin 5
//CS  --- Pin 6
//RST --- Pin 7

Adafruit_PCD8544 display = Adafruit_PCD8544(2, 4, 5, 6, 7);

#include "Startgame.h"
#include "Light.h"
#include "Buttons.h"
#include "Displaygame.h"
#include "Menu.h"
#include "Rand.h"

Startgame start;
Light light;
Buttons buttons;
Displaygame displaygame;
Menu menu;
Rand randgame;

#define BUTTON_M 13 // 13
#define BUTTON_D 12 // 12
#define BUTTON_U 11 // 11
#define BUTTON_L 10 // 10
#define BUTTON_R 9 // 9

int LIGHT_PIN = 3;

int difficulty = 2;
int prev_diff = difficulty;
int menu_choice = 1;

boolean startgame = true;
boolean startmenu_on = false;
boolean pausemenu_on = false;
boolean diffmenu_on = false;
boolean go = false;
boolean startrand = false;
boolean show = false;
boolean check_button = false;
boolean win = false;
boolean gameover = false;
boolean start_menu;
boolean b_up;
boolean b_down;
boolean b_left;
boolean b_right;
boolean b_middle;

void setup() {
  display.begin();
  display.setContrast(35); // 35
  display.clearDisplay();
  display.display();

  randomSeed(analogRead(0));

  pinMode(LIGHT_PIN, OUTPUT);
  digitalWrite(LIGHT_PIN, LOW);

  pinMode(BUTTON_D, INPUT_PULLUP);
  pinMode(BUTTON_U, INPUT_PULLUP);
  pinMode(BUTTON_L, INPUT_PULLUP);
  pinMode(BUTTON_R, INPUT_PULLUP);
  pinMode(BUTTON_M, INPUT_PULLUP);

  menu.setprevious_diff(difficulty);
  menu.setprevious_choice(menu_choice);
}

void restart_setting() {
  difficulty = 2;
  prev_diff = difficulty;
  menu_choice = 1;
  startgame = true;
  startmenu_on = false;
  pausemenu_on = false;
  diffmenu_on = false;
  go = false;
  startrand = false;
  show = false;
  check_button = false;
  win = false;
  gameover = false;
}

void loop() {
  buttons.up_button(BUTTON_U);
  buttons.down_button(BUTTON_D);
  buttons.left_button(BUTTON_L);
  buttons.right_button(BUTTON_R);
  buttons.middle_button(BUTTON_M);
  b_up = buttons.get_b_up();
  b_down = buttons.get_b_down();
  b_left = buttons.get_b_left();
  b_right = buttons.get_b_right();
  b_middle = buttons.get_b_middle();
  /////
  if (startgame) {
    start.startdisplay();
    light.startlight(LIGHT_PIN);
    if (b_up || b_down || b_left || b_right || b_middle) {
      startgame = false;
      digitalWrite(LIGHT_PIN, LOW);
      startmenu_on = true;
    }
  }
  /////
  else if (startmenu_on) {
    menu.startmenu(menu_choice);
    if (b_middle) {
      if (menu_choice == 1) {
        go = true;
        startmenu_on = false;
      }
      else if (menu_choice == 2) {
        diffmenu_on = true;
        startmenu_on = false;
        start_menu = true;
      }
      else {
        restart_setting();
        displaygame.restart();
        light.restart();
      }
    }
    else if (b_down) {
      menu_choice++;
      if (menu_choice > 3) menu_choice = 1;
    }
    else if (b_up) {
      menu_choice--;
      if (menu_choice < 1) menu_choice = 3;
    }
  }
  /////
  else if (diffmenu_on) {
    menu.choice_diff(difficulty);
    if (b_middle) {
      if (prev_diff == difficulty){
        if(start_menu){
          startmenu_on = true;
        }
        else pausemenu_on = true;
      }
      else {
        startmenu_on = true;
        displaygame.restart();
        menu_choice = 1;
      }
      prev_diff = difficulty;
      diffmenu_on = false;
    }
    else if (b_down) {
      difficulty++;
      if (difficulty > 3) difficulty = 1;
    }
    else if (b_up) {
      difficulty--;
      if (difficulty < 1) difficulty = 3;
    }
  }
  /////
  else if (win) {
    light.startlight(LIGHT_PIN);
    display.clearDisplay();
    display.setTextSize(3);
    display.setCursor(16, 13);
    display.println("WIN");
    if (b_middle) {
      startmenu_on = true;
      win = false;
      menu_choice = 1;
      digitalWrite(LIGHT_PIN, LOW);
    }
  }
  /////
  else if (gameover) {
    light.startlight(LIGHT_PIN);
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(19, 8);
    display.println("GAME");
    display.setCursor(19, 24);
    display.println("OVER");
    if (b_middle) {
      startmenu_on = true;
      gameover = false;
      menu_choice = 1;
      digitalWrite(LIGHT_PIN, LOW);
    }
  }
  /////
  else if (!pausemenu_on && b_middle) {
    digitalWrite(LIGHT_PIN, LOW);
    pausemenu_on = true;
  }
  else if (pausemenu_on) {
    menu.pausemenu(menu_choice);
    if (b_middle) {
      if (menu_choice == 1) {
        pausemenu_on = false;
      }
      else if (menu_choice == 2) {
        diffmenu_on = true;
        pausemenu_on = false;
        start_menu = false;
      }
      else {
        restart_setting();
        displaygame.restart();
        light.restart();
      }
    }
    else if (b_down) {
      menu_choice++;
      if (menu_choice > 3) menu_choice = 1;
    }
    else if (b_up) {
      menu_choice--;
      if (menu_choice < 1) menu_choice = 3;
    }
  }
  /////
  else if (go) {
    displaygame.gogame(LIGHT_PIN);
    go = !displaygame.statusdispstartgame();
    if (!go) {
      startrand = true;
      randgame.restartrand();
      digitalWrite(LIGHT_PIN, LOW);
    }
  }
  /////
  else if (startrand) {
    randgame.startrand(difficulty);
    startrand = randgame.statusrand();
    if (!startrand) {
      show = true;
      randgame.restartrand();
    }
  }
  /////
  else if (show) {
    randgame.randshow(difficulty);
    show = randgame.statusshow();
    if (!show) {
      check_button = true;
      randgame.restartrand();
      display.clearDisplay();
    }
  }
  /////
  else if (check_button) {
    check_button = randgame.statuscheck();
    win = randgame.statuswin();
    gameover = randgame.statusgameover();
    if (b_up) {
      randgame.checkrand(difficulty, 2);
    }
    else if (b_down) {
      randgame.checkrand(difficulty, 3);
    }
    else if (b_left) {
      randgame.checkrand(difficulty, 1);
    }
    else if (b_right) {
      randgame.checkrand(difficulty, 4);
    }
    randgame.dispcheckrand();
    if (!check_button) {
      randgame.restartrand();
      light.restart();
      displaygame.restarttimes();
      displaygame.restart();
    }
  }
  display.display();
}
