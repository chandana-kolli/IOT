int potent=0;
int ledpin=11;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin,OUTPUT);
  pinMode(potent,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensedValue=analogRead(potent);
  Serial.print("Sensed value =");
  Serial.println(sensedValue);
  
  int ConValue=map(sensedValue,0,1023,0,255);
  analogWrite(ledpin,ConValue);
  Serial.print("Converted value =");
  Serial.println(ConValue);
  delay(1000);
}
