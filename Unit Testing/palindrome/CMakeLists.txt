add_executable(palindrome_tests tests.cc)
target_link_libraries(palindrome_tests Catch2::Catch2)

catch_discover_tests(palindrome_tests)
