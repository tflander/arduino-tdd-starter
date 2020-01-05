include_directories( 
    ${PROJECT_SOURCE_DIR}/src 
    ${PROJECT_SOURCE_DIR}/mock
)

add_executable(${PROJECT_NAME} 
  # test_oscillator.cpp 
  # test_random.cpp
  test_grid.cpp
  test_rules.cpp
  test_neopixel_adapter.cpp
  test_randomSeed.cpp
  test_consoleDisplayAdapter.cpp
  test_serpentineNeopixelStripDisplayAdapter.cpp

  support.cpp
  ../src/neopixel_adapter.c
  ../src/render.c 
  ../src/gameOfLifeEngine/rules.c 
  ../src/gameOfLifeEngine/neighbor_counter.c 
  ../src/gameOfLifeEngine/grid.c
  ../src/gameOfLife.c
  ../src/consoleDisplayAdapter.cpp
  ../src/serpintineNeopixelStripDisplayAdapter.cpp
  ../mock/mockArduino.c
)

target_link_libraries(${PROJECT_NAME} gtest_main)


include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
