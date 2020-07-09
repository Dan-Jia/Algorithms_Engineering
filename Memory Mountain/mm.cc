#include <chrono>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <tuple>
#include <vector>

using mytype = std::int64_t;
using Measurement = std::tuple<int, int, double>;
std::vector<Measurement> measurements;

template <int Stride>
Measurement copy_bytes(const mytype *src, int num_elem, mytype *dst) {
  using namespace std::chrono;
  // warm up
  for (int i = 0; i < num_elem; ++i)
    dst[i] = src[i * Stride];
  auto start = high_resolution_clock::now();
  constexpr int num_runs = 3;
  for (int i = 0; i < num_runs; ++i)
    for (int i = 0; i < num_elem; ++i)
      dst[i] = src[i * Stride];
  auto end = high_resolution_clock::now();
  const double sec = duration<double>(end - start).count();
  // gigabyte / sec read
  const int size = (num_elem * sizeof(mytype) / 1024);
  const double bw = 1e-9 * 1024 * (num_runs * size) / sec;
  return {Stride, size, bw};
}

int main(int argc, char const *argv[]) {

  // size in kB
  constexpr int max_size = 20000;
  constexpr int max_stride = 16;
  std::vector<mytype> src(
      std::ceil(1024.0 * max_size / sizeof(mytype) * max_stride), 11);
  std::vector<mytype> dst(src.size());
  std::vector<int> sizes;
  for (int size = 2; size < max_size; size *= 2)
    sizes.push_back(size);
#pragma omp parallel for schedule(dynamic)
  for (int i = 0; i < sizes.size(); ++i) {
    const auto size = sizes[i];
    const int num_elem = 1024.0 * size / sizeof(mytype);
    auto result = copy_bytes<1>(src.data(), num_elem, dst.data());
#pragma omp critical
    measurements.push_back(std::move(result));
    result = copy_bytes<2>(src.data(), num_elem, dst.data());
#pragma omp critical
    measurements.push_back(std::move(result));
    result = copy_bytes<4>(src.data(), num_elem, dst.data());
#pragma omp critical
    measurements.push_back(std::move(result));
    result = copy_bytes<8>(src.data(), num_elem, dst.data());
#pragma omp critical
    measurements.push_back(std::move(result));
    result = copy_bytes<16>(src.data(), num_elem, dst.data());
#pragma omp critical
    measurements.push_back(std::move(result));
  }

  std::ofstream ofs("measurements.dat");
  for (const auto &[stride, size, bw] : measurements)
    ofs << stride << '\t' << size << '\t' << bw << '\n';

  return 0;
}
