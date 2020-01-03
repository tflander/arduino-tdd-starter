include_directories( ${PROJECT_SOURCE_DIR}/src )

add_executable(${PROJECT_NAME} 
  # test_oscillator.cpp 
  test_grid.cpp
  # test_random.cpp
  test_rules.cpp
  support.cpp
  ../src/neopixel_adapter.c
  ../src/render.c 
  ../src/rules.c 
  ../src/neighbor_counter.c 
  ../src/grid.c
  ../src/gameOfLife.c
)

target_link_libraries(${PROJECT_NAME} gtest_main)


include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
