// 3 Algorithms for computing Fibonacci numbers are implemented here:
// 1) Algorithm derived from the definition
// 2) Algorithm using linear memory in n and running in linear time in n
// 3) Algorithm using constant memory and running in linear time in n
// ==============================================================================

#include "fibonacci.h"
#include <stdexcept>
#include <vector>

int fiboDef(int n) {
  if (n < 0) throw std::invalid_argument{"n shouldn't be negative!"};
  return (n < 2) ? n : (fiboDef(n - 1) + fiboDef(n - 2));
}

int fiboLinear(int n) {
  if (n < 0) throw std::invalid_argument{"n shouldn't be negative!"};

  int res = 0;
  std::vector<int> fibo(n);
  if (0 == n || 1 == n) return n;

  fibo[0] = 0;
  fibo[1] = 1;
  for (int i = 2; i <= n; ++i) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }
  res = fibo[n];

  return res;
}

int fiboConst(int n) {
  if (n < 0) std::invalid_argument("n shouldn't be negativ!");
  if (0 == n || 1 == n) return n;

  int fibo_minusone = 1;
  int fibo_minustwo = 0;
  int fibo = 0;

  for (int i = 2; i <= n; ++i) {
    fibo = fibo_minusone + fibo_minustwo;
    fibo_minustwo = fibo_minusone;
    fibo_minusone = fibo;
  }

  return fibo;
}
