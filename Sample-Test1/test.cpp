#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

class SimilarityCheckerFixture : public testing::Test
{
public:
	SimilarityChecker checker;
};

TEST_F(SimilarityCheckerFixture, SameLength) {
	EXPECT_EQ(60, checker.getLengthPoint("ASD", "DSA"));
}

TEST_F(SimilarityCheckerFixture, DoubleLength) {
	EXPECT_EQ(0, checker.getLengthPoint("A", "BB"));
}