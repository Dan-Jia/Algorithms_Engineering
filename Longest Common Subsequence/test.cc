#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.hpp"
#include "lcs.h"

TEST_CASE("for test", "[lcs]") {
  std::string x = "ABCBDAB";
  std::string y = "BDCABA";
  REQUIRE(lcs(x, y, x.length(), y.length()) == 4);
}
