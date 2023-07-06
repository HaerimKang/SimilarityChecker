#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

class SimilarityCheckerFixture : public testing::Test
{
public:
	SimilarityChecker checker;
};

TEST_F(SimilarityCheckerFixture, GetLengthPointWhenSameLength) {
	EXPECT_EQ(60, checker.getLengthPoint("ASD", "DSA"));
}

TEST_F(SimilarityCheckerFixture, GetLengthPointWhenDoubleLength) {
	EXPECT_EQ(0, checker.getLengthPoint("A", "BB"));
}

TEST_F(SimilarityCheckerFixture, GetLengthPointWhenDifferentText) {
	EXPECT_EQ(20, checker.getLengthPoint("AAABB", "BAA"));
	EXPECT_EQ(30, checker.getLengthPoint("AA", "AAE"));
}