I've just started looking at the teensie 4.0

It has 14 analog pins, but 4 of them are on the rear of the board, not accessed via holes.

![Teensy Rear Side](./teensy40_pinout2.png)

I'm going to want access to pins 24-27.

There is a discussion of how to do this here:
https://forum.pjrc.com/threads/59817-Teensy-4-0-accesing-24-to-33-pines?highlight=pogo

I have ordered https://www.sparkfun.com/products/13925 this pin header set via ebay.


In the mean time I want to research two components:

KY-024 Hall Effect breakout.

https://arduinomodules.info/ky-024-linear-magnetic-hall-module/

Wired up to the nano using 3v power. Using arduino serial plot. The flat side of the package seems to be where you want to position the magnet for best reading/range.

These seem really easy, so I've ordered a stack of these. Need to think about a 3d holder.

KY-016 RGB Full Colour LED.

https://arduinomodules.info/ky-016-rgb-full-color-led-module/

Teensie Midi

https://www.pjrc.com/teensy/td_libs_MIDI.html

MIDI uses the hardware serial ports to communicate with standard MIDI devices at 31250 baud.
This page documents ordinary serial MIDI which uses round 5-pin DIN connectors.
You can use Serial.print() to observe what your program is doing, while using MIDI, or USB MIDI.

MIDI input requires an optically isolated input. Output requires only 2 resistors. This schematic is recommended for Teensy 4.x & 3.x & LC:

![Midi Circuit](./td_libs_MIDI_sch_t3.png)

When connecting the signals on the 5 pin DIN connectors, be sure to connect to the correct pins.

![Midi Wiring](./td_libs_MIDI_2.jpg)


So, let's see if I understand this:

![Teensy Front Side](./teensy40_pinout1.png)

47 ohm resistors

GND wire to pin 2 
Pin 1 is TX1 via 50ohm resistor to send - pin 5 on DIN
3.3V wire via 50ohm resistor to pin 4 (positive)

I've arranged the 3 pin headers in an L-shape
[1][2]
   [3]

[1] = rx/1 din pin 5 orange
[2] = 3.3v din pin 4 green
[3] = gnd  din pin 2 yellow

[orange][green ]
        [yellow]