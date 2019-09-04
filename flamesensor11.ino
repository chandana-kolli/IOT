int buzzer=13;
int flamepin=2;
int flame=HIGH;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer,OUTPUT);
  pinMode(flamepin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  flame=digitalRead(flamepin);
  if (flame==LOW)
  {
    Serial.println("High flame");
    digitalWrite(buzzer,HIGH);
  }
  else
  {
    Serial.println("No flame");
    digitalWrite(buzzer,LOW);
  }
}
