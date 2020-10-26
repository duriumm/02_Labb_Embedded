#ifndef LED_H_
#define LED_H_

void init_led(int indexInRegistry);

void activate_led(int indexInRegistry);

void deactivate_led(int ledToDeactivate);

void toggle_led(int ledToToggle);

//void change_led_ON_or_OFF_based_on_state(STATES currentEnumState);

#endif