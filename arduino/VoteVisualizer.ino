// VoteVisualization 
//
// Author: sven.mentl@gmail.com 
// Released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

// Digital I/O Pin connected to Data In of the NeoPixel Ring 
#define PIN            13

// Number of NeoPixels
#define NUMPIXELS      24

// Configuration of NeoPixels
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Constants 
const uint32_t RED = pixels.Color(255, 0, 0);
const uint32_t GREEN = pixels.Color(0, 255, 0);
const uint32_t BLUE = pixels.Color(0, 0, 255);
const uint32_t OFF = pixels.Color(0, 0, 0);
const int START_SEQUENCE_BLINK_DELAY = 200;

void setup() {

  // Setup the serial connection
  Serial.begin(9600);  
  
  // Initialize the NeoPixel library
  pixels.begin(); 
  
  // Display the start sequence to show that the right code is loaded and that the arduino is ready to be used
  startSequence();
}

void loop() {
  
  // Blocking call
  if (Serial.available() > 0) {
    
    // A value between 0 and 1 is expected on the serial line. 
    // The value expresses the ratio of positive votes in relation to all votes.
    float ratio = Serial.parseFloat();
    if(ratio < 0 || ratio > 1) return;
    
    int numberOfGreens = (ratio * 24)+0.5;
    lightFirstXInGreenRestInRed(numberOfGreens);
  }
}

void lightFirstXInGreenRestInRed(int numberOfGreens){

  for(int i=0; i<numberOfGreens; i++){
   pixels.setPixelColor(i, GREEN); 
  } 
  for(int i=0+numberOfGreens; i<NUMPIXELS; i++){
   pixels.setPixelColor(i, RED); 
  }
  pixels.show(); 
}

void startSequence(){
 for(int j=0; j<10; j++){
   lightAllLeds(BLUE); 
   delay(START_SEQUENCE_BLINK_DELAY);
   lightAllLeds(OFF); 
   delay(START_SEQUENCE_BLINK_DELAY);
 } 
}

void lightAllLeds(uint32_t color) {
 for(int i=0; i<NUMPIXELS; i++){
   pixels.setPixelColor(i, color); 
  } 
  pixels.show();
}
  
  
