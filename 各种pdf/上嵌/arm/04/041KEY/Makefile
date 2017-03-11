CC=arm-linux-
TARGET=key
all:
	
	$(CC)gcc -c start.S -o start.o
	$(CC)gcc -c $(TARGET).c -o $(TARGET).o
	$(CC)ld -Ttext 0x30000000 start.o $(TARGET).o -o $(TARGET)
	$(CC)objcopy -O binary $(TARGET) $(TARGET).bin
	cp $(TARGET).bin /tftpboot/
clean:
	rm $(TARGET) *.o $(TARGET).bin /tftpboot/$(TARGET).bin
