#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>

#include "SD.h"
#include "TMRpcm.h"
#include "SPI.h"

int trigPin[8]; 
int echoPin[8];
int distance[8];
const int SD_chipselectPin = 53;
TMRpcm tmrpcm;

void setup() {
Serial.begin(115200); 
for(int i=0;i<8;i++)
{ 
trigPin[i]= 2*i + 26;
echoPin[i]= 2*i + 27;
  }
tmrpcm.speakerPin = 5; 

for(int i=0;i<8;i++)
{
   pinMode(trigPin[i],OUTPUT);
   pinMode(echoPin[i],INPUT);
}
if(!SD.begin(SD_chipselectPin)){return; }
// tmrpcm.setvolume(6);
 
}

void loop() 
{
 bool current_status1[8];
  bool current_status2[8];
 bool get_status(int sensor_no);
double get_distance(int sensor_no);
 
 current_status1[0] = get_status(1);
 current_status1[3] = get_status(4);
delay(50);
current_status1[1] = get_status(2);
current_status1[2] = get_status(3);
current_status1[4] = get_status(5);
current_status1[5] = get_status(6);
current_status1[6] = get_status(7);
 current_status1[7] = get_status(8);

 current_status2[0] = get_status(1);
 current_status2[3] = get_status(4);
delay(50);
current_status2[1] = get_status(2);
current_status2[2] = get_status(3);
current_status2[4] = get_status(5);
current_status2[5] = get_status(6);
current_status2[6] = get_status(7);
 current_status2[7] = get_status(8);


if(current_status1[6]==LOW && current_status2[6]==LOW)
;
else if(current_status1[0]==LOW && current_status1[1]==LOW && current_status2[0]==LOW && current_status2[1]==LOW)
tmrpcm.play("45_left.wav");
else if(current_status1[2]==LOW && current_status1[3]==LOW && current_status2[2]==LOW && current_status2[3]==LOW)  
tmrpcm.play("45_right.wav");
else if(current_status1[4]==LOW && current_status2[4]==LOW)
tmrpcm.play("90_left.wav");
else if(current_status1[5]==LOW && current_status2[5]==LOW)
tmrpcm.play("90_right.wav");
else if(current_status1[7]==LOW && current_status2[7]==LOW)
tmrpcm.play("turn around.wav");
else tmrpcm.play("attention.wav");
delay(1500); 
}

// FUNCTIONS//
bool get_status(int sensor_no)
{ double Distance =get_distance(sensor_no-1);
  if( Distance>10 && Distance <150 ){
  return true;}
  else return false;

}

double get_distance(int sensor_no)
{
digitalWrite(trigPin[sensor_no-1], LOW);
delayMicroseconds(2);
digitalWrite(trigPin[sensor_no-1], HIGH);
delayMicroseconds(10);
digitalWrite(trigPin[sensor_no-1], LOW);
double duration = pulseIn(echoPin[sensor_no-1], HIGH,50000);
double distance = (duration/2) / 29.1;
return distance;
}
