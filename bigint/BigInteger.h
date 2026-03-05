#pragma once

#include <limits.h>
#include <compare>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

#ifndef NENIY_BIGINTEGER
#define NENIY_BIGINTEGER

class BigInteger {
 public:
  using BlockT = std::int32_t;
  static constexpr int cMaxBlock = 1'000'000'000;
  static constexpr int cBlockSize = 9;

  BigInteger(int = 0);

  explicit BigInteger(unsigned long long, size_t /*unused*/);

  explicit BigInteger(const char*);

  std::string ToString() const;

  BigInteger& operator+=(const BigInteger&);

  BigInteger& operator-=(const BigInteger&);

  BigInteger& operator*=(const BigInteger&);

  BigInteger& operator/=(const BigInteger&);

  BigInteger& operator%=(const BigInteger&);

  BigInteger operator-() const;

  BigInteger operator+() const;

  BigInteger& operator++();

  BigInteger& operator--();

  BigInteger operator++(int);

  BigInteger operator--(int);

  explicit operator bool() const;

  void FlipSign();

  bool IsZero() const;

  bool IsNegative() const;

  const std::vector<BlockT>& GetBlocks() const;

 private:
  void IncrementLogic();

  void DecrementLogic();

  std::pair<BigInteger, BigInteger> DivMod(const BigInteger&) const;

  bool is_negative_;
  std::vector<BlockT> blocks_;  // Блоки по 9 цифр (little-endian)
};

std::strong_ordering operator<=>(const BigInteger& lhs, const BigInteger& rhs);

bool operator==(const BigInteger& lhs, const BigInteger& rhs);

BigInteger operator""_bi(unsigned long long number);

BigInteger operator""_bi(const char* str, size_t /*unused*/);

std::ostream& operator<<(std::ostream& os, const BigInteger& rhs);

std::istream& operator>>(std::istream& is, BigInteger& rhs);

BigInteger operator+(const BigInteger& lhs, const BigInteger& rhs);

BigInteger operator-(const BigInteger& lhs, const BigInteger& rhs);

BigInteger operator*(const BigInteger& lhs, const BigInteger& rhs);

BigInteger operator/(const BigInteger& lhs, const BigInteger& rhs);

BigInteger operator%(const BigInteger& lhs, const BigInteger& rhs);

#endif // NENIY_BIGINTEGER
