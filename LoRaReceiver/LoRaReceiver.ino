#include <TimerOne.h>

#include <SPI.h>
#include <LoRa.h>

boolean data = 0;

void timerIsr() {
  data = 0;
}

void setup() {
  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);
  Timer1.initialize(100000);
  Timer1.attachInterrupt(timerIsr);
  
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
      data = 1;
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }

  if(data == 1) {
    digitalWrite(6, LOW);
    delay(500);
  }
  else {
    digitalWrite(6, HIGH);
  }
  
}
