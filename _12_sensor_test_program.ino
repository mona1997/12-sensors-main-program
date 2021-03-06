#include"SD.h"
#include "SPI.h"
int trigPin[12]; 
int echoPin[12];
int distance[12];



void setup() {
  Serial.begin(9600); 
  Serial.println("Initialising..");
  for(int i=0;i<12;i++)
    { 
    trigPin[i]= 2*i + 26; 
    echoPin[i]= 2*i + 27;
      }

for(int i=0;i<12;i++)
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
 bool current_status[12];
 bool get_status(int sensor_no);
double get_distance(int sensor_no);
 current_status[10] = get_status(11);
 delay(50);
 current_status[0] = get_status(1);
 delay(50);
 current_status[3] = get_status(4);
delay(50);
current_status[2] = get_status(3);
delay(50);
current_status[1] = get_status(2);
delay(50);
current_status[6] = get_status(7);
delay(50);
current_status[5] = get_status(6);
delay(50);
 current_status[4] = get_status(5);
 delay(50);
 current_status[7] = get_status(8);
 delay(50);
 current_status[8] = get_status(9);
 delay(50);
 current_status[9] = get_status(10);
 delay(50);
 current_status[11] = get_status(12);                            
delay(50);
if(current_status[10]==LOW && current_status[0]==LOW && current_status[1]==LOW && current_status[2]==LOW && current_status[3]==LOW)
Serial.println("keep walking");
else if(current_status[4]==LOW && current_status[5]==LOW)
Serial.println("left 45");
else if(current_status[6]==LOW && current_status[7]==LOW) 
Serial.println("right 45");
else if(current_status[8]==LOW)
Serial.println("left 90");
else if(current_status[9]==LOW)
Serial.println("right 90");
else if(current_status[11]==LOW)
Serial.println("attention");

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
double distance = (duration/2.0) / 29.1;
Serial.println(sensor_no + 1);
Serial.println(distance);
return distance;
}

