CC := ./gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -Iasset/ -Isrc/

ODIR =obj

SRCS := \
	src/gameai.c \
	src/graphics.c \
	src/main.c \
	src/patterns.c \
	src/sound.c \
	src/state.c \
	asset/images.c
OBJS = $(patsubst %.c, $(ODIR)/%.o, $(SRCS))

$(ODIR)/mass_driver.gb: $(OBJS)
	$(CC) -o $@ $(OBJS)
	cp $(ODIR)/mass_driver.gb ./

make.bat: Makefile
	echo "REM Automatically generated from Makefile" > make.bat
	make -sn | sed y/\\//\\\\/ | grep -v make >> make.bat

$(ODIR)/%.s:	%.c
	mkdir -p `echo $@ | rev | cut -d / -f 2- | rev`
	$(CC) -S -o $@ $<

$(ODIR)/%.o:	$(ODIR)/%.s
	$(CC) -c -o $@ $<

clean:
	rm -rf *.gb $(ODIR)
	
