#include "activity3.h"
#include "activity2.h"

void initTimer()
{
    TCCR1A |= (1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
    TCCR1B |= (1<<WGM12)|(1<<CS11)|(1<<CS10);
    DDRB |=(1<<PB1);
}

void Step3_PWM(uint16_t temp)
{
    initTimer();
    if(temp>=0 && temp<=200){
            OCR1A = PWM20PERCENT;
            delay_ms(200);
        }
        else if(temp>=210 && temp<=500){
             OCR1A = PWM40PERCENT;
            delay_ms(200);
        }
        else if(temp>=510 && temp<=700){
             OCR1A = PWM70PERCENT;
            delay_ms(200);
        }
        else if(temp>=710 && temp<=1024){
             OCR1A = PWM95PERCENT;
            delay_ms(200);
        }
        else{
            OCR1A=0;
            delay_ms(200);
        }
}
