#pragma once

#include <assert.h>
#include <numeric>
#include "../../BigInteger.h"

void CompareBigIntEqual(const BigInteger& a, const BigInteger& b) {
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

void CompareBigIntNotEqual(const BigInteger& a, const BigInteger& b) {
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

void CompareBigInt(const BigInteger& a, const BigInteger& b) {
  // assumed that a > b
  CompareBigIntNotEqual(a, b);
  CompareBigIntEqual(a, a);
  CompareBigIntEqual(b, b);
}

void BigIntTestCompare() {
  BigInteger a = 1'000'000'000;
  BigInteger b = 2'288'007;
  CompareBigInt(a, b);

  a = -a;
  b = -b;
  CompareBigInt(b, a);

  a = "8423705892470574572357357348572835723857823058472395723485743295723495398257042982315"_bi;
  b = "89437052984572838934572345234590702745982375429357289375029483754239857243895239584"_bi;
  CompareBigInt(a, b);

  BigInteger int_max = INT_MAX;
  BigInteger int_min = INT_MIN;
  CompareBigInt(int_max, int_min);
}

void AddBigIntEqual(const BigInteger& a, const BigInteger& b, const BigInteger& result) {
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

void AddBigInt(const BigInteger& a, const BigInteger& b, const BigInteger& result) {
  AddBigIntEqual(a, b, result);
  AddBigIntEqual(a, -a, 0);
  AddBigIntEqual(b, -b, 0);
  AddBigIntEqual(result, -result, 0);
}

void BigIntTestAdd() {
  // testing only equality, because compare operations already work properly
  AddBigIntEqual(0, 0, 0);
  AddBigIntEqual(0, 0, -0_bi);
  AddBigIntEqual(0, -0_bi, 0);
  AddBigIntEqual(0, -0_bi, -0_bi);

  AddBigInt(100, 0_bi, 100);
  AddBigInt(100, -0_bi, 100);
  
  BigInteger a = 1'000'000'000;
  BigInteger b = 2'288'007;

  AddBigInt(a, b, 1'002'288'007);
  AddBigInt(a, -b, 997'711'993);
  
  a = "348020895743759728347502349857294837"_bi;
  b = "348957289357048935740470385723457023954385973"_bi;
  
  AddBigInt(a, b, "348957289705069831484230114070959373811680810"_bi);
  AddBigInt(-a, b, "348957289009028039996710657375954674097091136"_bi);

  a = "8423705892470574572357357348572835723857823058472395723485743295723495398257042982315"_bi;
  b = "89437052984572838934572345234590702745982375429357289375029483754239857243895239584"_bi;

  AddBigInt(a, b, "8513142945455147411291929693807426426603805433901753012860772779477735255500938221899"_bi);
  AddBigInt(a, -b, "8334268839486001733422785003338245021111840683043038434110713811969255541013147742731"_bi);

  BigInteger int_max = INT_MAX;
  BigInteger int_min = INT_MIN;

  AddBigInt(int_max, 1, -int_min);
}

void SubBigIntEqual(const BigInteger& a, const BigInteger& b, const BigInteger& result) {
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

void SubBigInt(const BigInteger& a, const BigInteger& b, const BigInteger& result) {
  SubBigIntEqual(a, b, result);
  SubBigIntEqual(a, a, 0);
  SubBigIntEqual(b, b, 0);
  SubBigIntEqual(result, result, 0);
}

void BigIntTestSub() {
  SubBigInt(0, 0, 0);
  SubBigInt(100, 0, 100);
  SubBigInt(-100, 100, -200);
  
  BigInteger a = 1'000'000'000;
  BigInteger b = 2'288'007;

  SubBigInt(a, b, 997'711'993);
  SubBigInt(a, -b, 1'002'288'007);
  
  a = "348957289357048935740470385723457023954385973"_bi;
  b = "348020895743759728347502349857294837"_bi;

  SubBigInt(a, b, "348957289009028039996710657375954674097091136"_bi);
  SubBigInt(a, -b, "348957289705069831484230114070959373811680810"_bi);

  a = "8423705892470574572357357348572835723857823058472395723485743295723495398257042982315"_bi;
  b = "89437052984572838934572345234590702745982375429357289375029483754239857243895239584"_bi;

  SubBigInt(a, b, "8334268839486001733422785003338245021111840683043038434110713811969255541013147742731"_bi);
  SubBigInt(a, -b, "8513142945455147411291929693807426426603805433901753012860772779477735255500938221899"_bi);

  BigInteger int_max = INT_MAX;
  BigInteger int_min = INT_MIN;
  SubBigInt(int_max, -1, -int_min);
}

void MultBigIntEqual(const BigInteger& a, const BigInteger& b, const BigInteger& result) {
  assert(a * b == result);
  assert(b * a == result);
  assert(-a * b == -result);
  assert(b * -a == -result);
  assert(a * -b == -result);
  assert(-b * a == -result);
  assert(-a * -b == result);
  assert(-b * -a == result);
}

void MultBigInt(const BigInteger& a, const BigInteger& b, const BigInteger& result) {
  MultBigIntEqual(a, b, result);
  MultBigIntEqual(a, 0, 0);
  MultBigIntEqual(0, b, 0);
  MultBigIntEqual(result, 0, 0);
}

void BigIntTestMult() {
  MultBigIntEqual(0, 0, 0);

  BigInteger a = 993;
  MultBigInt(a, 0, 0);
  MultBigInt(a, a, 986049); 

  a = "2345"_bi;
  BigInteger b = "6789"_bi;
  MultBigInt(a, b, 15920205);

  a = "823785673246572348569278346578634782514237149839475"_bi;
  b = "24527543875892751746317824613251347"_bi;
  MultBigInt(a, b, "20205439244887153071277250438497056979461142047515064633241306631791910118898877522825"_bi);
  MultBigInt(a, a, "678622835446308465279465022800185504956380290925541324803211851434639513468471749513926663018268275625"_bi);

  a = INT_MAX;
  MultBigInt(a, 0, 0);
  MultBigInt(a, a, "4611686014132420609"_bi);
}

void DivBigIntEqual(const BigInteger& a, const BigInteger& b, const BigInteger& result) {
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

void DivBigInt(const BigInteger& a, const BigInteger& b, const BigInteger& result) {
  // assumed that a > b
  DivBigIntEqual(a, b, result);
  DivBigIntEqual(b, a, 0);
  DivBigIntEqual(0, a, 0);
  DivBigIntEqual(0, b, 0);
  DivBigIntEqual(0, result, 0);
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

void BigIntTestDiv() {
  DivBigInt(10, 5, 2);
  DivBigInt(10, 2, 5);
  DivBigInt(333'333'333'333_bi, 3, 111'111'111'111_bi); 

  BigInteger a = 239487;
  BigInteger b = 1337;

  DivBigInt(a, b, 179);

  a = "5634542375237589723485728347589234756817970587138957489037250982"_bi;

  DivBigInt(a, b, "4214317408554666958478480439483346863738197896139833574448205"_bi);

  a = "138945723857823475173814839578475849365325781239578356357423867873274671519357158319275175731289571389275"_bi;
  b = "1767347150125748236771893241362713094765382713765175832560125738948754542365728346547823657846572"_bi;

  DivBigInt(a, b, 78618240);

  BigInteger int_max = INT_MAX;
  BigInteger int_min = INT_MIN;
  DivBigInt(int_min, int_max, -1);
}

void ModBigIntEqual(const BigInteger& a, const BigInteger& b, const BigInteger& result) {
  // cases according to builtin cpp behavior
  if (a != 0) {
    assert(a % a == 0);
  }
  if (b != 0) {
    auto res = a % b;
    assert(a % b == result);
    assert(-a % b == -result);
    assert(a % -b == result);
    assert(-a % -b == -result);
    assert(b % b == 0);
  }
  if (result != 0) {
    assert(result % result == 0);
    if (b != 0) {
      assert(a % b % result == 0);
    }
  }
}

void ModBigInt(const BigInteger& a, const BigInteger& b, const BigInteger& result) {
  // assumed that |a| > |b|
  ModBigIntEqual(a, b, result);
  ModBigIntEqual(b, a, b);
  ModBigIntEqual(0, a, 0);
  ModBigIntEqual(0, b, 0);
  ModBigIntEqual(0, result, 0);

  try {
    a % 0;
  } catch (std::exception) {
  } catch (...) {
    std::cerr << "No exception on zero division\n";
    exit(-1);
  }

  try {
    b % 0;
  } catch (std::exception) {
  } catch (...) {
    std::cerr << "No exception on zero division\n";
    exit(-1);
  }

  try {
    result % 0;
  } catch (std::exception) {
  } catch (...) {
    std::cerr << "No exception on zero division\n";
    exit(-1);
  }
}

void BigIntTestMod() {
  ModBigInt(10, 4, 2);
  ModBigInt(339369, 3, 0);
  ModBigInt(224681, 2, 1);
  ModBigInt(1887, 7, 4);

  BigInteger a = 34985072_bi;
  BigInteger b = 24573_bi;

  ModBigInt(a, b, 17693);

  a = "48528957243650185304195792739475823490579874895702894752903752992439502738"_bi;

  ModBigInt(a, b, 21184);

  a = "824578917581754827581413658714518935714835673751357138577165891372457185618397581358901354138741634891375891359"_bi;
  b = "134523457234879247398572351985684935205789234759203475209758293435762034"_bi;

  ModBigInt(a, b, "82011087428166257419283842613234744332457702736340612839302293948470283"_bi);

  BigInteger int_max = INT_MAX;
  BigInteger int_min = INT_MIN;

  ModBigInt(int_min, int_max, -1);
}
