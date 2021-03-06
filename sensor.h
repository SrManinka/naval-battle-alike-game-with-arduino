#ifndef sensor_h
#define sensor_h

#include <Arduino.h>
#include <IRremote.h>//para receber dados do controle remoto


//Simple value definition
#define right 1
#define left -1
#define ok 5
#define save 6
#define numLed 5//number of leds

//Ir controller Button definition

#define irleft1 1972149634
#define irleft2 3772819033
#define irright1 3772819033
#define irright2 1400905448
#define irok1 2331063592
#define irok2 3772782313
#define irsave1 4105841032
#define irsave2 2024805451

//type of controller definition

#define joystick 3
#define controller 4 // ir controller

#define sensordoor A0 



class sensor {
  private:
    int door;
    int type; //3= joystick 4= infra red controller
    long int value;  // value recived from sensor
    decode_results result;
  public:
    sensor(int d, int t);
    void begin();
    void setDoor(int n);
    void setType(int n);
    int getType();
    int getDoor();

    int read();


};
#endif
