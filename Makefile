CXX = g++
CXXFLAGS = -std=c++20

ifeq ($(build), release)
	CXXFLAGS += -O2
else
	CXXFLAGS += -fsanitize=address,undefined
endif

SRC = bigint/BigInteger.cpp rational/Rational.cpp
OBJ = $(SRC:.cpp=.o)

TEST_SRC = 	test/main.cpp test/generate.cpp \
						test/bigint/method.cpp test/bigint/operation.cpp test/bigint/performance.cpp \
						test/rational/method.cpp test/rational/operation.cpp test/rational/performance.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)

all: test

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o compiled_test
	./compiled_test

clean:
	rm -f $(OBJ) $(TEST_OBJ) compiled_test

.PHONY: all test clean
