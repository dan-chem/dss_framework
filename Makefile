################################################
######## Edit variables in this section ########
################################################
CPP = g++
CPPFLAGS = -Wall -g #-DDEBUG
LINKFLAGS =
OBJECTS = main.o standardmsg.o gaussianproc.o
EXENAME = framework.exe
RM = del

################################################
# Don't edit anything in the following section #
################################################

$(EXENAME): $(OBJECTS)
	$(CPP) $(LINKFLAGS) $(OBJECTS) -o $(EXENAME)

%.o: %.cpp
	$(CPP) -c -o $@ $< $(CPPFLAGS)

clean:
	$(RM) *.o $(EXENAME)