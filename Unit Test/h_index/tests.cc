#define CATCH_CONFIG_MAIN

#include <limits>
#include <vector>

#include <catch2/catch.hpp>

#include "h_index.hpp"

TEST_CASE("h_index_unit_tests", "[moderate]") {
  REQUIRE(1 == hIndex({std::numeric_limits<int>::max()}));
  REQUIRE(3 == hIndex({3, 0, 6, 1, 5}));
  REQUIRE(1 == hIndex({1, 1, 1, 1, 1}));
  REQUIRE(5 == hIndex({5, 5, 5, 5, 5}));
  REQUIRE(0 == hIndex({0, 0, 0, 0}));
  REQUIRE(3 == hIndex({3, 0, 2, 1, 5, 100}));
}
