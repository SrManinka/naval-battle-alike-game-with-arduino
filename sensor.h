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

//type of controller definition
#define potentiometer 1
#define ultrasonic 2
#define joystick 3
#define controller 4 // ir controller



class sensor {
  private:
    int door;
    int type; //1 = potenciometro padrao 2= ultrasonico 3 = potenciometro joystick 4= controle if
    long int value;  // value recebido do sensor
    decode_results result;
  public:
    sensor(int d, int t);
    void begin();
    void setDoor(int n);
    void setType(int n);
    int getType();
    int getValor();

    int read();


};
#endif
