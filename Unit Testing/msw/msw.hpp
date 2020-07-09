#ifndef MSW_HPP
#define MSW_HPP

#include <deque>
#include <vector>

std::vector<int> max_sliding_window(const std::vector<int> &nums, int k) {
  std::vector<int> swm;
  std::deque<int> indices; // potential candidate indices
  for (std::size_t i = 0; i < nums.size(); ++i) {
    // remove out of scope elements
    if (!indices.empty() && indices.front() == (i - k))
      indices.pop_front();
    // keep condition alive, that deque is sorted in descending order, with
    // maximum at front --> eliminate elements, that can no longer be a maximum
    while (!indices.empty() && nums[indices.back()] < nums[i])
      indices.pop_back();
    indices.push_back(i); // insert current element
    // fill the window first
    if (i >= k - 1)
      swm.push_back(nums[indices.front()]);
  }
  return swm;
}

#endif /* end of include guard: MSW_HPP */
