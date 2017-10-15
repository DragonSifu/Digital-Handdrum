/******************************************************************************
  Digital Handpan Code for Teesny 
  Joel Bartlett @ SparkFun Electronics
  Original Creation Date: October 16, 2016
  
  This sketch produces polyphonic notes when any number of eight capacitive touch pads are 
  touched, thus replicating a Handpan (or Hang) steel drum. This sketch 
  makes use of the Teensy Audio Shield (https://www.sparkfun.com/products/12767)
  as well as the Teensy Audio System Design Tool (http://www.pjrc.com/teensy/gui/).
  All capactive touch sensing is handled by the Teensy's built in Touch Sense Pins. 
  
  Hardware:
    Teensy 3.2 Dev Board (https://www.sparkfun.com/products/13736)
    Teensy Audio Board (https://www.sparkfun.com/products/12767)
    Various buttons and potentiometers 

  Development environment specifics:
    IDE: Arduino IDE V 1.6.11 with the Teensyduino Add-on installed V Teensy Loader V1.30

  This code is beerware; if you see me (or any other SparkFun
  employee) at the local, and you've found our code helpful,
  please buy us a round!
  Distributed as-is; no warranty is given.
*******************************************************************************/
//These libraries are included by the Teensy Audio System Design Tool 
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
//#include <SD.h>//not using the SD library at this time
#include <SerialFlash.h>
#include <Bounce.h>

#include "note_frequency.h"
#include "scales.h"
AudioEffectDelayExternal delayExt1(AUDIO_MEMORY_CY15B104,6000);      //xy=1092,172

#include "TeensyAudioDesignTool.h"
#define SDCARD_MOSI_PIN  7
#define SDCARD_SCK_PIN   14

//an array to define each of the eight touch sense pins, 
//all other touch sense pins are used by the Teensy Audio Shield (16,17,18,19)
int pinTouch[] = {33,32,25,17,16,15,1,0};

int scale_index = 0;//var to keep track fo which scale is being used
#define FLANGE_DELAY_LENGTH (5*AUDIO_BLOCK_SAMPLES)
// Allocate the delay lines for left and right channels
short l_delayline[FLANGE_DELAY_LENGTH];
int s_idx = FLANGE_DELAY_LENGTH/4;
int s_depth = FLANGE_DELAY_LENGTH/4;
double s_freq = .25;

int n_chorus = 3;

int dcVal = 0;//value to control the decay of each note 
int fbval = 0;//value to control the decay of each note 
int shift = 0;//value to control the decay of each note 
float fBack = 1;//value to control the decay of each note 

//buttons for incrementing or decrementing through each scale
Bounce button0 = Bounce(2, 15);
Bounce button1 = Bounce(3, 15);    

bool debug =1;//Set to 1 for Serial debugging 

////////////////////////////////////////////////////////
void setup() 
{
  //initialize buttons
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  button0.update();
  button1.update();
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(24, OUTPUT);
//  digitalWrite(4, HIGH);
//  digitalWrite(5, HIGH);
//  digitalWrite(8, HIGH);
  //initialize Serial
  Serial.begin(115200);
  flange1.begin(l_delayline,FLANGE_DELAY_LENGTH,s_idx,s_depth,s_freq);
  flange1.voices(s_idx,s_depth,s_freq);

  //set aside audio memory 
  AudioMemory(128);
        SPI.setMOSI(SDCARD_MOSI_PIN);
        SPI.setSCK(SDCARD_SCK_PIN);

  //initialize audio settings

  //initialize volume
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.8);
  //enable line out for troubleshooting on O-scope
  //sgtl5000_1.unmuteLineout();
  filter1.resonance(2);
  filter2.resonance(2);
  filter3.resonance(2);
  filter4.resonance(2);
  filter1.frequency(110);
  filter2.frequency(220);
  filter3.frequency(440);
  filter4.frequency(880);
  filter1.octaveControl(2);
  filter2.octaveControl(2);
  filter3.octaveControl(2);
  filter4.octaveControl(2);
