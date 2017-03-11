CC=arm-linux-
TARGET=bl
all:
	$(CC)gcc -c $(TARGET).c -o $(TARGET).o
	$(CC)ld -Ttext 0x30000000 $(TARGET).o -o $(TARGET)
	$(CC)objcopy -O binary $(TARGET) $(TARGET).bin
	cp $(TARGET).bin /tftpboot/
clean:
	rm $(TARGET) $(TARGET).o $(TARGET).bin /tftpboot/$(TARGET).bin
