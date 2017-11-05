#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine13;         //xy=166,776
AudioSynthWaveformSine   sine14;         //xy=166,834
AudioSynthWaveformSine   sine15;         //xy=166,892
AudioSynthWaveformSine   sine16;         //xy=166,950
AudioSynthWaveformSine   sine12;         //xy=169,706
AudioSynthWaveformSine   sine9;          //xy=170,541
AudioSynthWaveformSine   sine10;         //xy=170,599
AudioSynthWaveformSine   sine11;         //xy=170,654
AudioSynthWaveformSine   sine5;          //xy=172,283
AudioSynthWaveformSine   sine6;          //xy=172,341
AudioSynthWaveformSine   sine7;          //xy=172,399
AudioSynthWaveformSine   sine8;          //xy=172,457
AudioSynthWaveformSine   sine1;          //xy=174,44
AudioSynthWaveformSine   sine2;          //xy=174,102
AudioSynthWaveformSine   sine3;          //xy=174,160
AudioSynthWaveformSine   sine4;          //xy=174,218
AudioSynthWaveformDc     dc16;           //xy=321,988
AudioSynthWaveformDc     dc14;           //xy=340,863
AudioSynthWaveformDc     dc6;            //xy=342,371
AudioSynthWaveformDc     dc15;           //xy=340,925
AudioSynthWaveformDc     dc12;           //xy=341,738
AudioSynthWaveformDc     dc9;            //xy=343,571
AudioSynthWaveformDc     dc13;           //xy=343,808
AudioSynthWaveformDc     dc5;            //xy=345,314
AudioSynthWaveformDc     dc11;           //xy=344,683
AudioSynthWaveformDc     dc10;           //xy=345,624
AudioSynthWaveformDc     dc8;            //xy=346,492
AudioSynthWaveformDc     dc3;            //xy=348,194
AudioSynthWaveformDc     dc4;            //xy=348,250
AudioSynthWaveformDc     dc1;            //xy=349,75
AudioSynthWaveformDc     dc7;            //xy=349,431
AudioSynthWaveformDc     dc2;            //xy=352,129
AudioEffectMultiply      multiply6;      //xy=525,953
AudioEffectMultiply      multiply5;      //xy=530,891
AudioEffectMultiply      multiply8;      //xy=532,781
AudioEffectMultiply      multiply7;      //xy=533,837
AudioEffectMultiply      multiply13;     //xy=541,659
AudioEffectMultiply      multiply14;     //xy=541,717
AudioEffectMultiply      multiply15;     //xy=544,604
AudioEffectMultiply      multiply9;      //xy=546,412
AudioEffectMultiply      multiply10;     //xy=546,470
AudioEffectMultiply      multiply16;     //xy=547,538
AudioEffectMultiply      multiply11;     //xy=549,357
AudioEffectMultiply      multiply3;      //xy=550,167
AudioEffectMultiply      multiply4;      //xy=550,225
AudioEffectMultiply      multiply12;     //xy=552,291
AudioEffectMultiply      multiply2;      //xy=553,112
AudioEffectMultiply      multiply1;      //xy=556,46
AudioMixer4              mixer1;         //xy=730,776
AudioMixer4              mixer9;         //xy=755,635
AudioMixer4              mixer8;         //xy=760,388
AudioMixer4              mixer7;         //xy=764,143
AudioMixer4              mixer2;         //xy=970,540
AudioEffectDelayExternal delayExt1;      //xy=1051,209
AudioMixer4              mixer3;         //xy=1117,538
AudioMixer4              mixer6;         //xy=1249,180
AudioMixer4              mixer5;         //xy=1290,299
AudioEffectFlange        flange1;        //xy=1316,504
AudioFilterStateVariable filter1;        //xy=1474,402
AudioOutputI2S           i2s1;           //xy=1489,571
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
AudioConnection          patchCord53(mixer2, 0, mixer3, 1);
AudioConnection          patchCord54(delayExt1, 0, mixer6, 0);
AudioConnection          patchCord55(delayExt1, 1, mixer6, 1);
AudioConnection          patchCord56(delayExt1, 2, mixer6, 2);
AudioConnection          patchCord57(delayExt1, 3, mixer6, 3);
AudioConnection          patchCord58(delayExt1, 4, mixer5, 1);
AudioConnection          patchCord59(delayExt1, 5, mixer5, 2);
AudioConnection          patchCord60(mixer3, 0, i2s1, 0);
AudioConnection          patchCord61(mixer3, 0, i2s1, 1);
AudioConnection          patchCord62(mixer3, delayExt1);
AudioConnection          patchCord63(mixer6, 0, mixer5, 0);
AudioConnection          patchCord64(mixer5, 0, filter1, 0);
AudioConnection          patchCord65(filter1, 0, mixer3, 0);
AudioControlSGTL5000     sgtl5000_1;     //xy=1605,831
// GUItool: end automatically generated code

