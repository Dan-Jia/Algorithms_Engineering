#define CATCH_CONFIG_MAIN

#include <vector>

#include <catch2/catch.hpp>
// see https://github.com/catchorg/Catch2/blob/master/docs/matchers.md
using namespace Catch::Matchers;

#include "msw.hpp"

TEST_CASE("msw_unit_tests", "[moderate]") {
  REQUIRE_THAT(max_sliding_window({1, 3, -1, -3, 5, 3, 6, 7}, 3),
               Equals(std::vector<int>({3, 3, 5, 5, 6, 7})));
  REQUIRE(max_sliding_window({}, 1).size() == 0);
}
