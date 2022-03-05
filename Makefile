################################################
######## Edit variables in this section ########
################################################
CPP = g++
CPPFLAGS = -Wall -g #-DDEBUG
LINKFLAGS =
OBJECTS = main.o standardmsg.o gaussianproc.o gromacsproc.o
EXENAME = framework.exe
RM = del

################################################
# Don't edit anything in the following section #
################################################

%.o: %.cpp
	$(CPP) -c -o $@ $< $(CPPFLAGS)

$(EXENAME): $(OBJECTS)
	$(CPP) $(LINKFLAGS) $(OBJECTS) -o $(EXENAME)

clean:
	$(RM) *.o $(EXENAME)