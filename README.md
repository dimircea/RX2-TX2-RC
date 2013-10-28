RX2-TX2-RC
==========

Control Realtek RX2 (RX2 -G) RC Receiver with Arduino.

Many cheap RC toys are based on TX2 / RX2 transmitter / receiver ICs.
This Arduino sketch allows to replace the TX2 based Remote Control with Arduino.
Just one single pin is used from the Arduino board.

Connect Arduino pin 10 to the solder point where the toy antenna is connected or to the toy antenna cable.
One can replace pin 10 with other free digital pin available on the Arduino board.

TX-2B/RX-2B datasheet: http://www.datasheetarchive.com/dl/Datasheet-035/DSA0017137.pdf

NOTE: RX2 (-G) is pin and command compatible with RX-2B.
