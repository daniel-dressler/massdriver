ifeq ($(OS),Windows_NT)
	CC = C:\Libraries\bin\lcc
else
	CC = ../gbdk/bin/lcc 
endif

all:
	$(CC) -Wa-l -c -o main.o main.c
	$(CC) -Wa-l -c -o state.o state.c
	$(CC) -Wa-l -c -o images.o images.c
	$(CC) -Wa-l -c -o graphics.o graphics.c
	$(CC) -Wa-l -c -o sound.o sound.c
	$(CC) -Wa-l -c -o input.o input.c
	$(CC) -Wl-m -Wl-yp0x143=0x80 -o shmup.gb main.o state.o images.o graphics.o sound.o input.o


clean:
	rm -f *.o *.lst *.map *.gb *~ *.rel *.cdb *.ihx *.lnk *.sym *.asm
