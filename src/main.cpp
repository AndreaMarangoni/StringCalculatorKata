/*
 * main.cpp
 *
 *  Created on: 10 May 2014
 *      Author: andy
 */

#include <iostream>
#include <string>
#include <exception>

#include "StringCalculatorKata.h"
#include <gtest/gtest.h>

TEST(StringCalculatorKataTestCase,InputCanTakeInfiniteNumbersCommaSeparated) {
	StringCalculatorKata kata;
	ASSERT_EQ(0, kata.add(""));
	ASSERT_EQ(0, kata.add("0"));
	ASSERT_EQ(1, kata.add("1"));
	ASSERT_EQ(2, kata.add("2"));
	ASSERT_EQ(3, kata.add("1,2"));
	ASSERT_EQ(6, kata.add("1,2,3"));
	ASSERT_EQ(10, kata.add("1,2,3,4"));
	ASSERT_EQ(15, kata.add("1,2,3,4,5"));
}

TEST(StringCalculatorKataTestCase,NegativeInputThrowAnException) {
	StringCalculatorKata kata;
	ASSERT_THROW(kata.add("-1"), std::exception);
	ASSERT_THROW(kata.add("-2"), std::exception);
	ASSERT_NO_THROW(kata.add("1,3"));
}

TEST(StringCalculatorKataTestCase,SeparatorCanBeCommaOrNewLine) {
	StringCalculatorKata kata;
	ASSERT_EQ(6, kata.add("1\n2\n3"));
	ASSERT_EQ(10, kata.add("1\n2\n3,4"));
	ASSERT_EQ(15, kata.add("1,2,3\n4,5"));
	ASSERT_THROW(kata.add("1,"), std::exception);
	ASSERT_THROW(kata.add("1\n"), std::exception);
	ASSERT_THROW(kata.add("1,\n"), std::exception);
}

TEST(StringCalculatorKataTestCase,NumbersGreaterThan1024MustBeIgnored) {
	StringCalculatorKata kata;
	ASSERT_EQ(1025, kata.add("1,1024"));
	ASSERT_EQ(1024, kata.add("1024"));
	ASSERT_EQ(0, kata.add("1025"));
	ASSERT_EQ(1, kata.add("1,1025"));
}

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

