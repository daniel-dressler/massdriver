all:
	C:\Libraries\gbdk\bin\lcc -Wa-l -c -o test.o test.c
	C:\Libraries\gbdk\bin\lcc -Wa-l -c -o images.o images.c
	C:\Libraries\gbdk\bin\lcc -Wa-l -c -o graphics.o graphics.c
	C:\Libraries\gbdk\bin\lcc -Wl-m -Wl-yp0x143=0x80 -o test.gb test.o images.o graphics.o

