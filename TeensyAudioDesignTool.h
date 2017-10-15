#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;          //xy=88,29
AudioSynthWaveformSine   sine2;          //xy=88,87
AudioSynthWaveformSine   sine3;          //xy=88,145
AudioSynthWaveformSine   sine4;          //xy=88,203
AudioSynthWaveformSine   sine9;          //xy=88,261
AudioSynthWaveformSine   sine10;         //xy=88,319
AudioSynthWaveformSine   sine12;         //xy=88,377
AudioSynthWaveformSine   sine11;         //xy=88,435
AudioSynthWaveformSine   sine13;         //xy=88,493
AudioSynthWaveformSine   sine14;         //xy=88,551
AudioSynthWaveformSine   sine15;         //xy=88,609
AudioSynthWaveformSine   sine16;         //xy=88,667
AudioSynthWaveformSine   sine5;          //xy=88,725
AudioSynthWaveformSine   sine6;          //xy=88,783
AudioSynthWaveformSine   sine7;          //xy=88,841
AudioSynthWaveformSine   sine8;          //xy=88,899
AudioSynthWaveformDc     dc1;            //xy=264,42
AudioSynthWaveformDc     dc2;            //xy=264,100
AudioSynthWaveformDc     dc3;            //xy=264,158
AudioSynthWaveformDc     dc4;            //xy=264,216
AudioSynthWaveformDc     dc9;            //xy=264,274
AudioSynthWaveformDc     dc10;           //xy=264,332
AudioSynthWaveformDc     dc12;           //xy=264,390
AudioSynthWaveformDc     dc11;           //xy=264,448
AudioSynthWaveformDc     dc13;           //xy=264,506
AudioSynthWaveformDc     dc14;           //xy=264,564
AudioSynthWaveformDc     dc15;           //xy=264,622
AudioSynthWaveformDc     dc16;           //xy=264,680
AudioSynthWaveformDc     dc5;            //xy=264,738
AudioSynthWaveformDc     dc6;            //xy=264,796
AudioSynthWaveformDc     dc7;            //xy=264,854
AudioSynthWaveformDc     dc8;            //xy=264,912
AudioEffectMultiply      multiply1;      //xy=464,36
AudioEffectMultiply      multiply2;      //xy=464,94
AudioEffectMultiply      multiply3;      //xy=464,152
AudioEffectMultiply      multiply4;      //xy=464,210
AudioEffectMultiply      multiply9;      //xy=464,268
AudioEffectMultiply      multiply10;     //xy=464,326
AudioEffectMultiply      multiply12;     //xy=464,384
AudioEffectMultiply      multiply11;     //xy=464,442
AudioEffectMultiply      multiply13;     //xy=464,500
AudioEffectMultiply      multiply14;     //xy=464,558
AudioEffectMultiply      multiply15;     //xy=464,616
AudioEffectMultiply      multiply16;     //xy=464,674
AudioEffectMultiply      multiply5;      //xy=464,732
AudioEffectMultiply      multiply6;      //xy=464,790
AudioEffectMultiply      multiply7;      //xy=464,848
AudioEffectMultiply      multiply8;      //xy=464,906
AudioMixer4              mixer4;         //xy=703,575
AudioMixer4              mixer2;         //xy=703,807
AudioMixer4              mixer3;         //xy=707,348
AudioMixer4              mixer1;         //xy=710,122
AudioFilterStateVariable filter1;        //xy=857,128
AudioFilterStateVariable filter3;        //xy=876,582
AudioFilterStateVariable filter2;        //xy=878,355
AudioFilterStateVariable filter4;        //xy=882,813
AudioMixer4              mixerMain;      //xy=1070,332
AudioSynthWaveformDc     dc17;           //xy=1080,465
AudioEffectFlange        flange1;        //xy=1272,335
//AudioEffectDelayExternal delayExt1;      //xy=1273,211
AudioMixer4              mixer6;         //xy=1532,185
AudioMixer4              mixer5;         //xy=1533,283
AudioOutputI2S           i2s1;           //xy=1659,491
AudioConnection          patchCord1(sine1, 0, multiply1, 0);
AudioConnection          patchCord2(sine2, 0, multiply2, 0);
AudioConnection          patchCord3(sine3, 0, multiply3, 0);
AudioConnection          patchCord4(sine4, 0, multiply4, 0);
AudioConnection          patchCord5(sine9, 0, multiply9, 0);
AudioConnection          patchCord6(sine10, 0, multiply10, 0);
AudioConnection          patchCord7(sine12, 0, multiply12, 0);
AudioConnection          patchCord8(sine11, 0, multiply11, 0);
AudioConnection          patchCord9(sine13, 0, multiply13, 0);
AudioConnection          patchCord10(sine14, 0, multiply14, 0);
AudioConnection          patchCord11(sine15, 0, multiply15, 0);
AudioConnection          patchCord12(sine16, 0, multiply16, 0);
AudioConnection          patchCord13(sine5, 0, multiply5, 0);
AudioConnection          patchCord14(sine6, 0, multiply6, 0);
AudioConnection          patchCord15(sine7, 0, multiply7, 0);
AudioConnection          patchCord16(sine8, 0, multiply8, 0);
AudioConnection          patchCord17(dc1, 0, multiply1, 1);
AudioConnection          patchCord18(dc2, 0, multiply2, 1);
AudioConnection          patchCord19(dc3, 0, multiply3, 1);
AudioConnection          patchCord20(dc4, 0, multiply4, 1);
AudioConnection          patchCord21(dc9, 0, multiply9, 1);
AudioConnection          patchCord22(dc10, 0, multiply10, 1);
AudioConnection          patchCord23(dc12, 0, multiply12, 1);
AudioConnection          patchCord24(dc11, 0, multiply11, 1);
AudioConnection          patchCord25(dc13, 0, multiply13, 1);
AudioConnection          patchCord26(dc14, 0, multiply14, 1);
AudioConnection          patchCord27(dc15, 0, multiply15, 1);
AudioConnection          patchCord28(dc16, 0, multiply16, 1);
AudioConnection          patchCord29(dc5, 0, multiply5, 1);
AudioConnection          patchCord30(dc6, 0, multiply6, 1);
AudioConnection          patchCord31(dc7, 0, multiply7, 1);
AudioConnection          patchCord32(dc8, 0, multiply8, 1);
AudioConnection          patchCord33(multiply1, 0, mixer1, 0);
AudioConnection          patchCord34(multiply2, 0, mixer1, 1);
AudioConnection          patchCord35(multiply3, 0, mixer1, 2);
AudioConnection          patchCord36(multiply4, 0, mixer1, 3);
AudioConnection          patchCord37(multiply9, 0, mixer3, 0);
AudioConnection          patchCord38(multiply10, 0, mixer3, 1);
AudioConnection          patchCord39(multiply12, 0, mixer3, 2);
AudioConnection          patchCord40(multiply11, 0, mixer3, 3);
AudioConnection          patchCord41(multiply13, 0, mixer4, 0);
AudioConnection          patchCord42(multiply14, 0, mixer4, 1);
AudioConnection          patchCord43(multiply15, 0, mixer4, 2);
AudioConnection          patchCord44(multiply16, 0, mixer4, 3);
AudioConnection          patchCord45(multiply5, 0, mixer2, 0);
AudioConnection          patchCord46(multiply6, 0, mixer2, 1);
AudioConnection          patchCord47(multiply7, 0, mixer2, 2);
AudioConnection          patchCord48(multiply8, 0, mixer2, 3);
AudioConnection          patchCord49(mixer4, 0, filter3, 0);
AudioConnection          patchCord50(mixer2, 0, filter4, 0);
AudioConnection          patchCord51(mixer3, 0, filter2, 0);
AudioConnection          patchCord52(mixer1, 0, filter1, 0);
AudioConnection          patchCord53(filter1, 0, mixerMain, 0);
AudioConnection          patchCord54(filter3, 0, mixerMain, 2);
AudioConnection          patchCord55(filter2, 0, mixerMain, 1);
AudioConnection          patchCord56(filter4, 0, mixerMain, 3);
AudioConnection          patchCord57(mixerMain, flange1);
AudioConnection          patchCord58(flange1, 0, mixer5, 3);
AudioConnection          patchCord59(delayExt1, 0, mixer6, 0);
AudioConnection          patchCord60(delayExt1, 1, mixer6, 1);
AudioConnection          patchCord61(delayExt1, 2, mixer6, 2);
AudioConnection          patchCord62(delayExt1, 3, mixer6, 3);
AudioConnection          patchCord63(delayExt1, 4, mixer5, 1);
AudioConnection          patchCord64(delayExt1, 5, mixer5, 2);
AudioConnection          patchCord65(mixer6, 0, mixer5, 0);
AudioConnection          patchCord66(mixer5, delayExt1);
AudioConnection          patchCord67(mixer5, 0, i2s1, 0);
AudioConnection          patchCord68(mixer5, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1496,578
// GUItool: end automatically generated code

