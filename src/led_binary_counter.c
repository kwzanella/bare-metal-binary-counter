// Bare-metal 6 bit binary counter with LEDs in ATmega328P

#include <util/delay.h>

#define DDRD  *((volatile char*) 0x2A) // ATmega328P -- 13.4.9 (DDRD – The Port D Data Direction Register)
#define PORTD *((volatile char*) 0x2B) // ATmega328P -- 13.4.8 (PORTD – The Port D Data Register)

int main() {
    DDRD |= 0xFC;  // sets the last 6 bits (11111100)
  
    while(1) {
        for(unsigned char i=0; i <= 63; i++) {  // 2^6 - 1
            PORTD = (i << 2);  // there are no leds connected in the first 2 PORTD pins
            _delay_ms(500);
        }
        _delay_ms(500);
    }
    return 0;
}
