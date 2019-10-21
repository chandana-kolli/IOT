
#define ledPin 13
int state;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  Serial.println("Enter AT Commands");
}
void loop() 
{
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    Serial.println(Serial.read());
    state=Serial.read();
  }
  if(state=='0')
  {
    digitalWrite(ledPin, LOW); // Turn LED OFF
    Serial.println("LED: OFF"); // Send back, to the phone, the String "LED: ON"
  }
  else
  {
    digitalWrite(ledPin, HIGH); // Turn LED OFF
    Serial.println("LED: ON");
  }
 
}
