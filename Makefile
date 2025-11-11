all: run

test: BigInteger.h Rational.h tests/test_operations.cpp
	g++ -std=c++23 -fsanitize=address,undefined tests/test_operations.cpp -o compiled_test

run: test
	./compiled_test

.PHONY: all test run