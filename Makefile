# MAKEFILE extraido do site
# http://polaris.s.kanazawa-u.ac.jp/~npozar/intro-to-make.html

# MANUAL GNU MAKE disponível em
# https://www.gnu.org/software/make/manual/make.pdf

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
HEADERS:=$(wildcard src/*.h)

# this will contain the names of all intermediate object files
OBJECTS:=$(patsubst src/%.cpp,bin/%.o,$(SRCS))

# Arquivos markdown para compilar
MARKDOWN:=$(wildcard *.md)

# chamada do programa compilado utilizando Variáveis Automáticas
all:	bin/myprogram
	$^
	rm bin/*.*

# this rule is fancier now
# $< are the names of all prerequisites (the object files)
# $@ is the name of the target (bin/myprogram in this case)
bin/myprogram: $(OBJECTS)
	$(CC) $^ $(CC_OPTS) -o $@

# but now we have to tell make how to build the object files
# -c option tells g++ to only compile one source file at a tile
#  $< is the name of the first prerequisite (the cpp file in this case)
bin/%.o: src/%.cpp $(HEADERS)
	$(CC) $< $(CC_OPTS) -c -o $@

pdf: 
	pandoc Respostas.md -o Respostas.pdf --from markdown --template eisvogel --top-level-division=chapter -V classoption=oneside --listings