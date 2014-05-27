/*
 * StringCalculatorKata.cpp
 *
 *  Created on: 10 May 2014
 *      Author: andy
 */

#include "StringCalculatorKata.h"

#include <exception>
#include <boost/tokenizer.hpp>

using std::string;
using boost::tokenizer;

#define MAX_NUMBER 1024

int StringCalculatorKata::strToInt(const std::string& str) {
	return ::atoi(str.c_str());
}

int StringCalculatorKata::add(const std::string& numbers) {
	if (this->isEmpty(numbers)) {
		return 0;
	}
	int sum = this->getSum(numbers);
	return sum;
}

bool StringCalculatorKata::isEmpty(const std::string& str) const {
	return str.empty();
}

int StringCalculatorKata::getSum(const std::string& str) {
	int sum = 0;
	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
	boost::char_separator<char> sep(",", "\n", boost::keep_empty_tokens);
	tokenizer tokens(str, sep);
	for (tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end();
		++tok_iter) {
		sum += getCurrentNumber(*tok_iter);
	}
	return sum;
}

int StringCalculatorKata::getCurrentNumber(const std::string& str) {
	int currentNumber = strToInt(str);
	if (currentNumber < 0 || str.empty()) {
		throw std::exception();
	} else if(currentNumber > MAX_NUMBER){
		currentNumber = 0;
	}
	return currentNumber;
}
