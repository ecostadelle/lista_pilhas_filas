# we can define variables in a makefile
# variable CC will specify the compiler; feel free to use clang++
CC:=g++

# this variable contains any extra compiler options that we might
# want to add, like -O3, -march=native, etc.
# -O3 tells g++ to optimize the code for speed
CC_OPTS:=-std=c++20 -fconcepts

# this variable will contain the names of all cpp source files
SRCS:=$(wildcard src/*.cpp)

# variable with all header files
INCLUDE:=$(wildcard include/*.cpp)

CPP:= $(INCLUDE) $(SRCS)

# variable with all header files
HEADERS:=$(wildcard include/*.h)

# this will contain the names of all intermediate object files
OBJECTS:=$(patsubst include/%.cpp,bin/%.o,$(INCLUDE)) $(patsubst src/%.cpp,bin/%.o,$(SRCS)) 

# this rule is fancier now
# $< are the names of all prerequisites (the object files)
# $@ is the name of the target (bin/myprogram in this case)
./bin/app.exe: ./bin/main.o ./bin/dequeEncadeado.o
	$(CC) $^ $(CC_OPTS) -o $@
	./bin/app

# but now we have to tell make how to build the object files
# -c option tells g++ to only compile one source file at a tile
#  $< is the name of the first prerequisite (the cpp file in this case)
./bin/dequeEncadeado.o:
#	$(CC) $(filter %.cpp,$(CPP))
	$(CC) ./include/dequeEncadeado.cpp $(CC_OPTS) -c -o ./bin/dequeEncadeado.o
	$(CC) ./src/main.cpp $(CC_OPTS) -c -o ./bin/main.o
	
