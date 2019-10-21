int outputpin=0;


void setup(){
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int rawvoltage=analogRead(outputpin);
  float millivolts=(rawvoltage/1034.0)*5000;
  float celsius= millivolts/10;
  Serial.print(celsius);
  Serial.println("Degree celsius");
  Serial.print((celsius*9)/5+32);
  Serial.println("Degree Fahranheit");
  delay(1000);
}
