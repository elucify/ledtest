//We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin  9 is connected to the DataIn 
 pin 10 is connected to the CLK 
 pin 11 is connected to LOAD/~CS
 We have only a single MAX72XX.
 LedControl(DataIn, CLK, Load)
 */
 
#define LC_DIN (13)
#define LC_CLK (11)
#define LC_LOAD (12)

LedControl lc=LedControl(LC_DIN, LC_CLK, LC_LOAD, 1);

/* we always wait a bit between updates of the display */
unsigned long delaytime=250;

void setup() {
  Serial.begin(9600);

  Serial.println("Setup");
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}


/*
 This method will display the characters for the
 word "Arduino" one after the other on digit 0. 
 */
void writeArduinoOn7Segment() {     
  lc.setChar(0,0,'a',false);
  delay(delaytime);
  lc.setRow(0,0,0x05);
  delay(delaytime);
  lc.setChar(0,0,'d',false);
  delay(delaytime);
  lc.setRow(0,0,0x1c);
  delay(delaytime);
  lc.setRow(0,0,B00010000);
  delay(delaytime);
  lc.setRow(0,0,0x15);
  delay(delaytime);
  lc.setRow(0,0,0x1D);
  delay(delaytime);
  lc.clearDisplay(0);
  delay(delaytime);
} 

void countDown()
{
  for (int i = 16; i >= 0; i--) {
    Serial.println(i);
    lc.setChar(0,7,i,false);
    delay(delaytime);
  }
}

void countUp()
{
  for (int i = 0; i < 16; i++) {
    Serial.println(i);
    lc.setChar(0,,i,false);
    delay(delaytime);
  }
}

void spinall() {
  for (int i = 0; i <= 0xff; i++) {
    Serial.print("Spin: ");
    Serial.println(i);
    lc.setRow(0,0,i);
    delay(delaytime / 4);
  }
}


void loop() { 
 // writeArduinoOn7Segment();
  countUp();
  countDown();
  spinall();
}
