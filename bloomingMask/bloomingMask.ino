// C++ code
//Blooming Mask Coding
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(8, 6);
uint32_t RED = strip.Color(200, 0, 0);
uint32_t WHITE = strip.Color(200, 200, 200);
uint32_t GREEN = strip.Color(0, 200, 0);

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
strip.fill(RED);//alternate between red and pink
    strip.show();
  }
  else{
    strip.clear();
    strip.fill (GREEN);// and blue
    strip.show();
  }
}