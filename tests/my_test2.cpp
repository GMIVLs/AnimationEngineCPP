#include <gtest/gtest.h>
#include "../src/lib/veclib/include/vector2d.h"

namespace {
int GetMeaningOfLife() { return 42; }
}  // namespace


TEST(TestTopic, TrivialEquality){
    EXPECT_EQ(GetMeaningOfLife(), 42);
}

TEST(TestTopic, MoreEqualityTests){
    ASSERT_EQ(GetMeaningOfLife(), 0) << "[ERROR]:: oh no!!, a mistake";
    vector2d<float> v = vector2d<float>(12.3, 32.43);
    EXPECT_FLOAT_EQ(v.get_x(), 12.3);
    EXPECT_FLOAT_EQ(v.get_y(), 32.43);
}


