#pragma once

#include <chrono>
#include <cmath>
#include "../generate.h"

void RationalPerformance(std::random_device& rand_device, std::mt19937& gen, std::uniform_int_distribution<uint32_t>& distrib,
                       const std::size_t test_count, char operation) {
  std::cout << test_count;
  switch (operation) {
    case '+':
    std::cout << " additions ";
    break;
    case '-':
    std::cout << " substractions ";
    break;
    case '*':
    std::cout << " multiplications ";
    break;
    case '/':
    std::cout << " divisions ";
    break;
    case '%':
    std::cout << " mods ";
    break;
  }
  std::cout << "of random 512-bit rational numbers\n<";
  
  std::chrono::nanoseconds ns;

  Rational a;
  Rational b;

  for (int i = 1; i <= test_count; ++i) {
    a = RandRational512(rand_device, gen, distrib);
    b = RandRational512(rand_device, gen, distrib);

    auto start = std::chrono::steady_clock::now();
    switch (operation) {
      case '+':
      { volatile auto result = a + b; }
      break;
      case '-':
      { volatile auto result = a - b; }
      break;
      case '*':
      { volatile auto result = a * b; }
      break;
      case '/':
      { volatile auto result = a / b; }
      break;
    }
    auto end = std::chrono::steady_clock::now();
    ns += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "-";
    std::cout.flush();
  }

  auto total_time = std::chrono::duration_cast<std::chrono::milliseconds>(ns).count();
  std::cout << "> " << total_time << " ms" << std::endl;
}

void RationalTestPerformance() {
  std::random_device rand_device;
  std::mt19937 gen(rand_device());
  std::uniform_int_distribution<uint32_t> distrib;

  constexpr std::size_t test_count = 10;

  RationalPerformance(rand_device, gen, distrib, test_count, '+');
  RationalPerformance(rand_device, gen, distrib, test_count, '-');
  RationalPerformance(rand_device, gen, distrib, test_count, '*');
  RationalPerformance(rand_device, gen, distrib, test_count, '/');
}