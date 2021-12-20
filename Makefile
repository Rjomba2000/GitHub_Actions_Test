all:
	g++ -std=c++17 src/main.cpp -o main
	g++ -std=c++17 tests/tests.cpp -lcppunit -o test

test:
	chmod +x main
	./test

clean:
	$(RM) main test