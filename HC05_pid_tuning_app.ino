#include<SoftwareSerial.h>
SoftwareSerial bluetooth(2,3); 
//defining Rx, Tx pins respectively
String s_differentiating;       
//to check whether the sent value is Kp,Ki or Kd
float val;                      
float kp=0,ki=0,kd=0;
void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);
}
void loop() 
{
  if(bluetooth.available()>1)
  {
    s_differentiating = bluetooth.readStringUntil('*');      
    val = bluetooth.readStringUntil('*').toFloat();
    Serial.println(s_differentiating);
    Serial.println(val);
    if(s_differentiating == "p")    
    {
      kp = val;
      Serial.print("kp ="); 
      Serial.println(kp);
    }
    else if(s_differentiating == "d")    
    {
      kd = val;
      Serial.print("kd ="); 
      Serial.println(kd);
    }
    else    
    {
      ki = val;
      Serial.print("ki ="); 
      Serial.println(ki);
    }
  }
 //put the pid tuning code here
  delay(1000);
}
