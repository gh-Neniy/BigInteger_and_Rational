#pragma once

#include "../bigint/BigInteger.hpp"

#ifndef NENIY_RATIONAL
#define NENIY_RATIONAL

class Rational {
 public:
  Rational(int = 0, int = 1);

  Rational(const BigInteger&, const BigInteger& = 1);

  Rational& operator+=(const Rational&);

  Rational& operator-=(const Rational&);

  Rational& operator*=(const Rational&);

  Rational& operator/=(const Rational&);

  Rational operator-() const;

  std::string ToString() const;

  std::string AsDecimal(size_t /*precision*/) const;

  bool IsNegative() const;

  const BigInteger& GetNumerator() const { return numerator_; }

  const BigInteger& GetDenominator() const { return denominator_; }

  explicit operator double() const;

 private:
  static BigInteger Gcd(BigInteger, BigInteger);

  void SetNegative();

  void Simplify();

  static void DecimalIncrementation(std::string& /*decimal*/);

  BigInteger numerator_;
  BigInteger denominator_;
};

std::strong_ordering operator<=>(const Rational& lhs, const Rational& rhs);

bool operator==(const Rational& lhs, const Rational& rhs);

Rational operator+(const Rational& lhs, const Rational& rhs);

Rational operator-(const Rational& lhs, const Rational& rhs);

Rational operator*(const Rational& lhs, const Rational& rhs);

Rational operator/(const Rational& lhs, const Rational& rhs);

#endif // NENIY_RATIONAL
