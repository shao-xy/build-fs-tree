add_executable(test_handy test_handy.cc)

add_executable(test_tree test_tree.cc)
target_link_libraries(test_tree tree)

add_executable(test_reader test_reader.cc)
target_link_libraries(test_reader reader)
