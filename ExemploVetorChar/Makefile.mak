CPP    = g++
RM     = rm -f
OBJS   = ExemploVetorChar.o \
         ExemploPonteiro.o

LIBS   =
CFLAGS =

.PHONY: Project.exe clean clean-after

all: Project.exe

clean:
	$(RM) $(OBJS) Project.exe

clean-after:
	$(RM) $(OBJS)

Project.exe: $(OBJS)
	$(CPP) -Wall -s -o $@ $(OBJS) $(LIBS)

ExemploVetorChar.o: ExemploVetorChar.cpp
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)

ExemploPonteiro.o: ExemploPonteiro.cpp
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)

