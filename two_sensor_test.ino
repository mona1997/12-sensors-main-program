#include"SD.h"
#include "SPI.h"
int trigPin[8]; 
int echoPin[8];
int distance[8];



void setup() {
  Serial.begin(9600); 
  Serial.println("Initialising..");
  for(int i=0;i<2;i++)
    { 
    trigPin[i]= 2*i + 28; 
    echoPin[i]= 2*i + 29;
      }

for(int i=0;i<2;i++)
{
   pinMode(trigPin[i],OUTPUT);
   pinMode(echoPin[i],INPUT);
}
 Serial.println("Done");
 delay(700);
}

void loop() 
{
  Serial.println("exe. loop");
 bool current_status[8];
 bool get_status(int sensor_no);
double get_distance(int sensor_no);
 current_status[0] = get_status(1);
 delay(1000);

 current_status[1] = get_status(2);
delay(1000);

}

// FUNCTIONS//
bool get_status(int sensor_no)
{ double Distance =get_distance(sensor_no);
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
double distance = (duration/2.0) / 29.1;
Serial.println(sensor_no);
Serial.println(distance);
return distance;
}

