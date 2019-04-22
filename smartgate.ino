#include <Servo.h>
Servo myservo1,myservo2;
#define l4 8
#define l5 9
int pos1=0;
int pos2=0;
void setup()
{
myservo1.attach(7);
myservo2.attach(6);
pinMode(l4,INPUT);
pinMode(l5,INPUT);
}
int count=0;
void loop() 
{
  // entry
  if(count<=3)
  {
  if(digitalRead(l4)==LOW)
  {
    gateentry();
    count++;
  }
  }
  //exit
  if(digitalRead(l5)==LOW)
  {
    gateexit();
    count--;
  }

}

void gateentry()
{
    for (pos1 = 0; pos1 <= 90; pos1 += 1) 
    { 
    myservo1.write(pos1);              
    delay(15);                    
    }
    while(digitalRead(l4)!=HIGH);
    delay(2000);
    for (pos1 = 90; pos1 >= 0; pos1 -= 1)
    {
    myservo1.write(pos1); 
    delay(15);  
    }
}

void gateexit()
{
   for (pos2 = 0; pos2 <= 90; pos2 += 1) 
    { 
    myservo2.write(pos2);              
    delay(15);                    
    }
    while(digitalRead(l5)!=HIGH);
    delay(2000);
    for (pos2 = 90; pos2 >= 0; pos2 -= 1)
    {
    myservo2.write(pos2); 
    delay(15);  
    }
  
}
