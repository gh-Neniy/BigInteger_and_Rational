#include "generate.hpp"

BigInteger RandBigInt512(std::random_device& /*rand_device*/, std::mt19937& gen,
                         std::uniform_int_distribution<uint32_t>& distrib) {
  static const BigInteger kShift("4294967296");

  BigInteger result = distrib(gen);
  for (int i = 0; i < 15; ++i) {
    result *= kShift;
    result += distrib(gen);
  }
  return result;
}

Rational RandRational512(std::random_device& rand_device, std::mt19937& gen,
                         std::uniform_int_distribution<uint32_t>& distrib) {
  BigInteger denominator = RandBigInt512(rand_device, gen, distrib);
  
  if (denominator == 0) {
    denominator = 1;
  }

  return Rational(RandBigInt512(rand_device, gen, distrib), denominator);
}
