#include <gtest/gtest.h>
#include "Taxes base.cpp"

TEST(AccountTest, InputData) {
	pl user;
	user.input_data();
	EXPECT_EQ(user.get_login(), "test_login");
}

int main() {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}