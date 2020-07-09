#include "lcs.h"
#include <algorithm>
#include <string>
#include <vector>

int lcs(std::string &x, std::string &y, int m, int n) {
  if (0 == m || 0 == n)
    return 0;

  else {
    std::vector<std::vector<int> > table(m + 1, std::vector<int>(n + 1));
    for (int i = 1; i < m + 1; ++i) {
      for (int j = 1; j < n + 1; ++j) {
        return (x[m] == y[n])
                   ? lcs(x, y, m - 1, n - 1) + 1
                   : std::max(lcs(x, y, m, n - 1), lcs(x, y, m - 1, n));
      }
    }
  }
}
