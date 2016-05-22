

CXX = g++
CXXFLAGS = -g -O2 -Wall -Wno-sign-compare -Iinclude -DHAVE_CONFIG_H 
OBJS = Solver.o Particle.o TinkerToy.o RodConstraint.o SpringForce.o CircularWireConstraint.o imageio.o

CPP  = g++
CC   = gcc
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
LIBS =  -static-libgcc -static-libstdc++ -L"deps/png" -L"deps/freeglut/lib" -lfreeglut -lfreeglut_static -lopengl32 -lpng -lglu32  -s 
INCS =  -I"deps/png"  -I"deps/freeglut/include"  -I"deps/libgfx/include" 
BIN  = Project1.exe
CXXFLAGS = $(INCS) -DHAVE_CONFIG_H -fexpensive-optimizations -O3 -std=c++11
RM = rm -f

.PHONY: all clean

all: $(BIN)

clean:
	$(RM) $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(OBJ) -o $(BIN) $(LIBS)

%.o: %.cpp
	$(CPP) $(CXXFLAGS) -c $^ -o $@
