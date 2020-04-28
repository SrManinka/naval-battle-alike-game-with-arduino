#include "sensor.h"

IRrecv reciver(sensordoor);

    sensor::sensor(int d , int t){ // constructor
      door = d;
      type = t;
    }

    void sensor::begin(){
      reciver.enableIRIn(); 
    }
    void sensor::setDoor(int n) {
      door = n;
      IRrecv reciver(door);
    }
    void sensor::setType(int n) {
      type = n;
    }
    sensor::getType() {
      return type;
    }
    sensor::getDoor() {
      return door;
    }

    sensor::read() {
        value= 0;
      if (type == controller) {

        if ( reciver.decode(&result)) {
          value = result.value;
          reciver.resume();
        }
      } else
        value = analogRead(door);
      switch (type)  {

        case joystick:  //Joystick
          if (value <= 300) //left
            return left;
          if (value >= 700) //right
            return right;
          return 0;//center


        case controller:
          switch (value) {//values from ir controller
            case irleft1:
            case irleft2:
              return left;

            case irright1:
            case irright2:
              return right;

            case irok1:
            case irok2:
              return ok;

            case irsave1:
            case irsave2:
              return save;

            default:
              return 0;
          }

      }
      return value;
    }
