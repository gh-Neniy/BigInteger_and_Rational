## Описание

С помощью **BigInteger** можно:
- Хранить числа произвольной длины (создавать через литерал _bi)
- Проводить с ними арифметические операции (+, -, *, /, %)
- Использовать их строковое представление с помощью метода ToString()  

Класс **Rational** позволяет:
- Хранить рациональные числа с произвольными числителем и знаменателем (с автоматическим сокращением дроби)
- Проводить с ними арифметические операции (+, -, *, /)
- Приводить их к строке с помощью ToString()
- Вычислять десятичное представление любой точности с помощью AsDecimal(precision)

## Тесты

Тесты, в том числе на скорость, запускаются так:
- `make` - в режиме debug
- `make build=release` - в режиме release


## Пример использования

```cpp
#include "bigint/BigInteger.h"
#include "rational/Rational.h"
#include <limits>
#include <cstdint>

int main() {
  auto number1 = "3498572385734857842375723485742375234582734957498"_bi;
  BigInteger number2 = 9998191345341121232_bi;

  std::cout << number1 / number2 << '\n'; // 349920527112645744335368925333

  number1 = std::numeric_limits<int>::min();
  std::cout << number1 * number1 * number1 << '\n'; // -9903520314283042199192993792

  Rational rational(number1, number2);
  std::cout << (rational * rational).AsDecimal(30) << '\n'; // 0.000000000000000000046133546606

  std::cout << Rational(1, 7).AsDecimal(12) << '\n'; // 0.142857142857
}
```
