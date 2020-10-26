#include <avr/io.h>
#include <util/delay.h>
#include "serial.h"
#include <avr/interrupt.h>
#include "led.h"
#include "timer.h"


int main (void) {

  /* Init led on pwm 6 */
  init_pwm_6();            

  /* Init fast pwm mode */
  pwm_timer0_init();        

  /* Initialize timer2 */
  ctc_timer2_init();
  
  while(1){
    /* If TIFR2 register has an 1 in index 1 (OCF2A) we enter. */
    if (TIFR2 & (1 << OCF2A)){  
      
      /* Returns a uint8_t value that increments/decrements inside function.
      This value makes out LED pulse since we increment or decrement OCR0A which is our TOP value
      So basically we raise the ROOF or lower the ROOF */
      OCR0A = simple_ramp();    

      /* This resets the flag */
      TIFR2 |= (1 << OCF2A);    
		}
  }
  
  return 0;
}
