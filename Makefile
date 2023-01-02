default:
		avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o build/led_binary_counter.o src/led_binary_counter.c
		avr-gcc -o build/led_binary_counter.bin build/led_binary_counter.o
		avr-objcopy -O ihex -R .eeprom build/led_binary_counter.bin build/led_binary_counter.hex
		sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:build/led_binary_counter.hex
