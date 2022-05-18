
output:
	clear
	g++ --std=c++17 -fconcepts main.cpp -o app
	./app
	rm -rf app.exe