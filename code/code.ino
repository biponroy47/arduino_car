#include <IRremote.h>
int IR_RECEIVE_PIN = 11;
IRrecv irrecv(IR_RECEIVE_PIN);

int m1 = 3;
int m1a = 4;
int m1b = 2;

int m2 = 6;
int m2a = A1;
int m2b = 9;

int m3 = 5;
int m3a = 8;
int m3b = 7;

int m4 = 10;
int m4a = 13;
int m4b = 12;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(m1, OUTPUT);
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m3a, OUTPUT);
  pinMode(m3b, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(m4a, OUTPUT);
  pinMode(m4b, OUTPUT);
}

void loop() {
  if (irrecv.decode()) {
    //UP
    if (irrecv.decodedIRData.decodedRawData == 3108437760) {
      Serial.print("FORWARD");
      digitalWrite(m1, HIGH);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2, HIGH);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);
      digitalWrite(m3, HIGH);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, HIGH);
      digitalWrite(m4, HIGH);
      digitalWrite(m4a, HIGH);
      digitalWrite(m4b, LOW);
    } 
    //LEFT
    else if (irrecv.decodedIRData.decodedRawData == 3141861120) {
      Serial.print("LEFT");
      digitalWrite(m1, HIGH);
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2, HIGH);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);
      digitalWrite(m3, HIGH);
      digitalWrite(m3a, HIGH);
      digitalWrite(m3b, LOW);
      digitalWrite(m4, HIGH);
      digitalWrite(m4a, HIGH);
      digitalWrite(m4b, LOW);
    } 
    //RIGHT
    else if (irrecv.decodedIRData.decodedRawData == 3158572800) {
      Serial.print("RIGHT");
      digitalWrite(m1, HIGH);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);
      digitalWrite(m3, HIGH);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, HIGH);
      digitalWrite(m4, HIGH);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, HIGH);
    } 
    //DOWN
    else if (irrecv.decodedIRData.decodedRawData == 3927310080) {
      Serial.print("FORWARD");
      digitalWrite(m1, HIGH);
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);
      digitalWrite(m3, HIGH);
      digitalWrite(m3a, HIGH);
      digitalWrite(m3b, LOW);
      digitalWrite(m4, HIGH);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, HIGH);
    } 
    //MIDDLE
    else if (irrecv.decodedIRData.decodedRawData == 3208707840) {
      Serial.println("STOP");
      digitalWrite(m1, LOW);
      digitalWrite(m2, LOW);
      digitalWrite(m3, LOW);
      digitalWrite(m4, LOW);
    }
    else {
      Serial.println(irrecv.decodedIRData.decodedRawData);
    }
    delay(200);
  }
  irrecv.resume();
}
