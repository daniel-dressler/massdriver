ifeq ($(OS),Windows_NT)
	CC = C:\Libraries\bin\lcc -Wa-l -Wl-m Wl-j
else
	CC = ./gbdk/bin/lcc -Wa-l -Wl-m -Wl-j
endif


BINS	= main.gb

all:	$(BINS)

make.bat: Makefile
	echo "REM Automatically generated from Makefile" > make.bat
	make -sn | sed y/\\//\\\\/ | grep -v make >> make.bat

%.o:	%.c
	$(CC) -c -o $@ $<

%.s:	%.c
	$(CC) -S -o $@ $<

%.o:	%.s
	$(CC) -c -o $@ $<

%.gb:	%.o
	$(CC) -o $@ $<

clean:
	rm -f *.o *.lst *.map *.gb *~ *.rel *.cdb *.ihx *.lnk *.sym *.asm
	
