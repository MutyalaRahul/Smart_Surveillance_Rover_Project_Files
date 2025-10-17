#include <msp430.h>

#define TRIG BIT4
#define ECHO BIT5
#define IN1 BIT6
#define IN2 BIT7
#define IN3 BIT0
#define IN4 BIT1

volatile unsigned int distance = 0;

void delay_us(unsigned int us) {
    while(us--) __delay_cycles(1); // 1us delay @1MHz
}

void trigger_ultrasonic() {
    P1OUT |= TRIG;
    delay_us(10);
    P1OUT &= ~TRIG;
}

unsigned int measure_distance() {
    unsigned int count = 0;
    trigger_ultrasonic();
    while(!(P1IN & ECHO)); // wait for echo start
    while(P1IN & ECHO) { count++; __delay_cycles(10); } // measure pulse width
    distance = count / 58; // approximate cm
    return distance;
}

void forward() {
    P1OUT |= IN1;
    P1OUT &= ~IN2;
    P2OUT |= IN3;
    P2OUT &= ~IN4;
}

void stop() {
    P1OUT &= ~(IN1 | IN2);
    P2OUT &= ~(IN3 | IN4);
}

void turn_right() {
    P1OUT |= IN1;
    P1OUT &= ~IN2;
    P2OUT &= ~(IN3);
    P2OUT |= IN4;
}

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;

    P1DIR |= TRIG + IN1 + IN2;
    P2DIR |= IN3 + IN4;
    P1DIR &= ~ECHO;

    while(1) {
        unsigned int dist = measure_distance();

        if(dist > 30)
            forward();
        else if(dist > 15 && dist <= 30)
            turn_right();
        else
            stop();

        __delay_cycles(50000);
    }
}
