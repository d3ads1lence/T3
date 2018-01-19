.PHONY: all clean
CC = ~/x-tools/arm-cortex_a8-linux-gnueabihf/bin/arm-cortex_a8-linux-gnueabihf-gcc 
PROG = gpio_control
LIB = gpio

all: $(PROG)

clean:
	rm -rf *.o $(PROG)

$(LIB).o: $(LIB).c
	$(CC) -o $(LIB).o -c $(LIB).c

$(PROG).o: $(PROG).c 
	$(CC) -o $(PROG).o -c $(PROG).c

$(PROG): $(PROG).o $(LIB).o
	$(CC) -o $(PROG) $(PROG).o $(LIB).o