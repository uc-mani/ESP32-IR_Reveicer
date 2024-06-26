#include <Arduino.h>
#include <IRremote.h>

#define RECEIVER_PIN 5
IRrecv receiver(RECEIVER_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  pinMode(22,OUTPUT);
  receiver.enableIRIn();

}

void loop() {
  if(receiver.decode(&results)){
    Serial.println(results.value,HEX);

    //SUN HEATER REMOTE
    //if "ON/OFF" button is pressed, LED OFF
    if(results.value == 0XA32AB931){
      digitalWrite(22,LOW);
    }
      
    //if "LIGHT" button is pressed, LED ON
    if(results.value == 0x4EA240AE){
      digitalWrite(22,HIGH);
    }

    receiver.resume();//to re-enable IR receiver again to start listening.
  }
}