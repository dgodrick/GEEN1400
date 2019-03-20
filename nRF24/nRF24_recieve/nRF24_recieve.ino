#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

#define ledPin 2

RF24 radio(9,10);
const byte address[6]="01100";
void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
    
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  
  radio.openReadingPipe(0,address);
  radio.startListening();
}

void loop() {
  if(radio.available()){
    byte dataIn=0;
    radio.read(&dataIn,sizeof(dataIn));
    Serial.println(dataIn);
    digitalWrite(ledPin,dataIn);
    }

}
