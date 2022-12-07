
//for v1.6, you may download this library from http://pcsx2.net/download/releases.html

#include<PS2X_lib.h>
#include<Servo.h>

PS2X ps2x; // create PS2 Controller Class

int error = 0; byte type = 0; byte vibrate = 0;   
int pos=0;
int pos1=0;

Servo s1, s2; 
void setup(){

Serial.begin(57600);

s1.attach(6); s2.attach(5);
s1.write(90); s2.write(90);

error = ps2x.config_gamepad(13,11,10,12, true, true);

if(error == 0){

Serial.println("Found Controller, configured successful");

} 
else
{
Serial.println("Error!");
}

}

void loop()
{ 
  if(error == 1) //skip loop if no controller found
 { 
   Serial.println("No Controller Found,check wiring");
   return;
 }

  ps2x.read_gamepad();
if(ps2x.Button(PSB_PAD_RIGHT) && pos<= 180)
{
    pos=pos+10;
    s1.write(pos);
}
if(ps2x.Button(PSB_PAD_LEFT) && pos>=0)
{
   pos=pos-10;
   s1.write(pos);
}

if(ps2x.Button(PSB_PAD_UP)&& pos1<=180)
{
   pos=pos+10;
   s2.write(pos);
}
if(ps2x.Button(PSB_PAD_DOWN) && pos1>=0)
{
  pos=pos-10;
  s2.write(pos);
}
delay(50);

}



