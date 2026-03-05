#include "method.h"

#include "../../bigint/BigInteger.h"

#include <assert.h>
#include <numeric>

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
}