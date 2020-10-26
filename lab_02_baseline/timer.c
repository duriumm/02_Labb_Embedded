#include <avr/io.h>
#include "timer.h"

void timer0_init(){

 
  /*TCCR0A is the Timer/Counter Control Register A which we use to initialize CTC mode
  TCCR0A uses (WGM01 = bit 1) and (WGM00 = bit 0)
  For TCCR0A we have (MAX = 0xFF) and (BOTTOM = 0x00)
  To init CTC mode for TCCR0A we put (WGM01 = 1)*/
  TCCR0A |= (1 << WGM01);
   
  /* Generate an interrupt each time the counter (TCNT0) reaches 156 
  Output Compare Value calculation is: (16 000 000 / (1024 x 100)) – 1 = 155,25 Which is rounded to 155.*/
  OCR0A = 155; 

  /* ENABLE Interrupt for ISR. for this deluppgift we will NOT use ISR*/
  //TIMSK0 = (1 << OCIE0A);
  
  /* initialize the counter */
  TCNT0 = 0;

  /*TCCR0B is the Timer/Counter Control Register B which we use to initialize prescaler. DETTA BORDE GÖRAS SIST TCCR0B
  TCCR0B uses (CS02 = bit 2) and (CS01 = bit 1) and (CS00= bit 0)
  To init prescaler 1024 for TCCR0B we put (CS02 = 1) and (CS00 = 1)*/   
  TCCR0B |= (1 << CS02) | (1 << CS00);
}

void pwm_timer0_init(){

    TCCR0A |= (1 << WGM01) | (1 << WGM00); // Initialize fast pwm mode

    TCCR0A |= (1 << COM0A1); // Non inverting mode

    OCR0A = 0xFF; // Set TOP to 0xFF

    TCCR0B |= (1 << CS01) | (1 << CS00); // Init prescaler 64

    // 16 000 000 / (64 * 256) = 976.5625 ~ 977. PWM frequency is 977.


}

