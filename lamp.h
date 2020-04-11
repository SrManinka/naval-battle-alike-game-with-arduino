#ifndef lamp_h

#include <Arduino.h>

#define lamp_h
#define HIGH 1
#define LOW 0


class lamp {
  public:
    int door;//door que estara conectado
    bool state = false; //aceso e apagado

    void setDoor(int n) {
      door = n;
    }

    void setState(int n) {
      state = n;
    }

    int getDoor() {
      return door;
    }

    int getState() {
      return state;
    }


    void on() {
      state = true;
      digitalWrite(door, HIGH);
    }

    void off() {
      state = false;
      digitalWrite(door, LOW);
    }

    void mudaState() { //altera entre 1 e 0
      state = !state;
      digitalWrite(door, state);
    }

    void blink() {
      int intensity;
      if(state)
        intensity =150;
      else
        intensity = 30;
      analogWrite(door, intensity);
      delay (150);
      analogWrite(door, LOW);
      delay(150);
    }
    void glowLess(){

      analogWrite(door, 10);
      delay(100);
    }

};
#endif
