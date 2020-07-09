#ifndef H_INDEX_HPP
#define H_INDEX_HPP

#include <algorithm>
#include <vector>

int hIndex(const std::vector<int> &citations) {
  int h_index = 0;
  int max_e;
  if (citations.size()) {
    max_e = *max_element(citations.begin(), citations.end());
    max_e = std::min(std::size_t(max_e), citations.size());
    std::vector<int> count(max_e + 1, 0);
    for (auto e : citations)
      count[std::min(std::size_t(e), count.size() - 1)]++;
    // accumulate all counters
    for (int i = count.size() - 1; i >= 1; --i)
      count[i - 1] += count[i];
    for (int i = count.size() - 1; !h_index && i >= 0; --i)
      if (count[i] >= i)
        h_index = i;
  }
  return h_index;
}

#endif /* end of include guard: H_INDEX_HPP */
