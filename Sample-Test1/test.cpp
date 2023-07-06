#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

TEST(TestCaseName, SameLength) {
	SimilarityChecker checker;
	EXPECT_EQ(60, checker.getLengthPoint("ASD", "DSA"));
}

TEST(TestCaseName, DoubleLength) {
	SimilarityChecker checker;
	EXPECT_EQ(0, checker.getLengthPoint("A", "BB"));
}