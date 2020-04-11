#ifndef button_h
#define button_h

#define savetime 2000

class button {
  private:
    int door;
    bool activate;
    int t;

  public:
    button(int d) {
      door = d;
    }

    void setDoor(int n) {
      door = n;
    }

    int getClick() { //verifica clique simples

      if (digitalRead(door)) // se o button nao estiver sido pressionado
      {
        return 0;
      } else {

        while (!digitalRead(door)) {}
        Serial.println("bazinga");
        return 1;
      }
    };

    int getBotao() { // diz se o button foi pressionado e se durou algo proximo de 3s

      while (digitalRead(door) == LOW) {
        t++;
        delay(1);
        if (t > 3000) {
          t = 0;
          return 2;
        }
      }

      if (t > 100) {
        t = 0;
        return 1;
      }
      t = 0;
      return 0;

    }

};
#endif
