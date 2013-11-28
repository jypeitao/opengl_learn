CC = g++

LDLIBS +=  -lGLU -lglut -lGL
#LDLIBS +=  -framework OpenGL -framework GLUT

Hs = interface.h

PUBLICOBJ= publicfuncs.o
HELLOOBJs = hello.o
DRAWSINOBJs = drawSin.o
DRAWCIRCLEOBJs = drawCircle.o
DRAWSINCOBJs = drawSinc.o
DRAWRECTOBJs = drawRect.o
DRAWDINOOBJs = drawDino.o

ALLOBJs = $(HELLOOBJs) $(PUBLICOBJ) $(DRAWSINOBJs) $(DRAWRECTOBJs) $(DRAWSINCOBJs) $(DRAWDINOOBJs)

.PHONY: all
all: hello drawSin drawRect drawSinc drawDino drawCircle

$(ALLOBJs): $(Hs)

hello: $(HELLOOBJs) $(PUBLICOBJ)
drawSin: $(DRAWSINOBJs) $(PUBLICOBJ)
drawCircle: $(DRAWCIRCLEOBJs) $(PUBLICOBJ)
drawSinc: $(DRAWSINCOBJs) $(PUBLICOBJ)
drawRect: $(DRAWRECTOBJs) $(PUBLICOBJ)
drawDino: $(DRAWDINOOBJs) $(PUBLICOBJ)

.PHONY: clean
clean:
	rm -rf *.o hello drawSin drawCircle drawRect drawSinc drawDino *~ *.orig 
