/*
  12 bit ADC - MCP3202

  created 19 Aug 2013
  by Anuj Deshpande
*/

#include<SPI.h>

void setup()
{
		SPI.begin();
}

void loop()
{
		char b ; 
		b = SPI.transfer();
		printf("%c\n",b);
}
