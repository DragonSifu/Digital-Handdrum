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
#include <CapacitiveSensor.h>
//#include <OpenAudio_ArduinoLibrary.h> //for AudioConvert_I16toF32, AudioConvert_F32toI16, and AudioEffectGain_F32

#include "note_frequency.h"
#include "scales.h"

#include "TeensyAudioDesignTool.h"
#define SDCARD_MOSI_PIN  7
#define SDCARD_SCK_PIN   14

//an array to define each of the eight touch sense pins,
//all other touch sense pins are used by the Teensy Audio Shield (16,17,18,19)
int pinTouch[] = { 30, 29, 36, 17, 16, 15, 0, 1 };
int pinTouched[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
float times1[]={185.76,185.76,185.76,185.76,185.76,185.76,185.76,185.76,185.76};
float levels1[]={80.7799,79.8124,21.6154,31.9916,15.2982,8.13087,5.67181,2.92224,1.87064};
float times2[]={185.76,185.76,185.76,185.76,185.76,185.76,185.76,185.76,185.76};
float levels2[]={63.4619,31.9866,46.4768,29.1345,1.44017,12.6471,6.70539,2.44639,3.5003};
int cos1[]={1,0};
int scale_index = 0;//var to keep track fo which scale is being used
#define FLANGE_DELAY_LENGTH (4*AUDIO_BLOCK_SAMPLES)
// Allocate the delay lines for left and right channels
short l_delayline[FLANGE_DELAY_LENGTH];
int s_idx = FLANGE_DELAY_LENGTH / 4;
int s_depth = FLANGE_DELAY_LENGTH / 8;
double s_freq = 1.5;
CapacitiveSensor   cs_4_2 = CapacitiveSensor(35, 34);
int dcVal = 0;//value to control the decay of each note
int headset = 0;
int shift = 0;//value to control pitch shift of the notes

float fBack = 1;//value to control the feedback of the delay
//buttons for incrementing or decrementing through each scale
Bounce button0 = Bounce(2, 15);
Bounce button1 = Bounce(3, 15);
AudioSynthWaveformSine   *sines[] = { &sine1, &sine3, &sine5, &sine7, &sine9, &sine11, &sine13, &sine15, &sine2, &sine4, &sine6, &sine8, &sine10, &sine12, &sine14, &sine16 };
AudioSynthWaveformDc     *dcs[] = { &dc1, &dc3, &dc5, &dc7, &dc9, &dc11, &dc13, &dc15, &dc2, &dc4, &dc6, &dc8, &dc10, &dc12, &dc14, &dc16 };

bool debug = 0;//Set to 1 for Serial debugging
int reso = 3;
////////////////////////////////////////////////////////
void setup()
{
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   AudioMemory(130);
 //initialize buttons
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  button0.update();
  button1.update();
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(33, OUTPUT);
  //initialize Serial
  Serial.begin(115200);
  Serial.println("Start...");
  delayExt1.initialize(AUDIO_MEMORY_CY15B104, 6 * AUDIO_SAMPLE_RATE_EXACT);
  flange1.begin(l_delayline, FLANGE_DELAY_LENGTH, s_idx, s_depth, s_freq);
  flange1.voices(s_idx, s_depth, s_freq);

  //set aside audio memory
 
  //initialize audio settings

  //initialize volume
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.8);
  //enable line out for troubleshooting on O-scope
  //sgtl5000_1.unmuteLineout();
//  filter1.resonance(reso);
//  filter2.resonance(reso);
//  filter3.resonance(reso);
//  filter4.resonance(reso);
//  filter1.frequency(50);
//  filter2.frequency(100);
//  filter3.frequency(200);
//  filter4.frequency(400);
//  filter21.frequency(1500);
//  filter1.octaveControl(2);
//  filter2.octaveControl(2);
//  filter3.octaveControl(2);
//  filter4.octaveControl(2);
  delayExt1.delay(5, 20);
  delayExt1.delay(4, 100);
  delayExt1.delay(3, 400);
  delayExt1.delay(2, 1000);
  delayExt1.delay(1, 4000);
  delayExt1.delay(0, 6000);
  for (int s = 0 ; s < 8; s ++)
  {
    sines[s]->phase(90);
    dcs[s]->multiseg(levels1, times1, sizeof(levels1)/4,128);
    dcs[s+8]->multiseg(levels2, times2, sizeof(levels2)/4,128);
  }

}
//////////////////////////////////////////////
void loop()
{
  int ps = shift - 6;

  volumeCheck();//check the volume knob

  touchCheck();//check if any of the capacitive pads have been touched

  dcValCheck();//check the decay knob

  buttonCheck();//check for button presses to change the scale
//  filter1.frequency(note_frequency[scale[scale_index][0]] + ps);
//  filter2.frequency(note_frequency[scale[scale_index][2]] + ps);
//  filter3.frequency(note_frequency[scale[scale_index][4]] + ps);
//  filter4.frequency(note_frequency[scale[scale_index][6]] + ps);
//  Serial.print("CPU: ");
}
/////////////////////////////////////////////////////
void volumeCheck()
{
  //check knob value for volume
  int knob = analogRead(A7);
  int fknob = analogRead(A20);
  shift = map(analogRead(37), 0, 1023, 0, 12);
  if (shift - 6 == 0)
    digitalWrite(33, HIGH);
  else
    digitalWrite(33, LOW);

  float vol = (float)knob / 1280.0;
  fBack = (float)fknob / 640.0;
  sgtl5000_1.volume(vol);
  if (debug == 1)
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
  headset = map(analogRead(A18), 0, 1023, 0, 21);
  float f = 1;
  if (headset > 6)
    f = 0.5;
  if (headset > 22)
    f = 1.0 / 3.0;
  if (headset > 41)
    f = 1.0 / 4.0;
  if (headset > 56)
    f = 1.0 / 5.0;
  if (headset > 62)
    f = 1.0 / 6.0;
  int *mix = heads[headset];
  f = f * fBack;
//  mixer5.gain(1, mix[0] * f);
//  mixer5.gain(2, mix[1] * f);
  mixer6.gain(0, mix[2] * f);
  mixer6.gain(1, mix[3] * f);
  mixer6.gain(2, mix[4] * f);
  mixer6.gain(3, mix[5] * f);
//filter1.frequency(analogRead(36));
//filter1.resonance(5);


}
/////////////////////////////////////////////////////
void hang(int t, AudioSynthWaveformSine *sine, AudioSynthWaveformSine *sinex, AudioSynthWaveformDc *dc, AudioSynthWaveformDc *dcx)
{
  int touch = touchRead(pinTouch[t]);
  long total1 = 1700;
  bool touched = false;
  if (t == 2)
  {
    total1 =  cs_4_2.capacitiveSensor(30);
    if (total1 < 0)
      touched = true;
    if (touched)
    {
      Serial.print("touch ");
      Serial.print(t);
      Serial.print(" = ");
      Serial.println(total1);
    }
  }
  else if (touch > 5000)
  {
    touched = true;
  }
  int ps = shift - 6;
  // Serial.println(touch);
  if (touched && pinTouched[t] == 0)
  {
    if (debug == 0)
    {
      Serial.print("touch ");
      Serial.print(t);
      Serial.print(" = ");
      Serial.println(note_frequency[scale[scale_index][t]]);
    }
    //once a pad is touched, a value from the note frquency froma table is looked up via a 2D table
    //with x corresponding to a scale and y corresponding to one of the eight notes on the drum.
    sine->frequency(note_frequency[scale[scale_index][t] + ps]);
    sinex->frequency(2 * note_frequency[scale[scale_index][t] + ps]);
    dc->noteOn();
    dcx->noteOn();
    if (pinTouched[t] == 0)
      usbMIDI.sendNoteOn(scale[scale_index][t] + ps, 100, 1);
    pinTouched[t] = 1;
  }
  if (!touched && pinTouched[t])
  {
    //one the pad is released, the note fades out with a decay val set by the dcVal knob
    dc->noteOff();
    dcx->noteOff();
    dc->amplitude(0, dcVal);
    dcx->amplitude(0, dcVal);
  if (pinTouched[t] == 1)
      usbMIDI.sendNoteOff(scale[scale_index][t] + ps, 0, 1);
    pinTouched[t] = 0;
  }

}
/////////////////////////////////////////////////////
void touchCheck()
{
  //Each capacitive touch pad will vary based on the size and material it is made of
  //The value necessary to trigger each note will require some trial and error to get the
  //sensitivity just right. Try adjusting these values to get the best response.
  for (int s = 0; s < 16; s += 2)
    hang(s / 2, sines[s / 2], sines[s / 2 + 1], dcs[s / 2], dcs[s / 2+1]);
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
    if (scale_index > numOfScales)//numOfScales variable found in the scales.h file
      scale_index = 0;
  }

  //if button 1 is pressed, decrement the scale being used
  if (button1.risingEdge())
  {
    scale_index--;
    //check for negative numbers
    if (scale_index < 0)
      scale_index = numOfScales;//numOfScales variable found in the scales.h file
  }
  int s1 = scale_index + 1;
  digitalWrite(4, s1 % 2);
  s1 /= 2;
  digitalWrite(5, s1 % 2);
  s1 /= 2;
  digitalWrite(8, s1 % 2);
}
