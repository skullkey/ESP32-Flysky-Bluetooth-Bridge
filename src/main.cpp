#include <Arduino.h>
#include <BleGamepad.h>
#include <IBusBM.h> 

BleGamepad bleGamepad;
IBusBM IBus;    // IBus object
#define PPM_LOW 988
#define PPM_HI  2012
#define PPM_MID 1500

void setup() 
{
  Serial.begin(115200);
  bleGamepad.begin(8);
IBus.begin(Serial2,1,16);
}

int map_channel(int channel){
  int ppm = IBus.readChannel(channel); // get latest value for servo channel 1
  return map(ppm,PPM_LOW,PPM_HI,-127*256,128*256-1);
}

void map_button(int channel, int button){
  int ppm = IBus.readChannel(channel); // get latest value for servo channel 1
  if(ppm > PPM_MID)
      bleGamepad.press(button);
  else 
      bleGamepad.release(button);    
}

void loop() 
{
  if(bleGamepad.isConnected()) 
  {    
 
  bleGamepad.setAxes(map_channel(0),map_channel(1),map_channel(2),map_channel(3));
  for(int i=0; i<4; i++)
       map_button(i+4, i+1);
  delay(100); 
  }
}