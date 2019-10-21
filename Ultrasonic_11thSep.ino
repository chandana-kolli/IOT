#include <LiquidCrystal.h>

const int TRIG_PIN=3;
const int ECHO_PIN=2;
int Buzzer=13;
LiquidCrystal lcd(8,9,4,5,6,7);

void setup() {
  // put your setup code here, to run once:
 lcd.begin(16,2);
 lcd.setCursor(0,0);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  long duration,inches,cm;
  lcd.setCursor(0,1);

  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  pinMode(ECHO_PIN, INPUT);
  duration= pulseIn(ECHO_PIN, HIGH);
  inches= microsecondsToInches(duration);
  cm= microsecondsToInches(duration);

  if(cm<15)
  {
    digitalWrite(Buzzer,HIGH);
  }

  lcd.println(inches);
  lcd.print("in, ");
  lcd.println(cm);
  lcd.print("cm, ");
  Serial.print(inches);
  Serial.println("in, ");
  Serial.print(cm);
  Serial.println("cm, ");
  delay(1000);
}
  
  long microsecondsToInches(long microseconds)
  {
    return microseconds/74/2;
  }

  long microsecondsToCentimeters(long microseconds)
  {
    return microseconds/29/2;
  }

  
