/**
 * Control Realtek RX2 (RX2 -G) RC Receiver with Arduino
 *
 * @author Mircea Diaconescu, Octomber 28, 2013
 * @source https://github.com/dimircea/
 * GPL v3 License
 *   
 * Many cheap RC toys are based on TX2 / RX2 transmitter / receiver ICs.
 * This Arduino sketch allows to replace the TX2 based Remote Control with Arduino.
 * Just one single pin is used from the Arduino board.
 *   
 * Connect Arduino pin 10 to the solder point where the toy antenna is connected or to the toy antenna cable.
 * One can replace pin 10 with other free digital pin available on the Arduino board.
 *
 * TX-2B/RX-2B datasheet: http://www.datasheetarchive.com/dl/Datasheet-035/DSA0017137.pdf
 */

/** Functions (aka W1) - as defined by the IC datasheet */
#define COMMAND_ENDCODE         4
#define COMMAND_FORWARD        10
#define COMMAND_FORWARD_TURBO  16
#define COMMAND_TURBO          22
#define COMMAND_FORWARD_LEFT   28
#define COMMAND_FORWARD_RIGHT  34
#define COMMAND_BACKWARD       40
#define COMMAND_BACKWARD_RIGHT 46
#define COMMAND_BACKWARD_LEFT  52
#define COMMAND_LEFT           58
#define COMMAND_RIGHT          64

//output pins
#define ANTENNA_PIN     10

/** Initialize the Arduino data and pin */
void setup() {
  pinMode( ANTENNA_PIN, OUTPUT);
}

/** Loop code */
void loop() {
  // add here your commands to control the RX2 module...
  // for test purposes, here a continuous forward command is sent
  sendCommand( COMMAND_FORWARD);
}

/** Send command to the RX2 IC */
void sendCommand( int command) {
  int w1 = 0, w2 = 0;
  
  /** start code sequence 4 x W2, ~625Hz, Duty Cycle 75% */ 
  for ( w2 = 0; w2 < 4; w2++) {
    digitalWrite( ANTENNA_PIN, HIGH);
    delayMicroseconds( 1200);
    digitalWrite( ANTENNA_PIN, LOW);
    delayMicroseconds( 400);
  }
  
  /** function code sequence, n x W1, ~1.25KHz, Duty Cycle 50% */
  for ( w1 = 0; w1 < command; w1++) {
    digitalWrite( ANTENNA_PIN, HIGH);
    delayMicroseconds( 400);
    digitalWrite( ANTENNA_PIN, LOW);
    delayMicroseconds( 400);
  }
}