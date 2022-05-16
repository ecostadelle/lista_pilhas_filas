all: clean test

appTeste: teste.cpp aluno.hpp
	g++ --std=c++17 -fconcepts teste.cpp -o appTeste

test: appTeste
	# executa todos os testes
	./appTeste

clean:
	rm -f appTeste