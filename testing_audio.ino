#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>


// Test program for testing audio and to test whether time delay occurs or not 
 
 #include "SD.h" 
 #define SD_ChipSelectPin 53 
 #include "TMRpcm.h"
 #include "SPI.h"
 TMRpcm tmrpcm;
void setup()  
  { 
    
  tmrpcm.speakerPin = 5; 
  Serial.begin(115200);
  if (!SD.begin(SD_ChipSelectPin)) 
  { Serial.println("SD fail"); 
  return;
  } 
  
  
  
  Serial.println("Playing File");
  }
  void loop(){
    tmrpcm.play("greek.wav"); 
    while(1);
  }


