

#include "game.h"//game functions
#include "buzzer.h" //buzzer class
#include "melody.h" //melody defaults

int onLed; // number of led that are on
int position = 0; //position of the led that is selected
int value, lastValue;
bool player;//player1 is the one to save the game and player2 will try

buzzer mario(marioMelody, marioTime, marioNotes);
buzzer coin (coinMelody, coinTime, coinNotes);
buzzer pacman(pacManMelody, pacManTime, pacManNotes);

lamp led[numLed];//values that will be changed frequently
lamp ledSaved[numLed];//values of the saved led package

void setup() {
  Serial.begin(9600);
  begin(led);
  start(led, &player);

}

void loop() {
value = getValue();

  if (value < ok) {//select position
    position = turn(value, position);  
  }
  led[position].blink();

  if (value == ok) {
    select(position, led);
    //if (player) {
      coin.play();
    // }
  }

  if (value == save ) { //if save button is pressed
    if (player == player1) {
      saveGame(led, ledSaved, &onLed, &player); //save the game so player 2 can try
      pacman.play();//play pacman's song

    } else { //caso nao

      if (checkEnd(led, ledSaved, onLed)) { //if player 2 is right
        Serial.println("******Parabens!******");
        mario.play();// play a mario's song
        while (getValue() != save) {} //wait till save button is pressed
        resetLamps(ledSaved);
        delay(1500);//made this to avoid a stupid error
        start(led, &player); //start a new game
      }
    }
 
  }
  showGame(led, position);

}
