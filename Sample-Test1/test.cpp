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

TEST_F(SimilarityCheckerFixture, GetAlphaPointWhenSame) {
	EXPECT_EQ(40, checker.getAlphaPoint("ASD", "DSA"));
	EXPECT_EQ(40, checker.getAlphaPoint("AAABB", "BA"));
}

TEST_F(SimilarityCheckerFixture, GetAlphaPointWhenDifferentAll) {
	EXPECT_EQ(0, checker.getAlphaPoint("A", "BB"));
}

TEST_F(SimilarityCheckerFixture, GetAlphaPointPartial) {
	EXPECT_EQ(20, checker.getAlphaPoint("AA", "AAE"));
}