#ifndef GPIO_H_
#define GPIO_H_

typedef enum {
	GPIO_RESET = 0,
	GPIO_SET
}gpio_state_t;

int gpio_set_direction (int num_of_gpio, char *direction);
int gpio_pin_write (int num_of_gpio, gpio_state_t state);
int gpio_set_interrupt (int num_of_gpio);

#endif /* GPIO_H_ */