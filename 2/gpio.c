#include <stdio.h>
#include <errno.h>
#include "gpio.h"

int gpio_set_direction (int num_of_gpio, char *direction)
{
	FILE *io;

	char path[128];
	sprintf(path, "/sys/class/gpio/gpio%d/direction", num_of_gpio);
	io = fopen(path, "w");
	if (io == NULL){
		perror("Error: ");
		return(-1);
	}
	fseek(io, 0, SEEK_SET);
	fprintf(io, direction);
	fflush(io);
	fclose(io);

	return (0);
}

int gpio_pin_write (int num_of_gpio, gpio_state_t state)
{
	FILE *io;

	char path[128];
	sprintf(path, "/sys/class/gpio/gpio%d/value", num_of_gpio);
	io = fopen(path, "w");
		if (io == NULL){
		perror("Error: ");
		return(-1);
	}
	fseek(io, 0, SEEK_SET);
	fprintf(io, "%d", state);
	fclose(io);

	return (0);
}

int gpio_set_interrupt (int num_of_gpio)
{
	FILE *io;

	char path[128];
	sprintf(path, "/sys/class/gpio/gpio%d/edge", num_of_gpio);
	io = fopen(path, "w");
		if (io == NULL){
		perror("Error: ");
		return(-1);
	}
	fseek(io, 0, SEEK_SET);
	fprintf(io, "rising");
	fclose(io);

	return (0);
}