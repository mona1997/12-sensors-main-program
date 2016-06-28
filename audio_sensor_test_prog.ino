// audio_sensor_test_program

#include "SD.h" 
 #define SD_ChipSelectPin 53 
 #include "TMRpcm.h"
 #include "SPI.h"
 TMRpcm tmrpcm;
 
const int echoPin =27;// Echo Pin
const int trigPin =26;// Trigger Pin

double maximumRange = 200.0; // Maximum range needed
double minimumRange = 10.0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
  Serial.begin(115200);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
  tmrpcm.speakerPin = 5; 
 
  if (!SD.begin(SD_ChipSelectPin)) 
  { Serial.println("SD fail"); 
  return;
  } 
}  
   
 


void loop() {
  bool get_status(int trigPin,int echoPin);
  double get_distance(int trigPin, int echoPin);
  
 Serial.print("status:");
 Serial.print(get_status(trigPin,echoPin));
 Serial.print("distance:");
 Serial.print(get_distance(trigPin,echoPin));
 if(get_status(trigPin,echoPin))
 {
 tmrpcm.play("greek.wav");
 }
  delay(5000);
}

// FUNCTIONS//
bool get_status(int trigPin,int echoPin)
{
 double Distance = get_distance(trigPin, echoPin);
  if(Distance>10 && Distance<200)
  return 1;
else return 0;
}

double get_distance(int trigPin, int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
double duration = pulseIn(echoPin, HIGH,50000);
double distance = (duration*17)/1000;
return distance;
}
