#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>

#include "LedControl.h"
//#include "binary.h"

/*
 DIN connects to pin 12
 CLK connects to pin 11
 CS connects to pin 10 
*/

LedControl lc=LedControl(A6,A7,A5,1);


unsigned long delaytime=100;
int cnt=0;
bool rightButtonPressed;

// happy face
byte hf[8]= {B00111100,B01000010,B10100101,B10000001,B10100101,B10011001,B01000010,B00111100};
// neutral face
byte nf[8]={B00111100, B01000010,B10100101,B10000001,B10111101,B10000001,B01000010,B00111100};
// sad face
byte sf[8]= {B00111100,B01000010,B10100101,B10000001,B10011001,B10100101,B01000010,B00111100};

 byte trp1[8]= 
{
  B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00000000
};
byte trp2[8]=
{
  B00000000,
  B00000000,
  B00111100,
  B00100100,
  B00100100,
  B00111100,
  B00000000,
  B00000000
};
byte trp3[8]=
{
  B00000000,
  B01111110,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B01111110,
  B00000000
};
byte trp4[8]=
{
  B11111111,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B11111111
};
byte trp5[8]=
{
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};
//const int IMAGES_LEN = sizeof(trp)/8;


void setup() {

  Serial.begin(9600);
 pinMode(CPLAY_LEFTBUTTON, INPUT_PULLDOWN);
 pinMode(CPLAY_RIGHTBUTTON, INPUT_PULLDOWN);
  lc.shutdown(0,false);
  // Set brightness to a medium value
  lc.setIntensity(0,8);
  // Clear the display
  lc.clearDisplay(0);  
}

void drawFaces(){
 
  if (digitalRead(CPLAY_LEFTBUTTON)==HIGH) {
    cnt=cnt+1;

   Serial.print(cnt);
  
  }

    if(cnt==1)
    {
  // Display sad face
  lc.setRow(0,0,sf[0]);
  lc.setRow(0,1,sf[1]);
  lc.setRow(0,2,sf[2]);
  lc.setRow(0,3,sf[3]);
  lc.setRow(0,4,sf[4]);
  lc.setRow(0,5,sf[5]);
  lc.setRow(0,6,sf[6]);
  lc.setRow(0,7,sf[7]);
  }

  
 if(cnt==2)
 { 
  // Display neutral face
  lc.setRow(0,0,nf[0]);
  lc.setRow(0,1,nf[1]);
  lc.setRow(0,2,nf[2]);
  lc.setRow(0,3,nf[3]);
  lc.setRow(0,4,nf[4]);
  lc.setRow(0,5,nf[5]);
  lc.setRow(0,6,nf[6]);
  lc.setRow(0,7,nf[7]);
 }

//  
//  // Display happy face
 if(cnt==3)
 {
 cnt=0;
  lc.setRow(0,0,hf[0]);
  lc.setRow(0,1,hf[1]);
  lc.setRow(0,2,hf[2]);
  lc.setRow(0,3,hf[3]);
  lc.setRow(0,4,hf[4]);
  lc.setRow(0,5,hf[5]);
  lc.setRow(0,6,hf[6]);
  lc.setRow(0,7,hf[7]);
//  delay(delaytime);
 }
 if (digitalRead(CPLAY_RIGHTBUTTON)==HIGH)
 
 {
  cnt=0;
  lc.setRow(0,0,trp1[0]);
  lc.setRow(0,1,trp1[1]);
  lc.setRow(0,2,trp1[2]);
  lc.setRow(0,3,trp1[3]);
  lc.setRow(0,4,trp1[4]);
  lc.setRow(0,5,trp1[5]);
  lc.setRow(0,6,trp1[6]);
  lc.setRow(0,7,trp1[7]);
  delay(delaytime);

  lc.setRow(0,0,trp2[0]);
  lc.setRow(0,1,trp2[1]);
  lc.setRow(0,2,trp2[2]);
  lc.setRow(0,3,trp2[3]);
  lc.setRow(0,4,trp2[4]);
  lc.setRow(0,5,trp2[5]);
  lc.setRow(0,6,trp2[6]);
  lc.setRow(0,7,trp2[7]);
  delay(delaytime);

  lc.setRow(0,0,trp3[0]);
  lc.setRow(0,1,trp3[1]);
  lc.setRow(0,2,trp3[2]);
  lc.setRow(0,3,trp3[3]);
  lc.setRow(0,4,trp3[4]);
  lc.setRow(0,5,trp3[5]);
  lc.setRow(0,6,trp3[6]);
  lc.setRow(0,7,trp3[7]);
  delay(delaytime);

  lc.setRow(0,0,trp4[0]);
  lc.setRow(0,1,trp4[1]);
  lc.setRow(0,2,trp4[2]);
  lc.setRow(0,3,trp4[3]);
  lc.setRow(0,4,trp4[4]);
  lc.setRow(0,5,trp4[5]);
  lc.setRow(0,6,trp4[6]);
  lc.setRow(0,7,trp4[7]);
  delay(delaytime);

  lc.setRow(0,0,trp5[0]);
  lc.setRow(0,1,trp5[1]);
  lc.setRow(0,2,trp5[2]);
  lc.setRow(0,3,trp5[3]);
  lc.setRow(0,4,trp5[4]);
  lc.setRow(0,5,trp5[5]);
  lc.setRow(0,6,trp5[6]);
  lc.setRow(0,7,trp5[7]);
  delay(delaytime);
 }
//  

//  else{
//    lc.clearDisplay(0);  
//  }
//  
//  delay(delaytime);
}
//
void loop(){
//   rightButtonPressed = CircuitPlayground.rightButton();
  drawFaces();

//  int sensorVal = digitalRead(CPLAY_LEFTBUTTON); 
}
