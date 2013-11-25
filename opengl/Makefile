CC = g++

LDLIBS +=  -lGLU -lglut -lGL
#LDLIBS +=  -framework OpenGL -framework GLUT

Hs = interface.h

PUBLICOBJ= publicfuncs.o
HELLOOBJs = hello.o
DRAWSINOBJs = drawSin.o
DRAWRECTOBJs = drawRect.o
DRAWNEWOBJs = drawNew.o

DRAWHAILOBJs = drawHail.o
BINGBAOOBJs = bingbao.o

ALLOBJs = $(HELLOOBJs) $(PUBLICOBJ) $(DRAWSINOBJs) $(DRAWRECTOBJs) $(DRAWNEWOBJs) $(BINGBAOOBJs) $(DRAWHAILOBJs)

.PHONY: all
all: hello drawSin drawRect drawNew bingbao drawHail

$(ALLOBJs): $(Hs)

hello: $(HELLOOBJs) $(PUBLICOBJ)
drawSin: $(DRAWSINOBJs) $(PUBLICOBJ)
drawRect: $(DRAWRECTOBJs) $(PUBLICOBJ) 
drawNew: $(DRAWNEWOBJs) $(PUBLICOBJ) 
bingbao: $(BINGBAOOBJs) $(PUBLICOBJ) 
drawHail: $(DRAWHAILOBJ) $(PUBLICOBJ) 

.PHONY: clean
clean:
	rm -rf *.o hello drawSin *~ drawRect drawNew bingbao drawHail
