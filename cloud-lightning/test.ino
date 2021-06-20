//Initializing LED Pin
int led_pin1 = 6;
int led_pin2 = 5;
int led_pin3 = 3;
int led_pin4 = 9;
void setup() {
  //Declaring LED pin as output
  pinMode(led_pin1, OUTPUT);
  pinMode(led_pin2, OUTPUT);
  pinMode(led_pin3, OUTPUT);
  pinMode(led_pin4, OUTPUT);
}
void loop() {
  //Fading the LED
  for(int i=0; i<255; i++){
    analogWrite(led_pin1, i);
    analogWrite(led_pin2, i);
    analogWrite(led_pin3, i);
    analogWrite(led_pin4, i);
    delay(5);
  }
  for(int i=255; i>0; i--){
    analogWrite(led_pin1, i);
    analogWrite(led_pin2, i);
    analogWrite(led_pin3, i);
    analogWrite(led_pin4, i);
    delay(5);
  }
}
