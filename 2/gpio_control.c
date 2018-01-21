#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <poll.h>
#include "gpio.h"

void gpio_blink (void);

int main (int argc, char *argv[])
{
	int f;
	struct pollfd poll_fds[1];
	int ret;
	char value[4];
	int n;
	gpio_set_interrupt(67);
	gpio_set_direction(66, "out");
	f = open ("/sys/class/gpio/gpio67/value", O_RDONLY | O_NONBLOCK);
	if (f == -1){
		perror("Cant open gpio");
		return 1;
	}
	n = read(f, &value, sizeof(value));
	if (n > 0) {
		lseek(f, 0, SEEK_SET);
	}
	poll_fds[0].fd = f;
	poll_fds[0].events = POLLPRI | POLLERR;
	while(1){
		ret = poll(poll_fds, 1, -1);
		if (ret > 0){
			n = read(f, &value, sizeof(value));
			lseek(f, 0, SEEK_SET);
			gpio_pin_write(66, GPIO_SET);
			sleep(1);
			gpio_pin_write(66, GPIO_RESET);
		}
	}

}

