#include <gtest/gtest.h>
//#include "../src/lib/veclib/include/vector2d.h"
#include "vector2d.h"

namespace {
int GetMeaningOfLife() { return 42; }
}  // namespace

TEST(TestTopic1, TrivialEquality){
    EXPECT_EQ(GetMeaningOfLife(),42);
}


TEST(TestTopic2, ChekcingAgain){
    EXPECT_EQ(GetMeaningOfLife(),40);
}

TEST(TestTopic3, ChekcingVector){
    immutable::vector2d<int> v = immutable::vector2d<int>(1012, 121);
    EXPECT_EQ(v.get_x(), 1012);
    EXPECT_EQ(v.get_y(), 121);
}

