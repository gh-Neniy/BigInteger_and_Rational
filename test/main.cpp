#include "bigint/operation.hpp"
#include "bigint/method.hpp"
#include "bigint/performance.hpp"
#include "rational/operation.hpp"
#include "rational/method.hpp"
#include "rational/performance.hpp"

#include <iostream>

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
  BigIntTestIO();
  std::cout << "IO (<< / >>) tests are successful\n";
  BigIntTestBool();
  std::cout << "operator bool tests are successful\n";
  BigIntTestIncDec();
  std::cout << "++/-- tests are successful\n";
  BigIntTestFlipSign();
  std::cout << "FlipSign tests are successful\n";

  std::cout << "BigInteger method tests passed\n\n";

  std::cout << "Rational method tests started\n";

  RationalTestConstruct();
  std::cout << "Construct tests are successful\n";
  RationalTestToString();
  std::cout << "ToString tests are successful\n";
  RationalTestAsDecimal();
  std::cout << "AsDecimal tests are successful\n";
  RationalTestDouble();
  std::cout << "operator double tests are successful\n";

  std::cout << "Rational method tests passed\n\n";

  std::cout << "BigInteger performance tests started\n";

  BigIntTestPerformance();

  std::cout << "BigInteger performance tests passed\n\n";

  std::cout << "Rational performance tests started\n";

  RationalTestPerformance();

  std::cout << "Rational performance tests passed\n\n";
}