#include <PID_v1.h>

double sp,setpoint,input,in,out,output;
int sal,val;
PID pendulo(&in,&out,&sp,10.57,8192,0.01,DIRECT);


void setup() {
  // put your setup code here, to run once:
    delay(3000);
    setpoint=analogRead(0);
   sp=0;
    Serial.begin(9600);
    Serial.println(sp);
    pendulo.SetSampleTime(20);
    pendulo.SetMode(AUTOMATIC);
    pendulo.SetOutputLimits(-255,255);

}

void loop() {
  // put your main code here, to run repeatedly:

    input=analogRead(0);
    val=setpoint-input;
    in= val;
    pendulo.Compute();
    if (abs(val) > 0){
        if(val > 0){
          sal=12;
          digitalWrite(13,LOW);
         }else{
            sal=13;
          digitalWrite(12,LOW);  
          }
      
      
    output = abs(out);
    analogWrite(sal,output);
    } else    {
       digitalWrite(12,LOW);   
      digitalWrite(13,LOW);
      
      }

        Serial.print(setpoint);
        Serial.print("");
        Serial.print(in);
        Serial.print("");
        Serial.println(output);
        
          



}
