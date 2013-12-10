CC = g++

LDLIBS +=  -lGLU -lglut -lGL
#LDLIBS +=  -framework OpenGL -framework GLUT

Hs = interface.h vector3f.h

PUBLICOBJ= publicfuncs.o
HELLOOBJs = hello.o
CALULATE_TESTOBJ = calculateTest.o 

ALLOBJs = $(HELLOOBJs) $(PUBLICOBJ) $(CALULATE_TESTOBJ)
.PHONY: all 
all: calculateTest

$(ALLOBJs): $(Hs)

hello: $(HELLOOBJs) $(PUBLICOBJ)
calculateTest: $(CALULATE_TESTOBJ)
 

.PHONY: clean
clean:
	rm -rf *.o hello calculateTest 
