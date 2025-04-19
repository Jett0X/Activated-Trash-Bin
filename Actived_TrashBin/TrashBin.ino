#include <Servo.h>
Servo servo1;

int distanceThreshold = 0;
int cm = 0;
int inches = 0;


long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}
//////////////////////////////////////////////////////////////////////////////////////
void setup()
{
  Serial.begin (9600);       // initialize serial port
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  
  digitalWrite(2, HIGH);
  digitalWrite(8, HIGH);
  
  servo1.attach(9);
  servo1.write(0);
}

void loop()
{
   // set threshold distance to activate LEDs
  distanceThreshold = 300;
  // calculate the distance to the target in cm
  cm = 0.09923 * readUltrasonicDistance(7, 6);
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  Serial.print(cm);
  Serial.print("cm, ");
  Serial.print(inches);
  Serial.println("in");
  if (cm > distanceThreshold){
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(8, HIGH);
    noTone(4);
    ///
    servo1.write(0);
  }
  if (cm <= distanceThreshold && cm > distanceThreshold - 100) {
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(8, HIGH);
    noTone(4);
    ///
    servo1.write(0);
  }
  if (cm <= distanceThreshold - 100 && cm > distanceThreshold - 200) {
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(8, LOW);
    tone(4, 562,4512);
    ///
    servo1.write(90);
  }
  if (cm <= distanceThreshold - 200 && cm > distanceThreshold - 300) {
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(8, LOW);
    tone(4, 562,4512);
    ///
    servo1.write(90);
  }
  if (cm <= distanceThreshold - 300 && cm > distanceThreshold - 300) {
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(8, LOW);
    tone(4, 562,4512);
    ///
    servo1.write(90);
  }
  delay(100); // Wait for 100 millisecond(s)
  //////////////////////////////////////
    Ultrasonic_2();
}
//////////////////////////////////////////////////////////////////////////
//.///////////////////////////////////////////////////////////////////////////////////
long readUltrasonicDistance_2(int triggerPin_2, int echoPin_2)
{
  pinMode(triggerPin_2, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin_2, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin_2, LOW);
  pinMode(echoPin_2, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin_2, HIGH);
}
//////////////////////////
void Ultrasonic_2(){
  // set threshold distance to activate LEDs
  distanceThreshold = 300;
  // calculate the distance to the target in cm
  cm = 0.09923 * readUltrasonicDistance_2(10, 11); //normal cm 0.01739
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  Serial.print(cm);
  Serial.print("cm, ");
  Serial.print(inches);
  Serial.println("in");
  /////////
  if (cm > distanceThreshold) {
    nonLights();
  }
  if (cm <= distanceThreshold && cm > distanceThreshold - 100) {
    nonLights();
  }
  if (cm <= distanceThreshold - 50 && cm > distanceThreshold - 100) {
    nonLights();
  }
  if (cm <= distanceThreshold - 100 && cm > distanceThreshold - 150) {
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(8, LOW);
    tone(4, 562,4512);
  }
  if (cm <= distanceThreshold - 200) {
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(8, LOW);
    tone(4, 562,4512);
  }
  delay(100); // Wait for 100 millisecond(s)
}
///////////////////
void nonLights(){
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(2, LOW);
    digitalWrite(8, LOW);
    noTone(4);
}