ifeq ($(OS),Windows_NT)
	CC = C:\Libraries\bin\lcc
else
	CC = ../gbdk/bin/lcc -I../gbdk/include/
endif

all:
	$(CC) -Wa-l -c -o main.o main.c
	$(CC) -Wa-l -c -o state.o state.c
	$(CC) -Wa-l -c -o images.o images.c
	$(CC) -Wa-l -c -o graphics.o graphics.c
	$(CC) -Wa-l -c -o sound.o sound.c
	$(CC) -Wa-l -c -o input.o input.c
	$(CC) -Wa-l -c -o gameai.o gameai.c
	$(CC) -Wl-m -o shmup.gb state.o images.o graphics.o sound.o input.o gameai.o main.o


clean:
	rm -f *.o *.lst *.map *.gb *~ *.rel *.cdb *.ihx *.lnk *.sym *.asm
