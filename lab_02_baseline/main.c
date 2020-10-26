#include <avr/io.h>
#include <util/delay.h>
#include "serial.h"
#include <avr/interrupt.h>
#include "led.h"
#include "timer.h"

#define GREENLED PB1
#define FOSC 16000000                   // Clockfrequency for the ATMegan
#define BAUD 38400                      // The baudrate I want 
#define MYUBRR ((FOSC / 16) / BAUD) -1  // Calculation to get the correct Baudrate for this clockfrequency

volatile uint16_t number_of_times_interrupted = 1;
int counter = 0;


/*
// This is the ISR function that executes on every interrupt. Doesnt have to be called.
// For this deluppgift we will NOT use this ISR interrupt.

ISR(TIMER0_COMPA_vect){                
  if(number_of_times_interrupted < 100){

    number_of_times_interrupted++;
    deactivate_led(PB1);    
  }
  else if(number_of_times_interrupted == 100){

    number_of_times_interrupted = 1;
    activate_led(PB1);    
  }
}
*/

int main (void) {

  //init_led(PB1);          // Init led as output
  //sei();                // For this deluppgift we wont use sei();

  //timer0_init();          // Init Timer0, see timer.c for more comments and calculation.
  
  init_pwm_6();             // Init led on pwm 6 (connected with pin 9 on shield hehe)
  pwm_timer0_init();        // Init fast pwm mode 
  while(1){
    /* 
    DELUPPGIFT 2 
    */
    if(OCR0A >= 100){       // Here we clearly see difference in LED strength as  
                            // it increases towards 100 and then goes to 0
      OCR0A = 0;
    }
    OCR0A++;
    _delay_ms(100);

    /* DELUPPGIFT 1 
    Here is flashing of led with 100ms in while loop without using sei(); 

    if (TIFR0 & (1 << OCF0A)){ // If TIFR0 register has an 1 in index 1 (OCF0A) we enter.
		
      counter++;
      if(counter == 10){  // Now switches every 100 milliseconds
        PORTB ^= (1 << PB1); // Switch led on/off
        counter = 0;
        
      }
			TIFR0 |= (1 << OCF0A); // TIFR0 is the Registry, OCF0A is index in registry.
                             // here we set an 1 to OFC0A (bit 1) index in TIFR0 registry. 
                             // This resets the flag
		}
    */
  }
  return 0;
}
