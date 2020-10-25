#include <avr/io.h>
#include <util/delay.h>
#include "serial.h"
#include <avr/interrupt.h>
#include "led.h"
#include "timer.h"






int main (void) {

  
  timer0_init();          // Init Timer0, see timer.c for more comments.

  return 0;
}
