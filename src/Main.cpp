#include <Arduino.h>
#include <Servo.h>

#define trigPin A2
#define echoPin A1

Servo motor[4][3];

int duration = 0;
int distance = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  int cnt = 2;
  for (int i = 0; i < 4; i++)
  {
    for (int q = 0; q < 3; q++)
    {
      motor[i][q].attach(cnt);
      Serial.println("D" + String(cnt));
      cnt++;
    }
    
  }
}

void calc_distance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
}

void stand()
{
  motor[0][0].write(180);
  delay(20);
  motor[1][0].write(0);
  delay(20);
  motor[2][0].write(0);
  delay(20);
  motor[3][0].write(180);
  delay(20);
  motor[0][1].write(90);
  delay(20);
  motor[1][1].write(90);
  delay(20);
  motor[2][1].write(90);
  delay(20);
  motor[3][1].write(90);
  delay(20);
  motor[0][2].write(60);
  delay(20);
  motor[1][2].write(110);
  delay(20);
  motor[2][2].write(110);
  delay(20);
  motor[3][2].write(60);
  delay(20);
}

void sit()
{
  motor[0][1].write(130);
  delay(20);
  motor[0][2].write(30);
  delay(20);
  motor[0][1].write(90);
  delay(500);
  motor[1][1].write(50);
  delay(20);
  motor[1][2].write(150);
  delay(20);
  motor[1][1].write(90);
  delay(500);
  motor[1][1].write(50);
  delay(20);
  motor[1][2].write(150);
  delay(20);
  motor[1][1].write(90);
  delay(500);
  motor[2][1].write(50);
  delay(20);
  motor[2][2].write(30);
  delay(20);
  motor[2][1].write(90);
  delay(500);
  motor[3][1].write(150);
  delay(20);
  motor[3][2].write(150);
  delay(20);
  motor[3][1].write(90);
  delay(500);
}

void wink()
{
  motor[1][1].write(0);
  delay(1000);
  for(int i = 0; i < 3; i++)
  {
    motor[1][0].write(90);
    delay(300);
    motor[1][0].write(0);
    delay(300);
  }
  motor[1][1].write(90);
}

void loop() {
  stand();
  delay(1000);
    calc_distance();
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    wink();
    delay(2000);
    sit();
    while(true) {}
}