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
DRAWGARLANDOBJs = drawGarland.o
DRAWCHAOSOBJs = drawChaos.o
DRAWORTHOOBJs = drawOrthoCircle.o

ALLOBJs = $(HELLOOBJs) $(PUBLICOBJ) $(DRAWSINOBJs) $(DRAWRECTOBJs) $(DRAWSINCOBJs) $(DRAWDINOOBJs) $(DRAWGARLANDOBJs) $(CDRAWCHAOSOBJs) $(DRAWORTHOOBJs)

.PHONY: all
all: hello drawSin drawRect drawSinc drawDino drawCircle drawGarland drawChaos drawOrthoCircle

$(ALLOBJs): $(Hs)

hello: $(HELLOOBJs) $(PUBLICOBJ)
drawSin: $(DRAWSINOBJs) $(PUBLICOBJ)
drawCircle: $(DRAWCIRCLEOBJs) $(PUBLICOBJ)
drawSinc: $(DRAWSINCOBJs) $(PUBLICOBJ)
drawRect: $(DRAWRECTOBJs) $(PUBLICOBJ)
drawDino: $(DRAWDINOOBJs) $(PUBLICOBJ)
drawGarland: $(DRAWGARLANDOBJs) $(PUBLICOBJ)
drawChaos: $(DRAWCHAOSOBJs) $(PUBLICOBJ)
drawOrthoCircle: $(DRAWORTHOOBJs) $(PUBLICOBJ)

.PHONY: clean
clean:
	rm -rf *.o hello drawSin drawCircle drawRect drawSinc drawDino *~ *.orig drawGarland drawChaos drawOrthoCircle
