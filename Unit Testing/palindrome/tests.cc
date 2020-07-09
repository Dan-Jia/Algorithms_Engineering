#define CATCH_CONFIG_MAIN

#include <limits>

#include <catch2/catch.hpp>

#include "is_palindrome.hpp"

TEST_CASE("palindrome_unit_test", "[light]") {
  // test single digits
  REQUIRE(isPalindrome(0));
  REQUIRE(isPalindrome(1));
  REQUIRE(isPalindrome(8));
  REQUIRE(isPalindrome(9));
  // negative numbers
  REQUIRE(not isPalindrome(-1));
  REQUIRE(not isPalindrome(-42));
  // regular cases
  REQUIRE(isPalindrome(11));
  REQUIRE(isPalindrome(111));
  REQUIRE(isPalindrome(1125211));
  REQUIRE(isPalindrome(11255211));
  // regular, no palindromes
  REQUIRE(not isPalindrome(11254211));
  REQUIRE(not isPalindrome(1121));
  REQUIRE(not isPalindrome(21));
  // zeros
  REQUIRE(not isPalindrome(112552110));
  REQUIRE(isPalindrome(112505211));
  REQUIRE(not isPalindrome(112552011));
  // extremes
  REQUIRE(not isPalindrome(std::numeric_limits<int>::max()));
  REQUIRE(not isPalindrome(std::numeric_limits<int>::min()));
  REQUIRE(isPalindrome(2133443312));
}
