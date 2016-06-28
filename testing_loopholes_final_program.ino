#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>

#include "SD.h"
#include "TMRpcm.h"
#include "SPI.h"

int trigPin[12]; 
int echoPin[12];
int distance[12];
const int SD_chipselectPin = 53;
TMRpcm tmrpcm;

void setup() {
Serial.begin(115200); 
for(int i=0;i<12;i++)
{ 
trigPin[i]= 2*i + 26;
echoPin[i]= 2*i + 27;
  }
tmrpcm.speakerPin = 5; 

for(int i=0;i<12;i++)
{
   pinMode(trigPin[i],OUTPUT);
   pinMode(echoPin[i],INPUT);
}
if(!SD.begin(SD_chipselectPin))
{ Serial.println("SD fail");
  return; }
// tmrpcm.setvolume(6);
Serial.println("starting loop");
 
}

void loop() 
{
  Serial.println("exec. loop");
 bool current_status[12];
 bool get_status(int sensor_no);
double get_distance(int sensor_no);
 current_status[10] = get_status(11);
 delay(50);
 current_status[0] = get_status(1);
 current_status[3] = get_status(4);
delay(50);
current_status[2] = get_status(3);
current_status[1] = get_status(2);
current_status[6] = get_status(7);
current_status[5] = get_status(6);
delay(50);
 current_status[4] = get_status(5);
 current_status[7] = get_status(8);
 current_status[8] = get_status(9);
 current_status[9] = get_status(10);
 current_status[11] = get_status(12);                            

if(current_status[10]==LOW && current_status[0]==LOW && current_status[1]==LOW && current_status[2]==LOW && current_status[3]==LOW)
return;
else if(current_status[4]==LOW && current_status[5]==LOW)
tmrpcm.play("45_left.wav");
else if(current_status[6]==LOW && current_status[7]==LOW) 
tmrpcm.play("45_right.wav");
else if(current_status[8]==LOW)
tmrpcm.play("90_left.wav");
else if(current_status[9]==LOW)
tmrpcm.play("90_right.wav");
else if(current_status[11]==LOW)
tmrpcm.play("turn around.wav");
else tmrpcm.play("attention.wav");
delay(5000); 
}

// FUNCTIONS//
bool get_status(int sensor_no)
{ double Distance =get_distance(sensor_no-1);
  if( Distance>10 && Distance <200){
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
Serial.println(distanceM);
return distance;
}

