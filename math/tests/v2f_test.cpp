//  g++ -o test v2f_test.cpp -lgtest -pthread -Wall && ./test

#include <gtest/gtest.h>
#include "../math.hpp"

class V2f_Test : public::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() {}
};

TEST_F(V2f_Test, EqualityOperator) {
    V2f v1(3, 3), v2(3, 3);
    EXPECT_EQ(v1 == v2, true);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}