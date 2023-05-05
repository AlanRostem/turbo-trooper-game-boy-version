#
# Simple Makefile that compiles all .c and .s files in the same folder
#

# Include paths

INC = -I/opt/gbdk/include

# If you move this project you can change the directory 
# to match your GBDK root directory (ex: GBDK_HOME = "C:/GBDK/")

LCC = /opt/gbdk/bin/lcc 

# You can uncomment the line below to turn on debug output
# LCC = $(LCC) -debug

# You can set the name of the .gb ROM file here
PROJECTNAME    = TurboTrooper

BINS	    = $(PROJECTNAME).gb
CSOURCES   := $(wildcard *.c)
ASMSOURCES := $(wildcard *.s)

all:	$(BINS)

compile.bat: Makefile
	@echo "REM Automatically generated from Makefile" > compile.bat
	@make -sn | sed y/\\//\\\\/ | sed s/mkdir\ \-p/mkdir/ | grep -v make >> compile.bat

# Compile and link all source files in a single call to LCC
$(BINS):	$(CSOURCES) $(ASMSOURCES)
	$(LCC) -o $@ $(CSOURCES) $(ASMSOURCES)

clean:
	rm -f *.o *.lst *.map *.gb *.ihx *.sym *.cdb *.adb *.asm

