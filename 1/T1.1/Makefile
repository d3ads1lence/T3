.PHONY: host target clean libs

PROG = hello
LIB_HELLO = libhello
LIB_BYE = libgoodbye

ifeq (host,$(filter host,$(MAKECMDGOALS)))
	OUTPUT_DIR = host
	CC = gcc
else ifeq (target,$(filter target,$(MAKECMDGOALS)))
	OUTPUT_DIR := target
	CC = arm-cortex_a8-linux-gnueabihf-gcc
endif

host target: $(PROG)

clean:
	rm -rf host target

libs: $(LIB_HELLO) $(LIB_BYE)

$(LIB_HELLO):	$(LIB_HELLO).c world.h
				$(CC) -c -fPIC -shared $(LIB_HELLO).c -o $(OUTPUT_DIR)/$(LIB_HELLO).o
				$(CC) -shared -o $(OUTPUT_DIR)/$(LIB_HELLO).so $(OUTPUT_DIR)/$(LIB_HELLO).o

$(LIB_BYE): 	$(LIB_BYE).c world.h
				$(CC) -c $(LIB_BYE).c -o $(OUTPUT_DIR)/$(LIB_BYE).o
				ar cr $(OUTPUT_DIR)/$(LIB_BYE).a $(OUTPUT_DIR)/$(LIB_BYE).o

$(PROG).o:		$(PROG).c 
				@mkdir -p $(OUTPUT_DIR)
				$(CC) -o $(OUTPUT_DIR)/$(PROG).o -c $(PROG).c

$(PROG): 		$(PROG).o $(LIB_HELLO) $(LIB_BYE)
				$(CC) -o $(OUTPUT_DIR)/$(PROG) $(OUTPUT_DIR)/$(PROG).o -L./$(OUTPUT_DIR) -lhello -Wl,-rpath,. -L./$(OUTPUT_DIR) -lgoodbye 
	