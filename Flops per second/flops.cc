#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <memory>
#include <random>
#include <sstream>

int main(int argc, char const* argv[]) {
  if (3 != argc) {
    std::cerr << "usage: " << argv[0] << " <num_iter> <vec_size>" << '\n';
    return -1;
  }

  int k;
  int n;

  if (!(std::istringstream{argv[1]} >> k).eof() ||
      !(std::istringstream{argv[2]} >> n).eof() || (n < 0) || (k < 0)) {
    std::cerr << "parameters have to be non-negative integers" << '\n';
    return -1;
  }

  std::mt19937 gen{std::random_device{}()};
  std::uniform_real_distribution<double> dis;

  std::unique_ptr<double[]> x{new double[n]};
  std::unique_ptr<double[]> y{new double[n]};
  auto rnd = std::bind(dis, gen);
  using namespace std::chrono;
  const auto rnd_start = system_clock::now();
  std::generate(x.get(), x.get() + n, std::ref(rnd));
  std::generate(y.get(), y.get() + n, std::ref(rnd));
  const double a = rnd();
  const auto rnd_end = system_clock::now();
  const double rnd_sec = duration<double>(rnd_end - rnd_start).count();
  std::cout << "random initialization took " << rnd_sec << "s" << '\n';

  const auto flop_start = system_clock::now();
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      y[j] = a * x[j] + y[j];
    }
  }
  const auto flop_end = system_clock::now();
  const double flop_sec = duration<double>(flop_end - flop_start).count();
  std::cout << "measuring took: " << flop_sec << "s" << '\n';

  const double gflops = 1.e-9 * 2 * n * k;
  const double gflops_s = (0.0 == gflops) ? 0.0 : (gflops / flop_sec);

  std::cout << "Giga-Flops/s = " << gflops_s << '\n';

  return 0;
}