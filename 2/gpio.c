#include <stdio.h>

void gpio_set_direction (int num_of_gpio, char *direction)
{
	FILE *io;

	char path[200];
	sprintf(path, "/sys/class/gpio/gpio%d/direction", num_of_gpio);
	io = fopen(path, "w");
	fseek(io, 0, SEEK_SET);
	fprintf(io, direction);
	fflush(io);
	fclose(io);
}
