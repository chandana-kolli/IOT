int input=A0;
  int ledpin=13;
  void setup() {
  // put your setup code here, to run once:
  pinMode(0,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
   int value=analogRead(value);
   Serial.println(value);
   delay(1000);
   int threshold= 100;
   if (value<threshold)
   digitalWrite(ledpin,HIGH);
   else
   digitalWrite(ledpin,LOW);
}
