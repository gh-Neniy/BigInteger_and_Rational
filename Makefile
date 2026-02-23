all: run

test: test/main.cpp
	g++ -std=c++20 -fsanitize=address,undefined test/main.cpp -o compiled_test

run: test
	./compiled_test

.PHONY: all test run