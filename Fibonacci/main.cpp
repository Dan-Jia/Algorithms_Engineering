#include <chrono>
#include <iostream>
#include "fibonacci.h"

int main(int argc, char* argv[]) {
  if (2 != argc) {
    std::cerr << "false argument!" << std::endl;
    return -1;
  }

  int n = atoi(argv[1]);
  int res = 0;
  using namespace std::chrono;

  auto start = system_clock::now();
  res = fiboDef(n);
  // res = fiboLinear(n);
  // res = fiboConst(n);
  auto end = system_clock::now();
  double fn_s = duration<double>(end - start).count();

  std::cout << "the fibonacci number of n is: " << res << std::endl;
  std::cout << "the time costs: " << fn_s << std::endl;

  return 0;
}
