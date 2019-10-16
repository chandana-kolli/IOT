#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);
int led=12;
void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
  pinMode(led,OUTPUT);
}


void loop()
{
  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 's':
      SendMessage();
      break;
    case 'r':
      RecieveMessage();
      break;
  }

 if (mySerial.available()>0)
   Serial.write(mySerial.read());
}


 void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919686744132\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("hiii!!");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
void work()
{
  if(mySerial.available())
  {
    String message =mySerial.readString();
    Serial.println(message);
    if(message.indexOf("ON")>0)
    {
    digitalWrite(led,HIGH);
  }
  else if(message.indexOf("OFF")>0)
  {digitalWrite(led,LOW);}
  }
  else
  {Serial.println("Nothing");}
}

 void RecieveMessage()
{
  mySerial.println("AT+CNMI=2,2,0,0,0");
  // AT Command to receive a live SMS
  work();
  /*if(mySerial.available())
  {
    String message =mySerial.readString();
    Serial.println(message);
    if(message.indexOf("ON")>0)
    {
    digitalWrite(led,HIGH);
  }
  else if(message.indexOf("OFF")>0)
  {digitalWrite(led,LOW);}
  }
  else
  {Serial.println("Nothing");}*/
  
  delay(1000);
 }
