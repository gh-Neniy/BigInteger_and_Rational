#include <iostream>

#include "bigint/operation.h"
#include "bigint/method.h"
#include "bigint/performance.h"
#include "rational/operation.h"
#include "rational/method.h"
#include "rational/performance.h"

int main() {
  std::cout << "BigInteger operation tests started\n";

  BigIntTestCompare();
  std::cout << "Compare tests are successful\n";
  BigIntTestAdd();
  std::cout << "Addition tests are successful\n";
  BigIntTestSub();
  std::cout << "Subtraction tests are successful\n";
  BigIntTestMult();
  std::cout << "Multiplication tests are successful\n";
  BigIntTestDiv();
  std::cout << "Division tests are successful\n";
  BigIntTestMod();
  std::cout << "Modulo tests are successful\n";

  std::cout << "BigInteger operation tests passed\n\n";

  std::cout << "Rational operation tests started\n";

  RationalTestCompare();
  std::cout << "Compare tests are successful\n";
  RationalTestAdd();
  std::cout << "Addition tests are successful\n";
  RationalTestSub();
  std::cout << "Subtraction tests are successful\n";
  RationalTestMult();
  std::cout << "Multiplication tests are successful\n";
  RationalTestDiv();
  std::cout << "Division tests are successful\n";

  std::cout << "Rational operation tests passed\n\n";

  std::cout << "BigInteger method tests started\n";

  BigIntTestToString();
  std::cout << "ToString tests are successful\n";

  std::cout << "BigInteger method tests passed\n\n";

  std::cout << "Rational method tests started\n";

  RationalTestToString();
  std::cout << "ToString tests are successful\n";
  RationalTestAsDecimal();
  std::cout << "AsDecimal tests are successful\n";

  std::cout << "Rational method tests passed\n\n";

  std::cout << "BigInteger performance tests started\n";

  BigIntTestPerformance();

  std::cout << "BigInteger performance tests passed\n\n";

  std::cout << "Rational performance tests started\n";

  RationalTestPerformance();

  std::cout << "Rational performance tests passed\n\n";
}