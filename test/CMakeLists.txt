add_subdirectory(./lib/googletest-master)
set(gtest_SOURCE_DIR, ./lib/googletest-master/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTest.cpp ToDoTest.cpp ToDoListTest.cpp DateTest.cpp SetOfListsTest.cpp)
add_executable(runAllTests ${TEST_SOURCE_FILES})
target_link_libraries(runAllTests gtest gtest_main core)