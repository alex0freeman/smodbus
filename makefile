#ARCH:=arm-linux-
CC:=$(ARCH)gcc
STRIP:=$(ARCH)strip
TARGET:= modbus-frame.exe

all:$(TARGET)
	$(STRIP) $+
	@ls -lhv $+
modbus-frame.exe: modbus-frame.c test.c
	$(CC) $+ -o $@
clean:
	rm -rfv *.exe
