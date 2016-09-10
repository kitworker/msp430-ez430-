#include <msp430f2012.h>

void blinkPort1(char pin, unsigned int  *timeray,  unsigned int value){

// 	static unsigned int timer = 0;
	if((*timeray)-- == 0) {
		P1OUT^= pin;
		*timeray = value;
	}
}
 
 
int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR = 0xFF;
  unsigned int timer1 = 2000;
  unsigned int timer2 = 1000;
  unsigned int timer3 =1500;
  
  while (1)
  {
//   if(--timer1 == 0)  P1OUT^= 0x01;
//   if(--timer2 == 0)  P1OUT^= 0x02;
// if(--timer3 == 0)  P1OUT^= 0x04;
	blinkPort1(0x01, &timer1, 1000);

	blinkPort1(0x02, &timer2, 200);

	blinkPort1(0x04, &timer3, 100);
  
  }
}
