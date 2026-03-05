#pragma once

#include "../rational/Rational.h"

#include <random>
#include <numeric>

BigInteger RandBigInt512(std::random_device& rand_device, std::mt19937& gen, std::uniform_int_distribution<uint32_t>& distrib);

Rational RandRational512(std::random_device& rand_device, std::mt19937& gen, std::uniform_int_distribution<uint32_t>& distrib);
