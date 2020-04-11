#ifndef game_h
#define game_h


#include "lamp.h"
#ifndef reciver
#include "sensor.h"
#endif
#include "button.h"

#define numLed 5

#define player1 0
#define player2 1
//door entrance definition

#define sensordoor A4 //A4 em decimal
#define gameButton 8

void begin(lamp l[numLed]);
void start(lamp l[numLed], bool *player);

int turn(int side, int  pos) ;//verify the side the player is trying to turn and check if its ok

int detectorValue();

int readButton();

int getValue();

void select(int n, lamp l[numLed]);//select a lamp

void resetLamps(lamp l[numLed]) ;//reset a lamps

int numOnLed(lamp l[numLed]);//verify the number of led that is on

void saveGame(lamp l[numLed], lamp l2[numLed], int *ledOn, bool *player) ; //save the game

int compairNum(lamp l[numLed],int ledOn) ;//verify if the number of lamps on are the same, higher or smaller than the storage on

int compairPos(lamp l[numLed], lamp l2[numLed]);//verify how many lamps are inm the right position 

bool compairRes(lamp l[numLed], lamp l2[numLed]);// verify if game is over

bool checkEnd(lamp l[numLed], lamp l2[numLed],int ledOn); //verify if game is over, if not, show compairPos e comparNum

void showGame(lamp l[numLed], int pos); //show the lamps
#endif
