#include"SD.h"
#include "SPI.h"
int trigPin[8]; 
int echoPin[8];
int distance[8];



void setup() {
  Serial.begin(9600); 
  Serial.println("Initialising..");
  for(int i=0;i<8;i++)
    { 
    trigPin[i]= 2*i + 26; 
    echoPin[i]= 2*i + 27;
      }

for(int i=0;i<8;i++)
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
 current_status[3] = get_status(4);
 delay(1000);
 current_status[1] = get_status(2);
delay(1000);
current_status[2] = get_status(3);
delay(1000);
current_status[4] = get_status(5);
delay(1000);
current_status[5] = get_status(6);
delay(1000);
current_status[6] = get_status(7);
delay(1000);
 current_status[7] = get_status(8);
 delay(1000);

if(current_status[6]==LOW)
Serial.println("keep walking");
else if(current_status[0]==LOW && current_status[1]==LOW)
Serial.println("left 45");
else if(current_status[2]==LOW && current_status[3]==LOW) 
Serial.println("right 45");
else if(current_status[4]==LOW)
Serial.println("left 90");
else if(current_status[5]==LOW)
Serial.println("right 90");
else if(current_status[7]==LOW)
Serial.println("attention");

delay(5000);
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

