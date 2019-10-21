int in=4;
int out=8;
int val= LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(in,INPUT);
  pinMode(out,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  val= digitalRead(in);
  if(val==HIGH)
  digitalWrite(out,HIGH);
  else
  digitalWrite(out,LOW);

}
