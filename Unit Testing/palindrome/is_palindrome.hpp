#ifndef IS_PALINDROME_H
#define IS_PALINDROME_H

// input is checked for base-10 palindromes
bool isPalindrome(int x) {
  if (x != 0 and (0 == x % 10))
    return false;

  int reverted_x = 0;
  while (x > reverted_x) {
    int last_digit = x % 10;
    reverted_x = 10 * reverted_x + last_digit;
    x /= 10;
  }
  // taking care of odd/even situation
  return x == reverted_x || (reverted_x / 10) == x;
}

#endif /* end of include guard: IS_PALINDROME_H */
