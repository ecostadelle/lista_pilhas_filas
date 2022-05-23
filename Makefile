
output:
	clear
	g++ --std=c++20 -fconcepts main.cpp -o app
	./app
	rm -rf app.exe