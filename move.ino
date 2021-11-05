#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enA 10
#define enB 5
#define SL 2
#define SR 3

 
 void setup() {

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

    pinMode(enA,OUTPUT);
    pinMode(enB,OUTPUT);

      pinMode(SL, INPUT); // initialize Left sensor as an input
      pinMode(SR, INPUT); // initialize Right sensor as an input

}

void loop() {

  int LEFT_SENSOR = digitalRead(SL);
  int RIGHT_SENSOR = digitalRead(SR);

if(RIGHT_SENSOR==0 && LEFT_SENSOR==0) {
    forward(); //FORWARD
}

  else if(RIGHT_SENSOR==1 && LEFT_SENSOR==0) {
    right(); //Move Right
 }

  else if(RIGHT_SENSOR==0 && LEFT_SENSOR==1) {
    left(); //Move Left
}

  else if(RIGHT_SENSOR==1 && LEFT_SENSOR==1) {
    Stop();  //STOP
 }
}



void forward()
{
      
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);

               
}

void backward()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);

                
}

void right()
{
              digitalWrite(in1,HIGH);
            digitalWrite(in2,LOW);
            digitalWrite(in3,LOW);
            digitalWrite(in4,LOW);

                
}


void left()
{
            digitalWrite(in1,LOW);
            digitalWrite(in2,LOW);
            digitalWrite(in3,HIGH);
            digitalWrite(in4,LOW);
                
}

void Stop()
{
            
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, LOW);
}
