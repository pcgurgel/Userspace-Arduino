/*
  PWM
  Turns on RGB LED 
*/		
void setup() {
/* pinMode(3,OUTPUT); */
/* pinMode(5,OUTPUT); */
/* pinMode(6,OUTPUT); */

}

void loop() {
		analogWrite(3,10000);
		delay(1000);
		analogWrite(3,0);
		delay(1000);

		/* analogWrite(5,10000); */
		/* delay(1000); */
		/* analogWrite(5,0); */
		/* delay(1000); */

		/* analogWrite(6,10000); */
		/* delay(1000); */
		/* analogWrite(6,0); */
		/* delay(1000); */
}
