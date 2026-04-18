#include "method.hpp"

#include "../../rational/Rational.hpp"

#include <assert.h>
#include <cmath>

void RationalTestToString() {
  Rational a(17, 18);
  assert(a.ToString() == "17/18");

  a *= 2;
  assert(a.ToString() == "17/9");

  a += Rational(1, 9);
  assert(a.ToString() == "2");

  a = -a;
  assert(a.ToString() == "-2");

  a += Rational(1, 18);
  assert(a.ToString() == "-35/18");

  assert(Rational(5, 25).ToString() == "1/5");
  assert(Rational(720, 120).ToString() == "6");
  assert(Rational(2398754, 2398754).ToString() == "1");

  a = Rational("17581758137556835713569823857135617851798235375165738917581668317581975"_bi,
               "2394762347671436872364761489758157878235720347504235000"_bi);

  assert(a.ToString() == "703270325502273428542792954285424714071929415006629556703266732703279/95790493906857474894590459590326315129428813900169400");
}

void RationalTestAsDecimal() {
  Rational a(1, 7);
  assert(a.AsDecimal(6) == "0.142857");
  assert(a.AsDecimal(36) == "0.142857142857142857142857142857142857");

  assert(a.AsDecimal(72) == "0.142857142857142857142857142857142857142857142857142857142857142857142857");
  assert(a.AsDecimal(71) == "0.14285714285714285714285714285714285714285714285714285714285714285714286");
  assert(a.AsDecimal(70) == "0.1428571428571428571428571428571428571428571428571428571428571428571429");
  assert(a.AsDecimal(69) == "0.142857142857142857142857142857142857142857142857142857142857142857143");
  assert(a.AsDecimal(68) == "0.14285714285714285714285714285714285714285714285714285714285714285714");
  assert(a.AsDecimal(67) == "0.1428571428571428571428571428571428571428571428571428571428571428571");

  a = -a;
  assert(a.AsDecimal(6) == "-0.142857");
  assert(a.AsDecimal(36) == "-0.142857142857142857142857142857142857");

  assert(a.AsDecimal(72) == "-0.142857142857142857142857142857142857142857142857142857142857142857142857");
  assert(a.AsDecimal(71) == "-0.14285714285714285714285714285714285714285714285714285714285714285714286");
  assert(a.AsDecimal(70) == "-0.1428571428571428571428571428571428571428571428571428571428571428571429");
  assert(a.AsDecimal(69) == "-0.142857142857142857142857142857142857142857142857142857142857142857143");
  assert(a.AsDecimal(68) == "-0.14285714285714285714285714285714285714285714285714285714285714285714");
  assert(a.AsDecimal(67) == "-0.1428571428571428571428571428571428571428571428571428571428571428571");

  a = 91;
  assert(a.AsDecimal(5) == "91.00000");

  a = -a;
  assert(a.AsDecimal(5) == "-91.00000");

  a = "1351089758347589145123653129875819237513457240385738947534"_bi;
  assert(a.AsDecimal(0) == "1351089758347589145123653129875819237513457240385738947534");

  a = -a;
  assert(a.AsDecimal(0) == "-1351089758347589145123653129875819237513457240385738947534");

  a = Rational("534170357139759183275324"_bi, "1395710389571356123759"_bi);
  assert(a.AsDecimal(12) == "382.722920980628");

  assert(Rational(1, 3).AsDecimal(0) == "0");
  assert(Rational(2, 3).AsDecimal(0) == "1");
  assert(Rational(1, 2).AsDecimal(0) == "1");
  assert(Rational(7, 3).AsDecimal(0) == "2");
  assert(Rational(7, 2).AsDecimal(0) == "4");
  assert(Rational(-1, 3).AsDecimal(0) == "0");
  assert(Rational(-1, 2).AsDecimal(0) == "-1");
  assert(Rational(-7, 3).AsDecimal(0) == "-2");
  assert(Rational(-7, 2).AsDecimal(0) == "-4");

  assert(Rational(1, 9).AsDecimal(9) == "0.111111111");
  assert(Rational(1, 9).AsDecimal(8) == "0.11111111");
  assert(Rational(1, 9).AsDecimal(17) == "0.11111111111111111");
  assert(Rational(1, 9).AsDecimal(18) == "0.111111111111111111");

  assert(Rational(99, 100).AsDecimal(1) == "1.0");
  assert(Rational(999'999, 1'000'000).AsDecimal(5) == "1.00000");
  assert(Rational(-999'999, 1'000'000).AsDecimal(5) == "-1.00000");

  assert(Rational(1, 1'000'000).AsDecimal(3) == "0.000");
  assert(Rational(-1, 1'000'000).AsDecimal(3) == "0.000");

  assert(Rational(1, 4).AsDecimal(3) == "0.250");
  assert(Rational(1, 8).AsDecimal(5) == "0.12500");
  assert(Rational(-1, 4).AsDecimal(3) == "-0.250");

  assert(Rational(5).AsDecimal(0) == "5");
  assert(Rational(-5).AsDecimal(0) == "-5");
  assert(Rational(0).AsDecimal(0) == "0");
  assert(Rational(0).AsDecimal(3) == "0.000");
}

void RationalTestConstruct() {
  assert(Rational(2, 4).ToString() == "1/2");
  assert(Rational(10, 100).ToString() == "1/10");
  assert(Rational(100, 10).ToString() == "10");
  assert(Rational(-6, 8).ToString() == "-3/4");

  assert(Rational(1, -2).ToString() == "-1/2");
  assert(Rational(-1, -2).ToString() == "1/2");
  assert(Rational(-3, -6).ToString() == "1/2");

  assert(Rational(0, 5).ToString() == "0");
  assert(Rational(0, -5).ToString() == "0");
  assert(!Rational(0, -5).IsNegative());

  assert(Rational().ToString() == "0");
  assert(Rational(7).ToString() == "7");
  assert(Rational(-7).ToString() == "-7");

  assert(Rational("1000000000"_bi).ToString() == "1000000000");
  assert(Rational("10"_bi, "100"_bi).ToString() == "1/10");
  assert(Rational("-10"_bi, "100"_bi).ToString() == "-1/10");
  assert(Rational("-10"_bi, "-100"_bi).ToString() == "1/10");

  Rational a(3, 7);
  assert((-a).ToString() == "-3/7");
  assert((-(-a)).ToString() == "3/7");
  Rational zero;
  assert((-zero).ToString() == "0");
  assert(!(-zero).IsNegative());
}

void RationalTestDouble() {
  assert(std::abs(static_cast<double>(Rational(1, 2)) - 0.5) < 1e-12);
  assert(std::abs(static_cast<double>(Rational(1, 4)) - 0.25) < 1e-12);
  assert(std::abs(static_cast<double>(Rational(-3, 4)) + 0.75) < 1e-12);
  assert(static_cast<double>(Rational(0)) == 0.0);

  double one_third = static_cast<double>(Rational(1, 3));
  assert(std::abs(one_third - (1.0 / 3.0)) < 1e-12);

  double neg_two_thirds = static_cast<double>(Rational(-2, 3));
  assert(std::abs(neg_two_thirds + (2.0 / 3.0)) < 1e-12);

  assert(static_cast<double>(Rational(1000000)) == 1000000.0);
  assert(static_cast<double>(Rational(-1000000)) == -1000000.0);
}
