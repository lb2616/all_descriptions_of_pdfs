obj-m += mymodule.o
mymodule-objs := hello.o test.o
all:
	make -C /home/libo/arm/linux-2.6.32.2/ M=$(PWD) modules
	cp mymodule.ko /tftpboot/
clean:	
	make -C /home/libo/arm/linux-2.6.32.2/ M=$(PWD) clean
	rm $(my_app)  /tftpboot/mymodule.ko
