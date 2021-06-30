//Initializing LED Pin
int led_pin1 = 6;
int led_pin2 = 5;
int led_pin3 = 3;
int led_pin4 = 9;
void setup() {
  //Declaring LED pin as output
  for (int i = 2; i < 14; i++) {
    pinMode(i, OUTPUT);
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
  //Fading the LED
    for (int j = 2; j < 14; j++) {
      analogWrite(j, 255);
      delay(1000);
      analogWrite(j, 0);
    }
}
