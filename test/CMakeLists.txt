set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    test.cpp
    test_mock.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include
                                           ${CMAKE_SOURCE_DIR}/include/mock
                                           ../vendor/googletest/googlemock/include)
target_link_libraries(cpp-test PUBLIC reader_writer gtest gmock)
