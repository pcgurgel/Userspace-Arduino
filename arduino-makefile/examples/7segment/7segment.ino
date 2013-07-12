/*
7segment

Displays digits on 7 segment display on Bacon Board
*/

#define LATCH 10 
#define CLOCK 13
#define DATA 11

/* 
 clk=/sys/class/gpio/gpio2
 serial=/sys/class/gpio/gpio4
 latch=/sys/class/gpio/gpio5
*/
int i;
const byte ledCharSet[10] = {

  B00111111,B00000110,B01011011,B01001111,B01100110,B01101101,B01111101,B00000111,B01111111,B01101111
};

void setup(){
  pinMode(LATCH, 1);
  pinMode(CLOCK, 1);
  pinMode(DATA,1);

}

void loop(){
	 	     i = 0;
    		 /* Serial.println("Seven segment display test"); */
			 while(1){
			 digitalWrite(LATCH,0);
			 shiftOut(DATA,CLOCK,MSBFIRST,~(ledCharSet[i]));
      		 digitalWrite(LATCH,1);
      		 i++;
			  if(i==10){
			  	           i = 0;
	         }
		      delay(500);
}

}
