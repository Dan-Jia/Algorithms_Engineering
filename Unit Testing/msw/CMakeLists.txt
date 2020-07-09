add_executable(msw_tests tests.cc)
target_link_libraries(msw_tests Catch2::Catch2)

catch_discover_tests(msw_tests)
