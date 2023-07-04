file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_executable(simd-test ${srcs})
target_include_directories(simd-test PUBLIC include)
target_link_libraries(simd-test PUBLIC simd-algorithm)