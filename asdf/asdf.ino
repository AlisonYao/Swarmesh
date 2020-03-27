#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 64
#define DELAY 200
#define RUN_COLOR Purple
#define DIRECTION_COLOR Red
#define RADAR_COLOR Blue
#define DATA_PIN 25

#define PWMA 27
#define DIRA 14
#define PWMB 12
#define DIRB 13
#define MUXI 34
#define MUXA 5
#define MUXB 18
#define MUXC 19
#define PULSE 312


CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  pinMode( MUXI, INPUT);
  pinMode( MUXA, OUTPUT);
  pinMode( MUXB, OUTPUT);
  pinMode( MUXC, OUTPUT);
  pinMode( PWMB, OUTPUT);
  pinMode( DIRB, OUTPUT);
  pinMode( DIRA, OUTPUT);
  pinMode( PWMA, OUTPUT);
}

int n = 0;
float brightness = 50;
int state = 1;
float IR_intensity = 0;
int distance = 15;
int moving_direction = 0; // going forward

// 0 is IR comes from the front/forward direcion 
// for each 45 degrees +1
int IR_reception_direction = 0;



void loop() {
  // you can comment out the line below when the set_brightness function is done
  // it's just I'm going blind
  LEDS.setBrightness(brightness);
//  state = set_state()

  if (state == 0){
    if (moving_direction == 0) { forward(); }
  }

  else if (state == 1){
    if ( distance > 30) { distance_0(); }
    else if ( distance > 20 && distance <= 30) {
      distance_1();
//      IR_reception_direction = set_IR_direction()
      if (IR_reception_direction == 0){ show_direction_1_0();}
      else if (IR_reception_direction == 1){ show_direction_1_1();}
      else if (IR_reception_direction == 2){ show_direction_1_2();}
      else if (IR_reception_direction == 3){ show_direction_1_3();}
      else if (IR_reception_direction == 4){ show_direction_1_4();}
      else if (IR_reception_direction == 5){ show_direction_1_5();}
      else if (IR_reception_direction == 6){ show_direction_1_6();}
      else if (IR_reception_direction == 7){ show_direction_1_7();}
      }
    else if ( distance > 10 && distance <= 20) {
      distance_2();
      if (IR_reception_direction == 0){ show_direction_2_0();}
      else if (IR_reception_direction == 1){ show_direction_2_1();}
      else if (IR_reception_direction == 2){ show_direction_2_2();}
      else if (IR_reception_direction == 3){ show_direction_2_3();}
      else if (IR_reception_direction == 4){ show_direction_2_4();}
      else if (IR_reception_direction == 5){ show_direction_2_5();}
      else if (IR_reception_direction == 6){ show_direction_2_6();}
      else if (IR_reception_direction == 7){ show_direction_2_7();}
      }
    else if ( distance >= 0 && distance <= 10) {
      distance_3();
      if (IR_reception_direction == 0){ show_direction_3_0();}
      else if (IR_reception_direction == 1){ show_direction_3_1();}
      else if (IR_reception_direction == 2){ show_direction_3_2();}
      else if (IR_reception_direction == 3){ show_direction_3_3();}
      else if (IR_reception_direction == 4){ show_direction_3_4();}
      else if (IR_reception_direction == 5){ show_direction_3_5();}
      else if (IR_reception_direction == 6){ show_direction_3_6();}
      else if (IR_reception_direction == 7){ show_direction_3_7();}
      }
    
  }
//  state = (state + 1) % 2;
//distance = (distance + 10) % 40;
}


int set_state(){
  // ???????? no idea what to write
}


// probably need to be fixed bc we don't have the readings yet
//float set_brightness(){
////  int brightness = analogRead(0)
//  brightness = map(brightness, 0, 4056, 0, 255);
//  return brightness;
//}


int set_IR_direction(){
//  ?????
}



void forward(){
// Turn the LED on, then pause
  leds[59] = CRGB::RUN_COLOR;
  FastLED.show();
  delay(DELAY);
  leds[52] = CRGB::RUN_COLOR;
  FastLED.show();
  delay(DELAY);
  leds[43] = CRGB::RUN_COLOR;
  FastLED.show();
  delay(DELAY);
  leds[36] = CRGB::RUN_COLOR;
  FastLED.show();
  delay(DELAY);
  leds[27] = CRGB::RUN_COLOR;
  FastLED.show();
  delay(DELAY);
  leds[20] = CRGB::RUN_COLOR;
  FastLED.show();
  delay(DELAY);
  leds[11] = CRGB::RUN_COLOR;
  FastLED.show();
  delay(DELAY);
  leds[4] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY + 500);
//Now turn the LED off, then pause
  leds[59] = CRGB::Black;
  leds[52] = CRGB::Black;
  leds[43] = CRGB::Black;
  leds[36] = CRGB::Black;
  leds[27] = CRGB::Black;
  leds[20] = CRGB::Black;
  leds[11] = CRGB::Black;
  leds[4] = CRGB::Black;
  FastLED.show();
//  FastLED.show();
  delay(DELAY);
}



void distance_0(){
  while (n <= 63){
    leds[n] = CRGB::Black;
    n++;
  }
  FastLED.show();
  delay(DELAY);
  n = 0;
}


void distance_1(){
  leds[36] = CRGB::RADAR_COLOR;
  leds[27] = CRGB::RADAR_COLOR;
  leds[35] = CRGB::RADAR_COLOR;
  leds[28] = CRGB::RADAR_COLOR;
  FastLED.show();
  delay(DELAY);
}


