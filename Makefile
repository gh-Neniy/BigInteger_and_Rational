all: run

test: BigInteger.h Rational.h test/operation.cpp
	g++ -std=c++20 -fsanitize=address,undefined test/operation.cpp -o compiled_test

run: test
	./compiled_test

.PHONY: all test run