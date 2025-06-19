#include <gtest/gtest.h>
#include "Tax.h"

TEST(PolandTaxTest, Over26LowIncome) {         //test for age pl above or equal 26
    pl user;
    user.set_income("100000");
    user.set_home("100");
    user.set_age("30");

    user.calculate_taxes();

    EXPECT_EQ(user.income_taxes, "12000.000000 PLN");
    EXPECT_EQ(user.estate_taxes, "118.000000 PLN");
}

TEST(PolandTaxTest, Over26HighIncome) {
    pl user;
    user.set_income("130000");
    user.set_home("200");
    user.set_age("40");

    user.calculate_taxes();

    EXPECT_EQ(user.income_taxes, "41600.000000 PLN");
    EXPECT_EQ(user.estate_taxes, "236.000000 PLN");
}

TEST(PolandTaxTest, Under26) {           //test for age pl below 26
    pl user;
    user.set_income("130000");
    user.set_home("200");
    user.set_age("25");

    user.calculate_taxes();

    EXPECT_EQ(user.income_taxes, "0 PLN");
    EXPECT_EQ(user.estate_taxes, "0 PLN");
}


TEST(UkraineTaxTest, Adult) {        //test for ua
    ua user;
    user.set_income("50000");
    user.set_home("100");
    user.set_age("30");

    user.calculate_taxes();

    EXPECT_EQ(user.income_taxes, "9000.000000 UAH");
    EXPECT_EQ(user.estate_taxes, "50.000000 UAH");
}

TEST(UkraineTaxTest, Minor) {
    ua user;
    user.set_income("50000");
    user.set_home("100");
    user.set_age("17");

    user.calculate_taxes();

    EXPECT_EQ(user.income_taxes, "0 UAH");
    EXPECT_EQ(user.estate_taxes, "0 UAH");
}
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}