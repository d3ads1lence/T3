.PHONY: host target clean libs

PROG = hello
LIB_HELLO = libhello
LIB_BYE = libgoodbye
CC = gcc
OUTPUT_DIR = default_folder

host: OUTPUT_DIR = host
host: $(OUTPUT_DIR)
host: CC = gcc
host: $(PROG)

target:	OUTPUT_DIR = target
target:	$(OUTPUT_DIR) 
target: CC = ~/x-tools/arm-cortex_a8-linux-gnueabihf/bin/arm-cortex_a8-linux-gnueabihf-gcc 
target:	$(PROG)

$(OUTPUT_DIR):
	@mkdir -p $(OUTPUT_DIR)

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
				$(CC) -o $(OUTPUT_DIR)/$(PROG).o -c $(PROG).c

$(PROG): 		$(PROG).c  $(PROG).o $(LIB_HELLO) $(LIB_BYE)
				$(CC) -o $(OUTPUT_DIR)/$(PROG) $(OUTPUT_DIR)/$(PROG).o -L./$(OUTPUT_DIR) -lhello -Wl,-rpath,. -L./$(OUTPUT_DIR) -lgoodbye 
	
