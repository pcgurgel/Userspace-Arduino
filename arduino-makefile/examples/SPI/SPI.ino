/*
  12 bit ADC - MCP3202

  created 19 Aug 2013
  by Anuj Deshpande
*/

#include<SPI.h>
#define SS 4
typedef uint_8 byte;
void setup()
{
  pinMode(SS,OUTPUT);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(MSBFIRST);
  digitalWrite(SS,LOW);

}
void loop()
{
  byte b ; 
  digitalWrite(SS,HIGH);
  b = SPI.transfer(0b11000000);
  printf("%d \n",b);
  digitalWrite(SS,LOW);
  delay(200);
  }
