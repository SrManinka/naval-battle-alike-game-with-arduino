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
            case 1972149634:
            case 3772819033:
              return left;

            case 3772794553:
            case 1400905448:
              return right;

            case 2331063592:
            case 3772782313:
              return ok;

            case 4105841032:
            case 2024805451:
              return save;

            default:
              return 0;
          }

      }
      return value;
    }
