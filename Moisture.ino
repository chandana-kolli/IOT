#include<Servo.h>
Servo s;
int input=0;
  int output=9;
  
 void setup() {
  // put your setup code here, to run once:
  pinMode(input,INPUT);
  pinMode(output,OUTPUT);
  s.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value=analogRead(input);
  Serial.println(value);
  delay(100);
 int threshold= 500;
  if(value>threshold){
  for(int i=0;i<180;i++)
  {
    s.write(i);
    delay(30);
  }
  for(int i=180;i>0;i--)
  {
    s.write(i);
    delay(30);
 }
}
}
