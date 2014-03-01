all:
	C:\Libraries\gbdk\bin\lcc -Wa-l -c -o main.o main.c
	C:\Libraries\gbdk\bin\lcc -Wa-l -c -o state.o state.c
	C:\Libraries\gbdk\bin\lcc -Wa-l -c -o images.o images.c
	C:\Libraries\gbdk\bin\lcc -Wa-l -c -o graphics.o graphics.c
	C:\Libraries\gbdk\bin\lcc -Wa-l -c -o sound.o sound.c
	C:\Libraries\gbdk\bin\lcc -Wl-m -Wl-yp0x143=0x80 -o shmup.gb main.o state.o images.o graphics.o sound.o

