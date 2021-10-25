############################ object declaration ############################

MODULE_NAME := ghost

obj-m += $(MODULE_NAME).o

OBJ := memutil.o regset.o taskutil.o ghost_main.o address_space.o networking.o 

$(MODULE_NAME)-y := $(patsubst %.o, src/%.o, $(OBJ))

############################ directories ############################



KDIR := /lib/modules/$(shell uname -r)/build #kernel source

BUILD_DIR := $(PWD)/bin #output directory

############################ options ############################

VICTIM_FILE := /home/mineo333/libc-2.33.so # #change this to change the target file

############################ Kbuild options ############################

CFLAGS_MODULE := -I$(PWD)/include/e1000 -I$(PWD)/include -DVICTIM_FILE=$(VICTIM_FILE) #this is an env variable for the CFLAGS

KBUILD_OUTPUT:= $(PWD)/bin


all:
	@echo $($(MODULE_NAME)-y)
	make -C $(KDIR) M=$(PWD) modules
	mv src/*.o ghost.mod* modules.order ghost.o $(BUILD_DIR)
clean:
	rm -f $(PWD)/ghost.ko/
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
