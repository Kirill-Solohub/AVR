/*
 * File     : int0.c
 * Project  : LangC_MCU/15_interrups/int0
 * MCU      : attiny85/attiny25
 *
 */

// #define F_CPU 1000000UL
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#define LED1_PIN PB5  //  PB0
#define B PD5 

#define DELAY 50

volatile int countEnc = 0;

int main(void) {
  // set led pins as output
  DDRB |= (1 << LED1_PIN);  // set pins as output


  // setup interupt INT0
  EICRA |= 1 << ISC00;
  EICRA &= ~(1 << ISC01);
  EIMSK |= 1 << INT0;
  sei();


  while (1) {
   
  }
}

ISR(INT0_vect) {  //тут пишем, что делать при прерывании
    countEnc++;
  if(PIND & (1 << B))
    PORTB ^= (1 << LED1_PIN); 

}