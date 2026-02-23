#pragma once

#include <assert.h>
#include <numeric>
#include "../../Rational.h"

void CompareRationalEqual(const Rational& a, const Rational& b) {
  assert(a == b);
  assert(b == a);
  assert(a <= b);
  assert(a >= b);
  assert(b <= a);
  assert(b >= a);

  assert(!(a != b));
  assert(!(b != a));
  assert(!(a < b));
  assert(!(a > b));
  assert(!(b < a));
  assert(!(b > a));
}

void CompareRationalNotEqual(const Rational& a, const Rational& b) {
  // assumed that a > b
  assert(a != b);
  assert(b != a);
  assert(a > b);
  assert(b < a);
  assert(a >= b);
  assert(b <= a);

  assert(!(a == b));
  assert(!(b == a));
  assert(!(a < b));
  assert(!(b > a));
  assert(!(a <= b));
  assert(!(b >= a));
}

void CompareRational(const Rational& a, const Rational& b) {
  // assumed that a > b
  CompareRationalNotEqual(a, b);
  CompareRationalEqual(a, a);
  CompareRationalEqual(b, b);
}

void RationalTestCompare() {
  Rational a(2,3);
  Rational b(1,2);
  CompareRational(a, b);

  a = -a;
  b = -b;
  CompareRational(b, a);

  a = Rational("483574324372582347574239580724357234837413975139825713"_bi, "8947524835472356"_bi);
  b = Rational("2945724938578247572435742357923495798234795723498897"_bi, "389744389572358935109"_bi);
  CompareRational(a, b);

  a = -a;
  b = -b;
  CompareRational(b, a);
}

void AddRationalEqual(const Rational& a, const Rational& b, const Rational& result) {
  assert(a + b == result);
  assert(b + a == result);
  assert(a == result + -b);
  assert(b == result + -a);
  assert((a + b) + -result == 0);
  assert(-result + (a + b) == 0);

  assert(-a + -b == -result);
  assert(-b + -a == -result);
  assert(-a == -result + b);
  assert(-b == -result + a);
  assert((-a + -b) + result == 0);
  assert(result + (-a + -b) == 0);
}

void AddRational(const Rational& a, const Rational& b, const Rational& result) {
  AddRationalEqual(a, b, result);
  AddRationalEqual(a, -a, 0);
  AddRationalEqual(b, -b, 0);
  AddRationalEqual(result, -result, 0);
}

