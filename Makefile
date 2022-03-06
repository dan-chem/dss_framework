################################################
######## Edit variables in this section ########
################################################
CPP = g++

# MACRO DESCRIPTIONS
#
# DEBUG: activates debug mode and shows some additional information
#		use carefully, can cause heavy I/O!
#
# _INTEGRATOR_LENGTH: Gromacs engine: At the moment(!) amount of x values in XVG (Standard value is 1189)
#
# RHO: Gromacs engine: At the moment(!) density of the system to integrate over

CPPFLAGS = -Wall -g -D_INTEGRATOR_LENGTH=1189 -DRHO=0.936
DEBUGFLAGS = #-DDEBUG
LINKFLAGS =
OBJECTS = main.o standardmsg.o gaussianproc.o gromacsproc.o
EXENAME = framework.exe
RM = del

################################################
# Don't edit anything in the following section #
################################################

# Compiler
%.o: %.cpp
	$(CPP) -c -o $@ $< $(CPPFLAGS) $(DEBUGFLAGS)

# Linker
$(EXENAME): $(OBJECTS)
	$(CPP) $(LINKFLAGS) $(OBJECTS) -o $(EXENAME)

# Misc stuff
clean:
	$(RM) *.o $(EXENAME)