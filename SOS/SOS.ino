/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
  
  modified 8 Sep 2016
  by Colby Newman

  Modified by Darko - S O Sas in Morse code.
*/

int led = 13;

const int BASE = 100;
const int SHORT_BLINK = BASE;
const int SHORT_DELAY = BASE;
const int LONG_BLINK = BASE * 2;
const int LONG_DELAY = BASE * 2;
const int CYCLE_DELAY = BASE * 2;
 
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  S();
  O();
  S();
  pause();
}

void S() {
  short_blink();
  short_blink();
  short_blink();
}

void O() {
  long_blink();
  long_blink();
  long_blink();
}

void pause() {
  cycle_delay();
}

void short_blink(){
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led, HIGH);
  delay(SHORT_BLINK);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(led, LOW);
  delay(SHORT_DELAY);
}

void long_blink() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led, HIGH);
  delay(LONG_BLINK);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(led, LOW);
  delay(LONG_DELAY);
}

void cycle_delay() {
  delay(CYCLE_DELAY);
}