void RationalTestAdd() {
  // testing only equality, because compare operations already work properly
  AddRational(Rational(17, 18), Rational(1, 18), 1);
  AddRational(Rational(1, 17), Rational(3, 7), Rational(58, 119));
  AddRational(Rational(3, 7), Rational(4, 8), Rational(13, 14));
  
  Rational a = 1'000'000'000;
  Rational b = 2'288'007;

  AddRational(a, b, 1'002'288'007);
  AddRational(a, -b, 997'711'993);

  a = Rational("8924758275715817235817357315713753"_bi, "93485734577"_bi);
  b = Rational("43754235734298759283475234890572"_bi, "894375894372589"_bi);
  
  AddRational(a, b, Rational("7982092755299367767557943993415392565118285224561"_bi, "83611387473382843198309853"_bi));
  AddRational(-a, b, Rational("-7982084574505630815272932802654370299631021808473"_bi, "83611387473382843198309853"_bi));

  a = Rational("892475827571581723581735731340752397450234758349275892375813575713753"_bi, "934457275987435828573457723"_bi);
  b = Rational("437542357342987592834752345423759238758932475897234598234534890572"_bi, "894375894372519837418937489127489"_bi);

  auto numerator = "798208866899052842581622515118421840422245065860679911107832877368642486557884988070240573467860943773"_bi;
  auto denominator = "835756061964171524473799789486563160727912187870279098647547"_bi;

  AddRational(a, b, Rational(numerator, denominator));

  numerator = "798208866081323563837923662082163681048210420081747244291577582179542613171724700335743749612914368661"_bi;
  
  AddRational(a, -b, Rational(numerator, denominator));
}

void SubRationalEqual(const Rational& a, const Rational& b, const Rational& result) {
  assert(a - b == result);
  assert(b - a == -result);
  assert(a == result - -b);
  assert(b == -result - -a);
  assert((a - b) - result == 0);
  assert(result - (a - b) == 0);

  // with unary minus
  assert(-a - -b == -result);
  assert(-b - -a == result);
  assert(-a == -result - b);
  assert(-b == result - a);
  assert(-(a - b) - -result == 0);
  assert(-result - -(a - b) == 0);
}

void SubRational(const Rational& a, const Rational& b, const Rational& result) {
  SubRationalEqual(a, b, result);
  SubRationalEqual(a, a, 0);
  SubRationalEqual(b, b, 0);
  SubRationalEqual(result, result, 0);
}

void RationalTestSub() {
  SubRational(Rational(1, 17), Rational(1, 18), Rational(1, 306));
  SubRational(Rational(89, 91), Rational(5, 19), Rational(1236, 1729));
  SubRational(Rational(19, 17), -Rational(15, 17), 2);
  
  Rational a = 1'000'000'000;
  Rational b = 2'288'007;

  SubRational(a, b, 997'711'993);
  SubRational(a, -b, 1'002'288'007);
  
  a = Rational("8924758275715817235817357315713753"_bi, "93485734577"_bi);
  b = Rational("43754235734298759283475234890572"_bi, "894375894372589"_bi);
  
  SubRational(a, b, Rational("7982084574505630815272932802654370299631021808473"_bi, "83611387473382843198309853"_bi));
  SubRational(-a, b, -Rational("7982092755299367767557943993415392565118285224561"_bi, "83611387473382843198309853"_bi));

  a = Rational("892475827571581723581735731340752397450234758349275892375813575713753"_bi, "934457275987435828573457723"_bi);
  b = Rational("437542357342987592834752345423759238758932475897234598234534890572"_bi, "894375894372519837418937489127489"_bi);

  auto numerator = "798208866081323563837923662082163681048210420081747244291577582179542613171724700335743749612914368661"_bi;
  auto denominator = "835756061964171524473799789486563160727912187870279098647547"_bi;

  SubRational(a, b, Rational(numerator, denominator));

  numerator = "798208866899052842581622515118421840422245065860679911107832877368642486557884988070240573467860943773"_bi;
  
  SubRational(-a, b, -Rational(numerator, denominator));
}

void MultRationalEqual(const Rational& a, const Rational& b, const Rational& result) {
  assert(a * b == result);
  assert(b * a == result);
  assert(-a * b == -result);
  assert(b * -a == -result);
  assert(a * -b == -result);
  assert(-b * a == -result);
  assert(-a * -b == result);
  assert(-b * -a == result);
}

void MultRational(const Rational& a, const Rational& b, const Rational& result) {
  MultRationalEqual(a, b, result);
  MultRationalEqual(a, 0, 0);
  MultRationalEqual(0, b, 0);
  MultRationalEqual(result, 0, 0);
}

void RationalTestMult() {
  MultRationalEqual(0, 0, 0);
  MultRational(Rational(83475, 193), Rational(4358, 188), Rational(363784050, 36284));
  MultRational(Rational(8, 8), Rational(193, 193), 1);

  auto a = Rational("823785673246572348569278346578634782514237149839475"_bi, "2984357"_bi);
  auto b = Rational("24527543875892751746317824613251347"_bi, "348957"_bi);

  auto num = "20205439244887153071277250438497056979461142047515064633241306631791910118898877522825"_bi;
  auto denum = "1041412265649"_bi;

  MultRational(a, b, Rational(num, denum));

  num = "678622835446308465279465022800185504956380290925541324803211851434639513468471749513926663018268275625"_bi;
  denum = "8906386703449"_bi;

  MultRational(a, a, Rational(num, denum));
}

void DivRationalEqual(const Rational& a, const Rational& b, const Rational& result) {
  if (a != 0) {
    assert((a * a) / a == a);
    assert((a * b) / a == b);
  }
  if (b != 0) {
    assert(a / b == result);
    assert(-a / b == -result);
    assert(a / -b == -result);
    assert(-a / -b == result);
    assert((a * b) / b == a);
    assert((b * b) / b == b);
  }
  if (result != 0) {
    assert((result * result) / result == result);
    if (b != 0) {
      assert(a / b / result == 1);
      assert(-a / b / result == -1);
    }
  }
}

void DivRational(const Rational& a, const Rational& b, const Rational& result) {
  // assumed that a > b
  DivRationalEqual(a, b, result);
  DivRationalEqual(0, a, 0);
  DivRationalEqual(0, b, 0);
  DivRationalEqual(0, result, 0);
  assert(a / a == 1);
  assert(b / b == 1);
  assert(result / result == 1);

  try {
    a / 0;
  } catch (std::exception) {
  } catch (...) {
    std::cerr << "No exception on zero division\n";
    exit(-1);
  }

  try {
    b / 0;
  } catch (std::exception) {
  } catch (...) {
    std::cerr << "No exception on zero division\n";
    exit(-1);
  }

  try {
    result / 0;
  } catch (std::exception) {
  } catch (...) {
    std::cerr << "No exception on zero division\n";
    exit(-1);
  }
}

void RationalTestDiv() {
  DivRational(Rational(328, 321), Rational(345435, 457), Rational(149896, 110884635));
  DivRational(Rational(345720, 23423), Rational(928347, 3294), Rational(1138801680, 21744671781_bi));

  auto a = Rational("5634542375237589723485728347589234756817970587138957489037250982"_bi, "345237562397562347856"_bi);
  auto b = Rational("432750394758927587284578243758617581753758234751895718976034875"_bi, "98475285782493572641587295782476"_bi);

  auto num = "554863170655091784133405029362723173953727918407987005112186383989833109619232615969385689391432"_bi;
  auto denom = "149401691413155000944640081791013148624416261238033302757281090354962347102337478000"_bi;

  DivRational(a, b, Rational(num, denom));
}
