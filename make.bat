REM Automatically generated from Makefile
mkdir -p `echo obj\src\gameai.s | rev | cut -d \ -f 2- | rev`
.\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Iasset\ -Isrc\ -S -o obj\src\gameai.s src\gameai.c
.\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Iasset\ -Isrc\ -c -o obj\src\gameai.o obj\src\gameai.s
mkdir -p `echo obj\src\graphics.s | rev | cut -d \ -f 2- | rev`
.\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Iasset\ -Isrc\ -S -o obj\src\graphics.s src\graphics.c
.\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Iasset\ -Isrc\ -c -o obj\src\graphics.o obj\src\graphics.s
mkdir -p `echo obj\src\main.s | rev | cut -d \ -f 2- | rev`
.\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Iasset\ -Isrc\ -S -o obj\src\main.s src\main.c
.\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Iasset\ -Isrc\ -c -o obj\src\main.o obj\src\main.s
mkdir -p `echo obj\src\patterns.s | rev | cut -d \ -f 2- | rev`
.\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Iasset\ -Isrc\ -S -o obj\src\patterns.s src\patterns.c
.\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Iasset\ -Isrc\ -c -o obj\src\patterns.o obj\src\patterns.s
mkdir -p `echo obj\src\sound.s | rev | cut -d \ -f 2- | rev`
.\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Iasset\ -Isrc\ -S -o obj\src\sound.s src\sound.c
.\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Iasset\ -Isrc\ -c -o obj\src\sound.o obj\src\sound.s
mkdir -p `echo obj\src\state.s | rev | cut -d \ -f 2- | rev`
.\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Iasset\ -Isrc\ -S -o obj\src\state.s src\state.c
.\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Iasset\ -Isrc\ -c -o obj\src\state.o obj\src\state.s
mkdir -p `echo obj\asset\images.s | rev | cut -d \ -f 2- | rev`
.\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Iasset\ -Isrc\ -S -o obj\asset\images.s asset\images.c
.\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Iasset\ -Isrc\ -c -o obj\asset\images.o obj\asset\images.s
.\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Iasset\ -Isrc\ -o obj\mass_driver.gb  obj\src\gameai.o  obj\src\graphics.o  obj\src\main.o  obj\src\patterns.o  obj\src\sound.o  obj\src\state.o  obj\asset\images.o
cp obj\mass_driver.gb .\
