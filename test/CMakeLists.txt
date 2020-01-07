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
  ../src/rules.c 
  ../src/neighbor_counter.c 
  ../src/grid.c
  ../src/gameOfLife.c
  ../src/consoleDisplayAdapter.cpp
  ../src/serpintineNeopixelStripDisplayAdapter.cpp

  ../mock/mockArduino.c
  ../mock/Adafruit_NeoPixelMock.cpp
)

target_link_libraries(${PROJECT_NAME} gtest_main)


include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
