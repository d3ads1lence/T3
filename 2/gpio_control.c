#include <stdio.h>
#include <unistd.h>
#include "gpio.h"

void gpio_blink (void);

int main (void)
{
	gpio_set_direction(66, "out");
	while(1){
		gpio_blink();
	}
}



void gpio_blink (void)
{
	FILE *io;

	io = fopen("/sys/class/gpio/gpio66/value", "w");
	fseek(io, 0, SEEK_SET);

	fprintf(io, "%d", 1);
	fflush(io);
	sleep(1);

	fprintf(io, "%d", 0);
	fflush(io);
	sleep(1);

	fclose(io);
}