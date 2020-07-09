add_executable(h_index_tests tests.cc)
target_link_libraries(h_index_tests Catch2::Catch2)

catch_discover_tests(h_index_tests)
