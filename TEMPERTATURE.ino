#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 
char auth[] = " jnxchyBR12tnZUR3ajMZT3x1Kpgxc80k";
char ssid[] = "TP-Link_D4B7";
char pass[] = "essgroup";

#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

float ambient_temp = 0.0;
float object_temp  = 0.0;

BlynkTimer timer;

void sensor1(){
  ambient_temp = mlx.readAmbientTempC();
  Serial.print("Ambient Temp = ");
  Serial.println(ambient_temp);
  Blynk.virtualWrite(V4,ambient_temp); 
  object_temp = mlx.readObjectTempC()+3;
  Serial.print("Object Temp = ");
  Serial.println(object_temp);
  Blynk.virtualWrite(V5,object_temp); 
}
int flag=0;
void PATIENTOUT()
{
  int isButtonPressed =digitalRead(D6);
    Serial.println(isButtonPressed);
  if (isButtonPressed==1 /*&& flag==0*/) {
    Serial.println("PATIENT OUTSIDE WARD");
     Blynk.notify("Alert : PATIENT OUTSIDE WARD");
  // flag=1;
    }
   else if (isButtonPressed==0)
  {
    flag=0;
  }
}
void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit MLX90614 test");
  Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  mlx.begin();
  timer.setInterval(300L,sensor1);
  pinMode(D6,INPUT);
timer.setInterval(1000L,PATIENTOUT);
 }
void loop() {
  Blynk.run();
  timer.run();
}
