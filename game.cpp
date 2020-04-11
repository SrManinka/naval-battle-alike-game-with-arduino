#include "game.h"

sensor detector(sensordoor,joystick); //controller that will be used
button gameB(gameButton);//a game button

int lampdoor[] ={ 3, 5,6,9,10};
void begin(lamp l[numLed]) { 
  int i;
  detector.begin();

  for (i = 0; i < numLed; i++) {
    l[i].setDoor(lampdoor[i]); //hooks a door for this led
    pinMode(l[i].getDoor(), INPUT); //and inform its an output
  }
  pinMode(gameButton, INPUT_PULLUP);
}

void start(lamp l[numLed], bool *player) {
  
  Serial.println("***iniciando um novo jogo***"); 
  resetLamps(l);
  *player = player1;

}


int detectorValue() {
  return detector.read();
}

int readButton(){
    return gameB.getBotao();
  }

int getValue(){
    int value = detectorValue();
    if(!value){ //if there is no value from detector, it gets button value
    int val =readButton();
    if(val){
      if( val==1)
        value = ok;
        
      if(val==2)
        value = save;

    }
  }
  return (value);
}
int turn(int side, int  pos) { //verify the side the player is trying to turn and check if its ok
  if ((pos - 1 >= 0) and ( side == left)) {
    pos --;
  }
  if ((pos + 1 <= 4) and ( side == right)) {
    pos ++;
  }
  return pos;

}

void select(int n, lamp l[numLed]) { //select a lamp
  l[n].mudaState();

}

void resetLamps(lamp l[numLed]) { //reset a lamps
  int i;
  for (i = 0; i < numLed; i++)
    l[i].off();
}

int numOnLed(lamp l[numLed]) { //verify the number of led that is on
  int i, cont;
  cont = 0;
  for (i = 0; i < numLed; i++) {
    if (l[i].state == true) {
      ++cont;
    }
  }
  return cont;
}

void saveGame(lamp l[numLed], lamp l2[numLed], int *ledOn, bool *player) { //save the game
  int i;
  Serial.println("bezusca");
  for (i = 0; i < numLed; i++) {
    l2[i].setDoor(l[i].getDoor()) ;
    l2[i].setState(l[i].getState());
    //l[i].blink();
    delay(200);
  }
  *ledOn = numOnLed(l);
  resetLamps(l);
  *player = player2;
}

int compairNum(lamp l[numLed], int ledOn) { //verify if the number of lamps on are the same, higher or smaller than the storage on
  int atualN = numOnLed(l);//the actual number of lamps that are on

  if (atualN < ledOn)
    return 1; 
  if (atualN == ledOn) 
    return 2;
  return 3; 
}

int compairPos(lamp l[numLed], lamp l2[numLed]) { //verify how many lamps are inm the right position 
  int i;
  int cont = 0;
  for (i = 0; i < numLed; i++) {
    if ((l[i].state == l2[i].state) and (l[i].state == true)) {
      ++cont;
    }
  }
  return cont;
}

bool compairRes(lamp l[numLed], lamp l2[numLed]) { // verify if game is over
  int i;
  for (i = 0; i < numLed; i++) {
    if (l[i].state != l2[i].state)
      return false;
  }
  return true;

}

bool checkEnd(lamp l[numLed], lamp l2[numLed], int ledOn) { //verify if game is over, if not, show compairPos e comparNum
  if (compairRes(l, l2))
    return true;
  Serial.print("O numero de luzes acesas e ");
  switch (compairNum(l, ledOn)) {
    case 1:
      Serial.print("menor que o ");
      break;
    case 2:
      Serial.print("igual ao ");
      break;
    case 3:
      Serial.print("maior que o ");
      break;
  }
  Serial.println("salvo!");
  Serial.print("o numero de posicoes certas e "); Serial.print(compairPos(l, l2)); Serial.println("!!");
  delay(300);
  Serial.println();Serial.println();Serial.println();Serial.println();//skip some lines
  return false;
}

void showGame(lamp l[numLed], int pos) { //show the lamps
  int i;
  for (i = 0; i < numLed; i++) {
    if (l[i].state == true) {

      l[i].on();
    } else {
      l[i].off();
    }
  }
}
