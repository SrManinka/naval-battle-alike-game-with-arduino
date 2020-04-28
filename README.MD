# How does this game work?

It's a two players game. The first one has to chose one or more ligths(none is acepted as well) and save it. After that, the other player has to guess wich lights were on. If our second player don't guess it right, two things will apear in your serial monitor. How many lights are right and if there are more or less guesses right. If it's alright, It's over and will wait the save button to be pressed.

## You need 

*  Arduino IDE

* To download [Ir sensor](https://github.com/z3t0/Arduino-IRremote) and [buzzer.h](https://github.com/z3t0/Arduino-IRremote) library and [this](https://gist.github.com/mikeputnam/2820675) file 
* [buzzersong.h](https://github.com/SrManinka/buzzer-song-maker) and [buzzerMelody.h](https://github.com/SrManinka/buzzer-melody) for sound effects
* A [Ir sensor reciver](https://www.ebay.com/c/678749978) or a [Joystick](https://www.ebay.com/itm/Arduino-Compatible-Analogue-Joystick-Controller/130949215082).

## Usage
There are two ways:

* **Ir controller** (standard)

    First, you'll have to find out your Ir Controller code. To do so, you may follow [this tutorial](https://forum.arduino.cc/index.php?topic=83044.0). Then set then into **sensor.h ir controller definition** .

![dwe](https://i.imgur.com/ApNCRZm.png)

* **Joystick**

    Search **sensor detector(sensordoor, controller)** at main.cpp  and switch controller to joystick. To turn left or right... I don't know if 
    i have to tell you. To select a LED, just press your controller button. If you want to save, press it 1 second .
    ![dwe](https://i.imgur.com/57erg4M.png)


## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

