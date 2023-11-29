// C++ code
//Blooming Mask Coding
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(12, 6);

int mPin=10;
int mVal;

float noMotion = 0;
float motion = 1;

void setup()
{
  Serial.begin(9600);
 pinMode(mPin,INPUT);
  strip.begin();
  strip.clear();
  strip.show();
}

void loop()
{
  mVal=digitalRead(mPin);
  Serial.println(mVal);
  
  if (mVal < motion){
    strip.clear();
  for(int i=0; i<strip.numPixels();i+=2){
    strip.setPixelColor(i,144, 238, 144); //green
  }
  
  for (int i=1; i<strip.numPixels(); i+=2){
    strip.setPixelColor(i,243, 207, 198); //pink

  }
  strip.show(); 
  }
  else{
    strip.clear();
   for(int i=0; i<strip.numPixels();i+=2){
    strip.setPixelColor(i,65,105,225); //blue
  }
  
  for (int i=1; i<strip.numPixels(); i+=2){
    strip.setPixelColor(i,93, 63, 211); //purple

  }
  strip.show(); 
  }
}
