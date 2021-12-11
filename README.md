# ESP32-Flysky-Bluetooth-Bridge
Expose FlySky Receiver as Bluetooth Gamepad / Joystick

Inspired by [BillyNate / ESP32IBUStoBLEgamepad](https://github.com/BillyNate/ESP32IBUStoBLEgamepad) and this version using PlatformIo

What is this?
===
Using ESP32 to emulate a Bluetooth Gamepad / Joystick using inputs from a Flysky Receiver (tested on fs-i6ab) using IBUS.  

The goal is to use a FlySky transmitter (e.g. Nirvana) with [PicaSim](http://www.rowlhouse.co.uk/PicaSim/) running on Android or Ubuntu (under Wine)

How do I use this?
===

This project was created under [PlatformIO](https://platformio.org/) running as on Visual Studio code.  So first step is to install PlatformIo.

Next you will need an ESP32 development board - I used a Wemos Lolin32, but any ESP32 board will work as long as it exposes UART1 or UART2.  The code in this repo is based on using UART2.

To connect the Flysky receiver, you will need to connect 3 wires:

```
ESP                  Flysky (i6ab - servo port)
---                  -------
GND    -----------   GND
3.3V   -----------   Power             
GPIO16 -----------   Signal
```

The Wemos Lolin came without header pins soldered, so I soldered a servo lead as described above.

NB!!!  Don't power the receiver using 5V - it WILL fry the ESP32!!!  The receiver is powered by 3.3V from the ESP, so no extra power supply or battery is needed.

Now, clone this repo and flash it to the ESP32, you will need to pair the laptop or Android device for Bluetooth.  

Extras
====

This project uses two libraries (specified in platformio.ini)

* 	lemmingdev/ESP32-BLE-Gamepad@^0.3.4
*   bmellink/IBusBM@^1.1.4