// biquad1.setLowpass(0,440,0.7);
//  biquad1.setLowpass(1,660,0.7);
//  biquad1.setLowpass(2,880,0.7);
//  biquad1.setLowpass(3,1000,0.7);
   delayExt1.delay(5,20);
   delayExt1.delay(4,100);
   delayExt1.delay(3,400);
   delayExt1.delay(2,1000);
   delayExt1.delay(1,4000);
   delayExt1.delay(0,6000);
   sine9.phase(90);
  sine10.phase(90); 
  sine11.phase(90);
  sine12.phase(90); 
  sine13.phase(90);  
  sine14.phase(90); 
  sine15.phase(90);  
  sine16.phase(90);  
}
//////////////////////////////////////////////
void loop() 
{     

  volumeCheck();//check the volume knob 

  touchCheck();//check if any of the capacitive pads have been touched

  dcValCheck();//check the decay knob

  buttonCheck();//check for button presses to change the scale 
  filter1.frequency(2*note_frequency[scale[scale_index][1]]);
  filter2.frequency(2*note_frequency[scale[scale_index][3]]);
  filter3.frequency(2*note_frequency[scale[scale_index][5]]);
  filter4.frequency(2*note_frequency[scale[scale_index][7]]);

}
/////////////////////////////////////////////////////
void volumeCheck()
{
  //check knob value for volume 
  int knob = analogRead(A7);
  int fknob = analogRead(A17);
  shift= map(analogRead(A16), 0, 1023,0, 12);
  if(shift-6==0)
    digitalWrite(24, HIGH );
  else
    digitalWrite(24, LOW);
  
  float vol = (float)knob / 1280.0;
  fBack = (float)fknob / 640.0;
  sgtl5000_1.volume(vol);
   if(debug == 1)
  {  
  Serial.print("A17 = ");  
  Serial.println(fBack);  
  Serial.print("A16 = ");  
  Serial.println(shift);  
  }
}
/////////////////////////////////////////////////////
void dcValCheck()
{
  //check knob and set value as delay on dc constant for sine wave decay
  dcVal = map(analogRead(A6), 0, 1023, 1, 1000);
  fbval = map(analogRead(A15), 0, 1023,0, 21);
  float f=1;
  if(fbval >6)
     f=0.5;
  if(fbval >22)
     f=1.0/3.0;
  if(fbval >41)
     f=1.0/4.0;
  if(fbval >56)
     f=1.0/5.0;
  if(fbval >62)
     f=1.0/6.0;
  int *mix=heads[fbval];
  f=f*fBack;
    mixer5.gain(1,mix[0]*f);
    mixer5.gain(2,mix[1]*f);
    mixer6.gain(0,mix[2]*f);
    mixer6.gain(1,mix[3]*f);
    mixer6.gain(2,mix[4]*f);
    mixer6.gain(3,mix[5]*f);
  
  if(debug == 1)
  {  
  Serial.print("A15 = ");  
  Serial.println(fbval);
  Serial.print("f = ");  
  Serial.print(mix[0]);  
  Serial.print("  ");  
  Serial.print(mix[5]);  
  Serial.print("  ");  
 Serial.println(f);
  }

}
/////////////////////////////////////////////////////
void hang(int t,AudioSynthWaveformSine *sine,AudioSynthWaveformSine *sinex,AudioSynthWaveformDc *dc,AudioSynthWaveformDc *dcx)
{
  int touch =touchRead(pinTouch[t]);
         if (touch > 2000)
        {
          //once a pad is touched, a value from the note frquency froma table is looked up via a 2D table
          //with x corresponding to a scale and y corresponding to one of the eight notes on the drum. 
         int ps=shift-6;
          sine->frequency(note_frequency[scale[scale_index][t]+ps]);
          dc->amplitude(0.8, 5);
          sinex->frequency(2*note_frequency[scale[scale_index][t]+ps]);
          dcx->amplitude(0.5, 6);
      }
      if (touch <= 2000) 
      {
        //one the pad is released, the note fades out with a decay val set by the dcVal knob
        dc->amplitude(0, dcVal);
        dcx->amplitude(0, dcVal*1.2);
     }

}
/////////////////////////////////////////////////////
void touchCheck()
{
  //Each capacitive touch pad will vary based on the size and material it is made of
  //The value necessary to trigger each note will require some trial and error to get the
  //sensitivity just right. Try adjusting these values to get the best response. 
  int t=0;
  hang(t++,&sine1,&sine2,&dc1,&dc2);  
  hang(t++,&sine3,&sine4,&dc3,&dc4);  
  hang(t++,&sine5,&sine6,&dc5,&dc6);  
  hang(t++,&sine7,&sine8,&dc7,&dc8);  
  hang(t++,&sine9,&sine10,&dc9,&dc10);  
  hang(t++,&sine11,&sine12,&dc11,&dc12);  
  hang(t++,&sine13,&sine14,&dc13,&dc14);  
  hang(t++,&sine15,&sine16,&dc15,&dc16);  
}
//////////////////////////////////////////////////
void buttonCheck()
{
  button0.update();
  button1.update();

  //if button 0 is pressed, increment the scale being used
  if (button0.risingEdge())
  { 
    scale_index++;
    //check for overflow
    if(scale_index > numOfScales)//numOfScales variable found in the scales.h file
    scale_index = 0;
    }

  //if button 1 is pressed, decrement the scale being used
   if (button1.fallingEdge())
      flange1.voices(0,0,0);
  if (button1.risingEdge())
  { 
    flange1.voices(s_idx,s_depth,s_freq);
    scale_index--;
    //check for negative numbers
    if(scale_index < 0)
    scale_index = numOfScales;//numOfScales variable found in the scales.h file
  }
   if((scale_index+1)%2)
       digitalWrite(4, HIGH);
    if((scale_index+1)%2==0)
       digitalWrite(4, LOW);
  if(((scale_index+1)/2)%2)
       digitalWrite(5, HIGH);
    if(((scale_index+1)/2)%2==0)
       digitalWrite(5, LOW);
   if(((scale_index+1)/4)%2)
       digitalWrite(8, HIGH);
    if(((scale_index+1)/4)%2==0)
       digitalWrite(8, LOW);

  if(debug == 0)
  {  
  Serial.print("Scale = ");  
  Serial.println(scale_index);
  }
}
