#include <avr/io.h>
volatile int adc = ADC;

int main(void){
    DDRB &= ~(1 << PB2);  
    PORTB &= ~(1 << PB2); 
//
    ADMUX &= ~(1 << MUX3); 
    ADMUX &= ~(1 << MUX2); 
    ADMUX &= ~(1 << MUX1); 
    ADMUX |= (1 << MUX0); 
    //Устанавливаем VCC как опорное U:
    ADMUX &= ~(1 << REFS1);
    ADMUX &= ~(1 << REFS0);
//125кГц
    ADCSRA |= (1 << ADCPS0);
    ADCSRA |= (1 << ADCPS1);
    ADCSRA |= (1 << ADCPS2);
    //Разрешение работы АЦП:
    ADCSRA |= (1 << ADEN);
    sei();  
    // Запуск первого преобразования:                            
    ADCSRA |= (1 << ADSC); 
    ISR(ADC_vect) {  // Прерывание при завершении
         adc = ADC;
        ADCSRA |= (1 << ADSC);  // Запуск следующего преобразования

    } 


while(1){
    if(adc < 256){
        //выводим 00 на сетодиодах
    }
    // если от 256 до 512:
    if(){
        //выводим 01 на сетодиодах
    }
    // если от 512 до 768:
    if(){
        //выводим 10 на сетодиодах
    }
    // если от 768 до 1024:
    if(){
        //выводим 11 на сетодиодах
    }
    

}
}
