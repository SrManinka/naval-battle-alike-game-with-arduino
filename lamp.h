#ifndef lamp_h

#define lamp_h



class lamp {
  private:
    int door;// fisical door
    bool state = false; //on and off
  public:

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

    void changeState() { //alternate between on and off
      state = !state;
      digitalWrite(door, state);
    }

    void blink() {
      int intensity;
      if (state)
        intensity = 900;
      else {
        intensity = 150;
      }
      for (int j = 0; j < 100; j++) {
        digitalWrite(door, HIGH);
        delayMicroseconds(intensity); // Approximately 10% duty cycle @ 1KHz
        digitalWrite(door, LOW);
        delayMicroseconds(1000 - intensity);
        delay(1);
      }

      digitalWrite(door, LOW);
      delay(100);
    }


};
#endif
