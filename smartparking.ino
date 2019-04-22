#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
#define l1 2
#define l2 3
#define l3 4
int pos1 = 0;
int pos2 = 0;   
int pos3 = 0;
//LED A1 AT PIN A0
//LED A2 AT PIN A1
//LED A3 AT PIN A2
void setup() 
{
pinMode(l1,INPUT);
pinMode(l2,INPUT);
pinMode(l3,INPUT);
analogWrite(6,20);
lcd.begin(16,2);
}

void loop() 
{ 
      int count;
      count=pos1+pos2+pos3;
   if(count<=3)
   {  
    if(digitalRead(l1)==HIGH)
    {
      analogWrite(A2,140);
      pos1=0;
    }
    else
    {
      analogWrite(A2,0);
      pos1=1;
    }

    if(digitalRead(l2)==HIGH)
    {
      analogWrite(A0,140);
      pos2=0;
    }
    else
    {
      analogWrite(A0,0);
      pos2=1;
    }

    if(digitalRead(l3)==HIGH)
    {
      analogWrite(A1,140);
      pos3=0;
    }
    else
    {
      analogWrite(A1,0);
      pos3=1;
    }
   }
   else{
   }
      lcd.setCursor(1,0);
      lcd.print("PARKING STATUS:");
      lcd.setCursor(0,1);
      if(count==3)
      {
       lcd.print("SORRRY BUT FULLL");
      }
      if(count==2)
      {
        if(pos1==0)
          lcd.print("HURRAY 1 FREEE");
        if(pos2==0)
          lcd.print("HURRAY 2 FREEE");
        if(pos3==0)
          lcd.print("HURRAY 3 FREEE");
      }
      if(count==1)
      { 
        if(pos1==0&&pos2==0)
        lcd.print("HURRAY 1,2 FREEE");
        if(pos1==0&&pos3==0)
        lcd.print("HURRAY 1,3 FREEE");
        if(pos3==0&&pos2==0)
        lcd.print("HURRAY 2,3 FREEE");
      }
      if(count==0)
      {
        
        lcd.print("ALL SLOTS FREE");
      }
     
   
}
    
