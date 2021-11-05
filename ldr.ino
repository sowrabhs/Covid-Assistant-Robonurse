void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(8,OUTPUT);
pinMode(A0,INPUT);
}

void loop() {
  int v=analogRead(A0);
  if (v<=406)
  {digitalWrite(8,HIGH);
  Serial.println("LIGHT ON");
   Serial.println(v);}
  else
  
  {digitalWrite(8,LOW);
  Serial.println("LIGHT OFF");
   Serial.println(v);
  }// put your main code here, to run repeatedly:

}
