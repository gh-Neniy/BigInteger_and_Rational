#pragma once

#include <random>
#include <numeric>
#include "../BigInteger.h"
#include "../Rational.h"

BigInteger RandBigInt512(std::random_device& rand_device, std::mt19937& gen, std::uniform_int_distribution<uint32_t>& distrib) {
  BigInteger shift = (1 << 31);
  shift *= 2;
  
  BigInteger result = distrib(gen);

  for (int i = 0; i < 15; ++i) {
    result *= shift;
    result += distrib(gen);
  }
  return result;
}

Rational RandRational512(std::random_device& rand_device, std::mt19937& gen, std::uniform_int_distribution<uint32_t>& distrib) {
  return Rational(RandBigInt512(rand_device, gen, distrib), RandBigInt512(rand_device, gen, distrib));
}
