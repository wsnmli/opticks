//  g++ -o test Vector2iTest.cpp -lgtest -pthread && ./test

#include <gtest/gtest.h>
#include "../math.hpp"

class Vector2iTest : public::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(Vector2iTest, AdditionOperator) {
    Vector2i v1(5, 3), v2(4, 7), result;
    result = v1 + v2;
    EXPECT_EQ(result.x, 9);
    EXPECT_EQ(result.y, 10);
}

TEST_F(Vector2iTest, CompoundAdditionOperator) {
    Vector2i O, A(1,2);
    O += A;
    EXPECT_EQ(O.x, A.x);
    EXPECT_EQ(O.y, A.y);
}

TEST_F(Vector2iTest, DistanceFunction) {
    Vector2i O, A(10,10);
    EXPECT_EQ((10*10)+(10*10), distance_squared(O, A));
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}