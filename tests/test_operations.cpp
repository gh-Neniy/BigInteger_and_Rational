#include <assert.h>
#include <iostream>
#include <numeric>
#include "../Rational.h"

void TestAdd() {
  assert(0_bi + 0_bi == 0);
  assert(100_bi + 0 == 100);
  assert(0 + 100_bi == 100);
  assert(-100_bi + 0 == -100);
  assert(0 + -100_bi == -100);
  assert(-100_bi + 100_bi == 0);
  assert(100_bi + -100_bi == 0);

  BigInteger int_max = INT_MAX;
  BigInteger int_min = INT_MIN;
  assert(-int_min == int_max + 1);
  assert(-int_min + -1 == int_max);
  assert(-int_max == int_min + 1);
  assert(-int_max + -1 == int_min);

  assert(int_min < int_max);
  assert(int_max > int_min);
  assert(int_min != int_max + 1);
  assert(int_min + -1 != int_max);
  
  BigInteger a = 1'000'000'000;
  BigInteger b = 2'288'007;
  assert(a > b);
  assert(!(a <= b));
  assert(a + -b > 0);
  assert(-b + a > 0);
  assert(b < a);
  assert(!(b >= a));
  assert(b + -a < 0);
  assert(-a + b < 0);

  assert(a + b == b + a);
  assert(a + b == 1'002'288'007);
  assert(a + -b == 997'711'993);
  assert(-a + b == -997'711'993);
  
  a = "348020895743759728347502349857294837"_bi;
  b = "348957289357048935740470385723457023954385973"_bi;
  assert(a + b == b + a);
  assert(a + b == "348957289705069831484230114070959373811680810"_bi);
  assert(-a + b == "348957289009028039996710657375954674097091136"_bi);
  assert(a + -b == -"348957289009028039996710657375954674097091136"_bi);

  a = "8423705892470574572357357348572835723857823058472395723485743295723495398257042982315"_bi;
  b = "89437052984572838934572345234590702745982375429357289375029483754239857243895239584"_bi;
  assert(a + b == b + a);
  assert(a != b + a);
  assert(a + b == "8513142945455147411291929693807426426603805433901753012860772779477735255500938221899"_bi);
  assert(-a + b == -"8334268839486001733422785003338245021111840683043038434110713811969255541013147742731"_bi);
  assert(a + -b == "8334268839486001733422785003338245021111840683043038434110713811969255541013147742731"_bi);

  assert(a + -a == 0);
  assert(b + -b == 0);
  assert(a > b);
  assert(b < a);
  b += a;
  assert(b == "8513142945455147411291929693807426426603805433901753012860772779477735255500938221899"_bi);
  assert(a < b);
  assert(b > a);
  assert(a + -b < 0);
  assert(-a + b > 0);
}

void TestSub() {
  assert(0_bi - 0_bi == 0);
  assert(100_bi - 0 == 100);
  assert(0 - 100_bi == -100);
  assert(-100_bi - 0 == -100);
  assert(0 - -100_bi == 100);
  assert(-100_bi - 100_bi == -200);
  assert(100_bi - -100_bi == 200);

  BigInteger int_max = INT_MAX;
  BigInteger int_min = INT_MIN;
  assert(-int_min - 1 == int_max);
  assert(-int_max - 1 == int_min);
  assert(int_min - 1 != int_max);
  
  BigInteger a = 1'000'000'000;
  BigInteger b = 2'288'007;
  assert(a > b);
  assert(a - b > 0);
  assert(b < a);
  assert(b - a < 0);

  assert(a - b != b - a);
  assert(a - b == 997'711'993);
  assert(b - a == -997'711'993);
  
  a = "348020895743759728347502349857294837"_bi;
  b = "348957289357048935740470385723457023954385973"_bi;
  assert(a - b == -"348957289009028039996710657375954674097091136"_bi);
  assert(b - a == "348957289009028039996710657375954674097091136"_bi);

  a = "8423705892470574572357357348572835723857823058472395723485743295723495398257042982315"_bi;
  b = "89437052984572838934572345234590702745982375429357289375029483754239857243895239584"_bi;
  assert(a - b == "8334268839486001733422785003338245021111840683043038434110713811969255541013147742731"_bi);
  assert(b - a == -"8334268839486001733422785003338245021111840683043038434110713811969255541013147742731"_bi);

  assert(a - a == 0);
  assert(b - b == 0);
  assert(a > b);
  assert(b < a);
  b -= a;
  assert(b == -"8334268839486001733422785003338245021111840683043038434110713811969255541013147742731"_bi);
  assert(a > b);
  assert(b < a);
  assert(a - b > 0);
  assert(b - a < 0);
}

void TestMult() {
  BigInteger a = 993;
  assert(a * 0 == 0);
  assert(0 * a == 0);
  assert(-a * 0 == 0);
  assert(0 * -a == 0);
  assert(a * a == 986049);
  assert(a * -a == -986049);
  assert(a * -a == -a * a);
  assert(-a * -a == a * a);

  a = INT_MAX;
  assert(a * 0 == 0);
  assert(0 * a == 0);
  assert(-a * 0 == 0);
  assert(0 * -a == 0);
  assert(a * a == 4611686014132420609_bi);
  assert(a * -a == -4611686014132420609_bi);
  assert(a * -a == -a * a);
  assert(-a * -a == a * a);

  a = "2345"_bi;
  BigInteger b = "6789"_bi;
  assert(b * a == a * b);
  assert(-b * a == -a * b);
  assert(-a * -b == a * b);

  assert(a * b == 15920205);
  assert(-a * b == -15920205);
  assert(a * -b == -15920205);
  assert(a * a * b * -b * -a * b * a * b * a == "150639015938107607084511705965625"_bi);

  a = "823785673246572348569278346578634782514237149839475"_bi;
  b = "24527543875892751746317824613251347"_bi;
  assert(a * b == "20205439244887153071277250438497056979461142047515064633241306631791910118898877522825"_bi);
  assert(-a * b == -"20205439244887153071277250438497056979461142047515064633241306631791910118898877522825"_bi);
  assert(a * -b == -"20205439244887153071277250438497056979461142047515064633241306631791910118898877522825"_bi);
}

void TestDiv() {
  try {
    1_bi / 0;
  } catch (std::exception) {
  } catch (...) {
    std::cerr << "No exception in zero division.\n";
    exit(-1);
  }

  assert(10_bi / 5 == 2);
  assert(10_bi / (10_bi / 5) == 5);
  assert(333'333'333'333_bi / 3 = 111'111'111'111_bi);

  BigInteger a = 1337;
  assert(a / a == 1);
  assert(a / -a == -1);
  assert(-a / a == -1);
  assert(-a / -a == a / a);
  
  BigInteger b = 239487;
  assert(a / b == 0);
  assert(b / a != 0);
  assert(0_bi / a == 0);
  assert(0_bi / b == 0);

  assert(b / a == 179);
  assert(-b / a == -179);
  assert(b / -a == -179);
  assert(-b / -a == 179);

  a = "5634542375237589723485728347589234756817970587138957489037250982"_bi;
  assert(a / a == 1);
  assert(a / -a == -1);
  assert(-a / a == -1);
  assert(-a / -a == a / a);

  assert(a / b == "23527550035023152502999028538456094722544315921694945817673"_bi);
  assert(-a / b == -"23527550035023152502999028538456094722544315921694945817673"_bi);
  assert(a / -b == -a / b);
  assert(-a / -b == a / b);

  b = "176734715012574823677189324136271309476538271376517583256012573894875"_bi;
  assert(a / b == 0);
  assert(b / a != 0);
  assert(0_bi / a == 0);
  assert(0_bi / b == 0);

  assert(b / a == 31366);
  assert(-b / a == -31366);
  assert(b / -a == -b / a);
  assert(-b / -a == b / a);
}

void TestDivWithRemainder() {
  try {
    1_bi % 0;
  } catch (std::exception) {
  } catch (...) {
    std::cerr << "No exception in division with remainder by zero.\n";
    exit(-1);
  }

  auto a = 24573_bi;
  auto b = 34985072_bi;
  assert(a % b == a);
  assert(-a % b == -a); // C++ like
  assert(a % a == 0);
  assert(b % b == 0);
  assert(1 % a == 1);
  assert(1 % b == 1);

  assert(b % a == 17693);
  assert(-b % a == -(b % a));

  assert(10_bi % 4 == 2);
  assert(339369_bi % 3 == 0);
  assert(224681_bi % 2 == 1);
  assert(1887_bi % 7 == 4);

  a = "48528957243650185304195792739475823490579874895702894752903752992439502738"_bi;
  assert(b % a == b);
  assert(-b % a == -b);
  assert(a % b == 22599682);
  assert(-a % b == -22599682);

  b = "1345234572348756823819759823458937592473985723519856849352057892347592034752097582934"_bi;
  assert(a % b == a);
  assert(-a % b == -a);
  assert(b % a == "43959346560949061496198985867836448496012008622372191450720366294002954696"_bi);
  assert(-b % a == -"43959346560949061496198985867836448496012008622372191450720366294002954696"_bi);
}

int main() {
  TestAdd();
  std::cout << "Test add passed.\n";
  TestSub();
  std::cout << "Test sub passed.\n";
  TestMult();
  std::cout << "Test mult passed.\n";
  TestDiv();
  std::cout << "Test div passed.\n";
  TestDivWithRemainder();
  std::cout << "Test div with remainder passed.\n";
  
  std::cout << "All tests were passed.\n";
}