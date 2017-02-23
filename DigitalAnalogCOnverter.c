#include "DigitalAnalogConverter.h"
#include "..//tm4c123gh6pm.h"


void DAC_Init(void){
	unsigned long volatile delay;
	SYSCTL_RCGC2_R |= 0x00000002; // activate port B
  delay = SYSCTL_RCGC2_R;    // allow time to finish activating
  GPIO_PORTB_AMSEL_R &= ~0x0F;      // no analog 
  GPIO_PORTB_PCTL_R &= ~0x00000FFF; // regular function
  GPIO_PORTB_DIR_R |= 0x0F;      // make PB3-0 out
  GPIO_PORTB_AFSEL_R &= ~0x0F;   // disable alt funct on PB3-0
  GPIO_PORTB_DEN_R |= 0x0F;      // enable digital I/O on PB3-0

}


// **************DAC_Out*********************
// output to DAC
// Input: 4-bit data, 0 to 15 
// Output: none
void DAC_Out(unsigned long data){
	
  GPIO_PORTB_DATA_R = data;

}


