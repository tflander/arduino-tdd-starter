#include <gtest/gtest.h>

extern "C" {
    #include "Arduino.h"
}

TEST(RansomSeed, foo)
{
    ASSERT_EQ(0, analogRead(0));
}
