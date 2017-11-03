#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine13;         //xy=225,805
AudioSynthWaveformSine   sine14;         //xy=225,863
AudioSynthWaveformSine   sine15;         //xy=225,921
AudioSynthWaveformSine   sine16;         //xy=225,979
AudioSynthWaveformSine   sine12;         //xy=228,735
AudioSynthWaveformSine   sine9;          //xy=229,570
AudioSynthWaveformSine   sine10;         //xy=229,628
AudioSynthWaveformSine   sine11;         //xy=229,683
AudioSynthWaveformSine   sine5;          //xy=231,312
AudioSynthWaveformSine   sine6;          //xy=231,370
AudioSynthWaveformSine   sine7;          //xy=231,428
AudioSynthWaveformSine   sine8;          //xy=231,486
AudioSynthWaveformSine   sine1;          //xy=233,73
AudioSynthWaveformSine   sine2;          //xy=233,131
AudioSynthWaveformSine   sine3;          //xy=233,189
AudioSynthWaveformSine   sine4;          //xy=233,247
AudioSynthWaveformDc     dc16;           //xy=380,1017
AudioSynthWaveformDc     dc14;           //xy=399,892
AudioSynthWaveformDc     dc6;            //xy=401,400
AudioSynthWaveformDc     dc15;           //xy=399,954
AudioSynthWaveformDc     dc12;           //xy=400,767
AudioSynthWaveformDc     dc9;            //xy=402,600
AudioSynthWaveformDc     dc13;           //xy=402,837
AudioSynthWaveformDc     dc5;            //xy=404,343
AudioSynthWaveformDc     dc11;           //xy=403,712
AudioSynthWaveformDc     dc10;           //xy=404,653
AudioSynthWaveformDc     dc8;            //xy=405,521
AudioSynthWaveformDc     dc3;            //xy=407,223
AudioSynthWaveformDc     dc4;            //xy=407,279
AudioSynthWaveformDc     dc1;            //xy=408,104
AudioSynthWaveformDc     dc7;            //xy=408,460
AudioSynthWaveformDc     dc2;            //xy=411,158
AudioEffectMultiply      multiply6; //xy=584,982
AudioEffectMultiply      multiply5; //xy=589,920
AudioEffectMultiply      multiply8; //xy=591,810
AudioEffectMultiply      multiply7; //xy=592,866
AudioEffectMultiply      multiply13; //xy=600,688
AudioEffectMultiply      multiply14; //xy=600,746
AudioEffectMultiply      multiply15; //xy=603,633
AudioEffectMultiply      multiply9; //xy=605,441
AudioEffectMultiply      multiply10; //xy=605,499
AudioEffectMultiply      multiply16; //xy=606,567
AudioEffectMultiply      multiply11; //xy=608,386
AudioEffectMultiply      multiply3;      //xy=609,196
AudioEffectMultiply      multiply4;      //xy=609,254
AudioEffectMultiply      multiply12; //xy=611,320
AudioEffectMultiply      multiply2;      //xy=612,141
AudioEffectMultiply      multiply1;      //xy=615,75
AudioMixer4              mixer1;         //xy=789,805
AudioMixer4              mixer9; //xy=814,664
AudioMixer4              mixer8; //xy=819,417
AudioMixer4              mixer7;         //xy=823,172
AudioMixer4              mixer2;         //xy=1029,569
AudioEffectDelayExternal delayExt1;      //xy=1110,238
AudioEffectFlange        flange1;        //xy=1219,599
AudioMixer4              mixer6;         //xy=1308,209
AudioMixer4              mixer5;         //xy=1355,331
AudioOutputI2S           i2s1;           //xy=1409,552
AudioConnection          patchCord1(sine13, 0, multiply8, 0);
AudioConnection          patchCord2(sine14, 0, multiply7, 0);
AudioConnection          patchCord3(sine15, 0, multiply5, 0);
AudioConnection          patchCord4(sine16, 0, multiply6, 0);
AudioConnection          patchCord5(sine12, 0, multiply14, 0);
AudioConnection          patchCord6(sine9, 0, multiply16, 0);
AudioConnection          patchCord7(sine10, 0, multiply15, 0);
AudioConnection          patchCord8(sine11, 0, multiply13, 0);
AudioConnection          patchCord9(sine5, 0, multiply12, 0);
AudioConnection          patchCord10(sine6, 0, multiply11, 0);
AudioConnection          patchCord11(sine7, 0, multiply9, 0);
AudioConnection          patchCord12(sine8, 0, multiply10, 0);
AudioConnection          patchCord13(sine1, 0, multiply1, 0);
AudioConnection          patchCord14(sine2, 0, multiply2, 0);
AudioConnection          patchCord15(sine3, 0, multiply3, 0);
AudioConnection          patchCord16(sine4, 0, multiply4, 0);
AudioConnection          patchCord17(dc16, 0, multiply6, 1);
AudioConnection          patchCord18(dc14, 0, multiply7, 0);
AudioConnection          patchCord19(dc6, 0, multiply11, 1);
AudioConnection          patchCord20(dc15, 0, multiply5, 1);
AudioConnection          patchCord21(dc12, 0, multiply14, 1);
AudioConnection          patchCord22(dc9, 0, multiply16, 1);
AudioConnection          patchCord23(dc13, 0, multiply8, 1);
AudioConnection          patchCord24(dc5, 0, multiply12, 1);
AudioConnection          patchCord25(dc11, 0, multiply13, 1);
AudioConnection          patchCord26(dc10, 0, multiply15, 1);
AudioConnection          patchCord27(dc8, 0, multiply10, 1);
AudioConnection          patchCord28(dc3, 0, multiply3, 1);
AudioConnection          patchCord29(dc4, 0, multiply4, 1);
AudioConnection          patchCord30(dc1, 0, multiply1, 1);
AudioConnection          patchCord31(dc7, 0, multiply9, 1);
AudioConnection          patchCord32(dc2, 0, multiply2, 1);
AudioConnection          patchCord33(multiply6, 0, mixer1, 3);
AudioConnection          patchCord34(multiply5, 0, mixer1, 2);
AudioConnection          patchCord35(multiply8, 0, mixer1, 0);
AudioConnection          patchCord36(multiply7, 0, mixer1, 1);
AudioConnection          patchCord37(multiply13, 0, mixer9, 2);
AudioConnection          patchCord38(multiply14, 0, mixer9, 3);
AudioConnection          patchCord39(multiply15, 0, mixer9, 1);
AudioConnection          patchCord40(multiply9, 0, mixer8, 2);
AudioConnection          patchCord41(multiply10, 0, mixer8, 3);
AudioConnection          patchCord42(multiply16, 0, mixer9, 0);
AudioConnection          patchCord43(multiply11, 0, mixer8, 1);
AudioConnection          patchCord44(multiply3, 0, mixer7, 2);
AudioConnection          patchCord45(multiply4, 0, mixer7, 3);
AudioConnection          patchCord46(multiply12, 0, mixer8, 0);
AudioConnection          patchCord47(multiply2, 0, mixer7, 1);
AudioConnection          patchCord48(multiply1, 0, mixer7, 0);
AudioConnection          patchCord49(mixer1, 0, mixer2, 3);
AudioConnection          patchCord50(mixer9, 0, mixer2, 2);
AudioConnection          patchCord51(mixer8, 0, mixer2, 1);
AudioConnection          patchCord52(mixer7, 0, mixer2, 0);
AudioConnection          patchCord53(mixer2, 0, i2s1, 0);
AudioConnection          patchCord54(mixer2, flange1);
AudioConnection          patchCord55(flange1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1664,860
// GUItool: end automatically generated code

