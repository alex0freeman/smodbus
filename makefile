modbus-frame.exe: modbus-frame.c test.c
	gcc $+ -o $@
clean:
	rm -rfv *.exe
