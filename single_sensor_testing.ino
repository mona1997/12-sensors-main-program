
const int trigPin1=26; 
const int echoPin1=27;




void setup() {
Serial.begin(9600);

pinMode(trigPin1,OUTPUT);
pinMode(echoPin1,INPUT);

}

void loop() {
bool get_status(int trigPin,int echoPin);
double get_distance(int trigPin,int echoPin);


int current_status=get_status(26,27);
Serial.println("current_status=");
Serial.println(current_status);
delay(2000);
}

// FUNCTIONS//
bool get_status(int trigPin,int echoPin)
{
  double Distance=get_distance(trigPin,echoPin);
  if(Distance>10 && Distance<200)
  return true;
  else return false;
}

double get_distance(int trigPin, int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
double duration = pulseIn(echoPin, HIGH,50000);
double distance;
distance = (duration/2) / 29.1;
Serial.println("distance=");
Serial.println(distance);
return distance;
}