void distance_2(){
  leds[36] = CRGB::RADAR_COLOR;
  leds[27] = CRGB::RADAR_COLOR;
  leds[35] = CRGB::RADAR_COLOR;
  leds[28] = CRGB::RADAR_COLOR;
  leds[42] = CRGB::RADAR_COLOR;
  leds[43] = CRGB::RADAR_COLOR;
  leds[44] = CRGB::RADAR_COLOR;
  leds[45] = CRGB::RADAR_COLOR;
  leds[34] = CRGB::RADAR_COLOR;
  leds[29] = CRGB::RADAR_COLOR;
  leds[18] = CRGB::RADAR_COLOR;
  leds[19] = CRGB::RADAR_COLOR;
  leds[20] = CRGB::RADAR_COLOR;
  leds[21] = CRGB::RADAR_COLOR;
  leds[26] = CRGB::RADAR_COLOR;
  leds[37] = CRGB::RADAR_COLOR;
  FastLED.show();
  delay(DELAY);
}


void distance_3(){
  leds[36] = CRGB::RADAR_COLOR;
  leds[27] = CRGB::RADAR_COLOR;
  leds[35] = CRGB::RADAR_COLOR;
  leds[28] = CRGB::RADAR_COLOR;
  leds[42] = CRGB::RADAR_COLOR;
  leds[43] = CRGB::RADAR_COLOR;
  leds[44] = CRGB::RADAR_COLOR;
  leds[45] = CRGB::RADAR_COLOR;
  leds[34] = CRGB::RADAR_COLOR;
  leds[29] = CRGB::RADAR_COLOR;
  leds[18] = CRGB::RADAR_COLOR;
  leds[19] = CRGB::RADAR_COLOR;
  leds[20] = CRGB::RADAR_COLOR;
  leds[21] = CRGB::RADAR_COLOR;
  leds[26] = CRGB::RADAR_COLOR;
  leds[37] = CRGB::RADAR_COLOR;
  leds[54] = CRGB::RADAR_COLOR;
  leds[53] = CRGB::RADAR_COLOR;
  leds[52] = CRGB::RADAR_COLOR;
  leds[51] = CRGB::RADAR_COLOR;
  leds[50] = CRGB::RADAR_COLOR;
  leds[49] = CRGB::RADAR_COLOR;
  leds[46] = CRGB::RADAR_COLOR;
  leds[33] = CRGB::RADAR_COLOR;
  leds[30] = CRGB::RADAR_COLOR;
  leds[17] = CRGB::RADAR_COLOR;
  leds[14] = CRGB::RADAR_COLOR;
  leds[13] = CRGB::RADAR_COLOR;
  leds[12] = CRGB::RADAR_COLOR;
  leds[11] = CRGB::RADAR_COLOR;
  leds[10] = CRGB::RADAR_COLOR;
  leds[9] = CRGB::RADAR_COLOR;
  leds[22] = CRGB::RADAR_COLOR;
  leds[25] = CRGB::RADAR_COLOR;
  leds[38] = CRGB::RADAR_COLOR;
  leds[41] = CRGB::RADAR_COLOR;
  FastLED.show();
  delay(DELAY);
}


void show_direction_1_0(){
  leds[20] = CRGB::DIRECTION_COLOR;
  leds[19] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}


void show_direction_1_1(){
  leds[21] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}


void show_direction_1_2(){
  leds[37] = CRGB::DIRECTION_COLOR;
  leds[26] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}


void show_direction_1_3(){
  leds[42] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}


void show_direction_1_4(){
  leds[43] = CRGB::DIRECTION_COLOR;
  leds[44] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}


void show_direction_1_5(){
  leds[45] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}

void show_direction_1_6(){
  leds[34] = CRGB::DIRECTION_COLOR;
  leds[29] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}


void show_direction_1_7(){
  leds[18] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}


void show_direction_2_0(){
  leds[11] = CRGB::DIRECTION_COLOR;
  leds[12] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}

void show_direction_2_1(){
  leds[9] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}

void show_direction_2_2(){
  leds[38] = CRGB::DIRECTION_COLOR;
  leds[25] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}


void show_direction_2_3(){
  leds[54] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}

void show_direction_2_4(){
  leds[52] = CRGB::DIRECTION_COLOR;
  leds[51] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}

void show_direction_2_5(){
  leds[49] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}

void show_direction_2_6(){
  leds[33] = CRGB::DIRECTION_COLOR;
  leds[30] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}

void show_direction_2_7(){
  leds[14] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}

void show_direction_3_0(){
  leds[4] = CRGB::DIRECTION_COLOR;
  leds[3] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}

void show_direction_3_1(){
  leds[7] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}

void show_direction_3_2(){
  leds[39] = CRGB::DIRECTION_COLOR;
  leds[24] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}

void show_direction_3_3(){
  leds[56] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}

void show_direction_3_4(){
  leds[60] = CRGB::DIRECTION_COLOR;
  leds[59] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}

void show_direction_3_5(){
  leds[63] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}

void show_direction_3_6(){
  leds[32] = CRGB::DIRECTION_COLOR;
  leds[31] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}

void show_direction_3_7(){
  leds[0] = CRGB::DIRECTION_COLOR;
  FastLED.show();
  delay(DELAY);
}
