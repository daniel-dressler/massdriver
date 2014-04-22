Mass Driver
===========

A shoot-em-up space shooter for the original gameboy. Gameplay is focused on
fast difficult dodging, shooting, and when you die: instant restart.

### Gameplay

Rounds start with a medium boss flying circles while light
attackers shoot and dive bomb you. If you manage to destroy
the medium boss the fight turns to the main boss.

Mass Driver is a hard to master game. Everytime I return
I find myself relearing my reflexes. Doing well is a product
of skill which you must relearn during each session.

In Mass Driver you start with 5 lives and killing the most
medium and heavy bosses with those lives is your measure of skill.

* Main stage with medium boss
![Main stage medium boss fight](https://i.imgur.com/mYrkEFx.png)

* Main Boss fight
![Boss stage fight](https://i.imgur.com/iukJXLR.png)


### Compilation

Mass Driver uses the GBDK compiler. We've developed against
GBDK 2.95-3 and 2.96a. It should work against newer versions
of GBDK provided these contain fewer compiler bugs.

GBDK requires the environmental variable "GBDKHOME" to be set
to the full path of the GBDK compiler. Our make file then
reuses this envar.

If you do not set "GBDKHOME" you will get errors where make
cannot find the compiler.

__Linux__
* `make`

### Development

Mass Driver is written in C against the GBDK compiler. This
compiler is old and often produces incorrect code. When you
write code make sure to test often. Avoid writing large chunks
of code between play tests. If you do encounter mysterious bugs
try isolating the broken section rewriting it.

In far too many cases rewriting a section to a logical equivalent
has avoided incorrect code generation. Even something simple
like applying De'Morgan's law to a conditional has fixed bugs.

### Credit

I would like to thank Chris Antonellis for his
[GBTDG](http://www.chrisantonellis.com/gameboy/gbtdg/)
image converter. We used it to convert most of the bitmaps in
Mass Driver.

I would also like to thank Dr. Aycock for teaching [CPSC
599.82](http://pages.cpsc.ucalgary.ca/~aycock/599.82/). Mass Driver
was developed as our group project for 599.82 and I appreciated the
opportunity to demo our game to our classmates.

My group consisted of myself, Daniel, Phil, and Ryan. Both Phil
and Ryan are grade A+++ programmers and I am proud to have had the
chance to work with them.
