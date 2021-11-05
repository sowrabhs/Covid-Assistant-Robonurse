#include <Servo.h>
#define ws 2   // water sensor at pin 0
#define ss 3    // sanitizer sensor at pin 1
#define ds 4    // door sensor at pin 2
#define ts 5    // tablet sensor at pin 3
#define wm 8    // water motor relay at pin 8
#define sm 9    // sanitizer motor relay at pin 9
#define dm 10   // door servo motor  at pin 10
#define tm 11 
#define md 12
#define mo 13 // tabletdispenser servo motor  at pin 11


Servo door,tablet;  // create servo object to control a servo


int pos = 0;
int pos1 = 45; 
// variable to store the servo position

void setup() {
pinMode(ws,INPUT);
pinMode(ss,INPUT);
pinMode(ds,INPUT);
pinMode(ts,INPUT);
pinMode(wm,OUTPUT);
pinMode(sm,OUTPUT);


  door.attach(dm);
  tablet.attach(tm);// attaches the servo on pin 9 to the servo object
}

void loop() {
  int a,b,c,d;
 /* if(digitalRead(md)==1)
  {digitalWrite(mo,HIGH);
   delay(5000);
   digitalWrite(mo,LOW);
  }*/
//a=digitalRead(ws);
 if(digitalRead(ws)==0)
 {digitalWrite(wm,HIGH);
 delay(1800);
 digitalWrite(wm,LOW);
 delay(50);}
//b= digitalRead(ss);
  if(digitalRead(ss)==0)
 {digitalWrite(sm,HIGH);
 delay(500);
 digitalWrite(sm,LOW);}
 delay(800);
//c=digitalRead(ds);
 if(digitalRead(ds)==0)
  {for (pos = 0; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    door.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }delay(5000);
  for (pos = 120; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  door.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }
}
  
//d=digitalRead(ts);
 if(digitalRead(ts)==0)
  { for (pos = 0; pos <= 45; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    tablet.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }//delay(5000);
  for (pos = 45; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  tablet.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }}
}/*
    for (pos = 45; pos <= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    tablet.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }delay(5000);
  for (pos1 =0; pos1 >= 45; pos1 += 1) { // goes from 180 degrees to 0 degrees
  tablet.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }
} }*/
