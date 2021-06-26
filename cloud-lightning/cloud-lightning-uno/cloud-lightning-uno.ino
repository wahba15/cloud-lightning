
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip)
int NUM_LEDS = 4;
int ledPins[]={3,5,6,9};

const int HIGH_STRIKE_LIKELIHOOD = 5;
const int LOW_STRIKE_LIKELIHOOD = 10;
int currentDataPoint = 0;
int chance = LOW_STRIKE_LIKELIHOOD;

// Simple moving average plot
int NUM_Y_VALUES = 17;

float yValues[] = {
  0,
  7,
  10,
  9,
  7.1,
  7.5,
  7.4,
  12,
  15,
  10,
  0,
  3,
  3.5,
  4,
  1,
  7,
  1
};

int loop_reset=0;
float simple_moving_average_previous = 0;
float random_moving_average_previous = 0;

float (*functionPtrs[10])(); //the array of function pointers
int NUM_FUNCTIONS = 2;

void setup() {
Serial.begin(9600);
  for (int i = 0; i < NUM_LEDS; i++) {
  pinMode(ledPins[i], OUTPUT);
  }

  // initializes the array of function pointers.
  functionPtrs[0] = simple_moving_average;
  functionPtrs[1] = random_moving_average;
}

void loop() {
  loop_reset++;
  if (true) {
//    if (random(chance) == 3) {
    
    int led = ledPins[random(NUM_LEDS)];
    for (int i = 0; i < 10; i++) {
      // Use this line to keep the lightning focused in one LED.
      // lightningStrike(led):
      // Use this line if you want the lightning to spread out among multiple LEDs.
      lightningStrike(ledPins[random(NUM_LEDS)]);
      Serial.println("Lightning");
    }
    // Once there's been one strike, I make it more likely that there will be a second.
    Serial.println("Lightning Done");
    chance = HIGH_STRIKE_LIKELIHOOD;
  } else {
    chance = LOW_STRIKE_LIKELIHOOD;
  }
  turnAllPixelsOff();
  if (loop_reset>NUM_Y_VALUES)  {
    loop_reset=0;
    currentDataPoint = 0;
    simple_moving_average_previous = 0;
    random_moving_average_previous = 0;
    Serial.println("Reset");
  }
  delay(1000);
  Serial.println("Delay Done");
}

void turnAllPixelsOff() {
  for (int i = 0; i < NUM_LEDS; i++) {
    analogWrite(ledPins[i], 0);
  }
}

void lightningStrike(int pixel) {
  float brightness = callFunction(random(NUM_FUNCTIONS));
  float scaledWhite = abs(brightness*250);
//  Serial.println(brightness);

  analogWrite(pixel, scaledWhite);
  
  delay(random(5, 100));
  currentDataPoint++;
  currentDataPoint = currentDataPoint%NUM_Y_VALUES;
}


float callFunction(int index) {
  return (*functionPtrs[index])(); //calls the function at the index of `index` in the array
}

// https://en.wikipedia.org/wiki/Moving_average#Simple_moving_average
float simple_moving_average() {
  uint32_t startingValue = currentDataPoint;
  uint32_t endingValue = (currentDataPoint+1)%NUM_Y_VALUES;
  float simple_moving_average_current = simple_moving_average_previous + 
                                  (yValues[startingValue])/NUM_Y_VALUES - 
                                  (yValues[endingValue])/NUM_Y_VALUES;

  simple_moving_average_previous = simple_moving_average_current;
  return simple_moving_average_current;
}


// Same as simple moving average, but with randomly-generated data points.
float random_moving_average() {
  float firstValue = random(1, 10);
  float secondValue = random(1, 10);
  float random_moving_average_current = random_moving_average_previous +
                                  firstValue/NUM_Y_VALUES -
                                  secondValue/NUM_Y_VALUES;
  random_moving_average_previous = random_moving_average_current;

  return random_moving_average_current;
}
