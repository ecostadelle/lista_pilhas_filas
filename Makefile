
output:
	g++ --std=c++17 -fconcepts main.cpp -o app
	./app

clean:
	rm -rf *.exe