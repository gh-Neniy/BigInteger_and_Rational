#include "method.hpp"

#include "../../bigint/BigInteger.hpp"

#include <assert.h>
#include <sstream>

void BigIntTestToString() {
  BigInteger a = 1337;
  assert(a.ToString() == "1337");

  a = -a;
  assert(a.ToString() == "-1337");

  a = INT_MAX;
  assert(a.ToString() == std::to_string(INT_MAX));

  ++a;
  assert(a.ToString() == std::to_string(static_cast<int64_t>(INT_MAX) + 1));
  assert((-a).ToString() == std::to_string(INT_MIN));

  a = "47857185718751835781375185718938123571382581513875418561380975183589172359823895713891895723985"_bi;
  assert(a.ToString() == "47857185718751835781375185718938123571382581513875418561380975183589172359823895713891895723985");
  
  a = -a;
  assert(a.ToString() == "-47857185718751835781375185718938123571382581513875418561380975183589172359823895713891895723985");

  assert(("475238752340758165175135819"_bi).ToString() == "475238752340758165175135819");
  assert(("-475238752340758165175135819"_bi).ToString() == "-475238752340758165175135819");
  assert((-"475238752340758165175135819"_bi).ToString() == "-475238752340758165175135819");

  assert(("1000000000"_bi).ToString() == "1000000000");
  assert(("1000000001"_bi).ToString() == "1000000001");
  assert(("1000000000000000000"_bi).ToString() == "1000000000000000000");

  assert(("0"_bi).ToString() == "0");
  assert(("-0"_bi).ToString() == "0");
  assert(("00000"_bi).ToString() == "0");
  assert(("-0000"_bi).ToString() == "0");
  assert(("000123"_bi).ToString() == "123");
  assert(("-000123"_bi).ToString() == "-123");
}

void BigIntTestIO() {
  {
    std::ostringstream oss;
    BigInteger a = "12345678901234567890"_bi;
    oss << a;
    assert(oss.str() == "12345678901234567890");
  }
  {
    std::ostringstream oss;
    oss << -"12345678901234567890"_bi;
    assert(oss.str() == "-12345678901234567890");
  }
  {
    std::ostringstream oss;
    oss << BigInteger(0);
    assert(oss.str() == "0");
  }

  {
    std::istringstream iss("12345678901234567890");
    BigInteger a;
    iss >> a;
    assert(a == "12345678901234567890"_bi);
  }
  {
    std::istringstream iss("-12345678901234567890");
    BigInteger a;
    iss >> a;
    assert(a == -"12345678901234567890"_bi);
  }
  {
    std::istringstream iss("   \t\n 42  garbage");
    BigInteger a;
    iss >> a;
    assert(a == 42);
  }
  {
    std::istringstream iss("1 2 3");
    BigInteger a;
    BigInteger b;
    BigInteger c;
    iss >> a >> b >> c;
    assert(a == 1);
    assert(b == 2);
    assert(c == 3);
  }

  {
    BigInteger original =
        "8423705892470574572357357348572835723857823058472395723485743295723495398257042982315"_bi;
    std::ostringstream oss;
    oss << original;
    std::istringstream iss(oss.str());
    BigInteger restored;
    iss >> restored;
    assert(restored == original);
  }
  {
    BigInteger original =
        -"8423705892470574572357357348572835723857823058472395723485743295723495398257042982315"_bi;
    std::ostringstream oss;
    oss << original;
    std::istringstream iss(oss.str());
    BigInteger restored;
    iss >> restored;
    assert(restored == original);
  }
}

void BigIntTestBool() {
  assert(!static_cast<bool>(BigInteger(0)));
  assert(!static_cast<bool>("0"_bi));
  assert(!static_cast<bool>(-"0"_bi));
  assert(static_cast<bool>(BigInteger(1)));
  assert(static_cast<bool>(BigInteger(-1)));
  assert(static_cast<bool>("1000000000"_bi));
  assert(static_cast<bool>(-"1000000000"_bi));

  BigInteger a = 3;
  int count = 0;
  while (a) {
    --a;
    ++count;
  }
  assert(count == 3);
  assert(a == 0);
}

void BigIntTestIncDec() {
  BigInteger a = 0;
  assert(++a == 1);
  assert(a == 1);
  assert(--a == 0);
  assert(a == 0);
  assert(--a == -1);
  assert(a == -1);
  assert(++a == 0);
  assert(a == 0);

  a = 5;
  assert(a++ == 5);
  assert(a == 6);
  assert(a-- == 6);
  assert(a == 5);

  a = 1;
  --a;  // 0
  --a;  // -1
  assert(a == -1);
  ++a;  // 0
  ++a;  // 1
  assert(a == 1);

  a = 999'999'999;
  ++a;
  assert(a == 1'000'000'000);
  --a;
  assert(a == 999'999'999);

  a = "999999999999999999"_bi;
  ++a;
  assert(a == "1000000000000000000"_bi);
  --a;
  assert(a == "999999999999999999"_bi);

  a = -1;
  ++a;
  assert(a == 0);
  ++a;
  assert(a == 1);
  --a;
  --a;
  assert(a == -1);
}

void BigIntTestFlipSign() {
  BigInteger a = 42;
  a.FlipSign();
  assert(a == -42);
  a.FlipSign();
  assert(a == 42);

  BigInteger zero = 0;
  zero.FlipSign();
  assert(zero == 0);
  assert(!zero.IsNegative());

  BigInteger big = "12345678901234567890"_bi;
  big.FlipSign();
  assert(big == -"12345678901234567890"_bi);
}
