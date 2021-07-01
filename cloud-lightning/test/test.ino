//Initializing LED Pin
int led_pin1 = 6;
int led_pin2 = 5;
int led_pin3 = 3;
int led_pin4 = 9;
void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

  //Declaring LED pin as output
  for (int i = 2; i < 14; i++) {
    pinMode(i, OUTPUT);
    analogWrite(i, 255);
  }

}
//void loop() {
//  //Fading the LED
//  for (int i = 0; i < 255; i++) {
//    for (int j = 2; j < 14; j++) {
//      analogWrite(j, i);
//    }
//
//    delay(5);
//  }
//  for (int i = 255; i > 0; i--) {
//    for (int j = 2; j < 14; j++) {
//      analogWrite(j, i);
//    }
//    delay(5);
//  }
//}

void loop() {
    for (int i = 2; i < 14; i++) {
    
    analogWrite(i, 255);
  }
delay(1000);
}

//int incomingByte = 0; // for incoming serial data
//
//void loop() {
//  if (Serial.available() > 0) {
//    incomingByte = Serial.parseInt();
//    analogWrite(incomingByte, 255);
//    delay(2000);
//    analogWrite(incomingByte, 0);
//  }
//}
