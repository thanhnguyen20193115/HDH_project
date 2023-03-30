# Hello world kernel module
# Paths
BBB_KERNEL := /home/phong/working_space/Linux-Porting-N-System/BBB/bb-kernel/KERNEL
TOOLCHAIN := /home/phong/working_space/Linux-Porting-N-System/BBB/gcc-linaro-6.5.0-2018.12-x86_64_arm-linux-gnueabihf/bin

# Toolchain
PREFIX := arm-linux-gnueabihf-
CC := $(TOOLCHAIN)/$(PREFIX)gcc

all:
	make ARCH=arm CROSS_COMPILE=$(TOOLCHAIN)/$(PREFIX) -C $(BBB_KERNEL) M=$(shell pwd) modules
	$(CC) -o app usr_app.c

clean:
	make -C $(BBB_KERNEL) M=$(shell pwd) clean
	rm -rf app
