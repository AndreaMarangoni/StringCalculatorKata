/*
 * StringCalculatorKata.h
 *
 *  Created on: 10 May 2014
 *      Author: andy
 */

#ifndef STRINGCALCULATORKATA_H_
#define STRINGCALCULATORKATA_H_

#include <string>

class StringCalculatorKata {
public:
	int add(const std::string& numbers);
private:
	int strToInt(const std::string& str);
	bool isEmpty(const std::string& str) const;
	int getSum(const std::string& str);
	int getCurrentNumber(const std::string& str);
};

#endif /* STRINGCALCULATORKATA_H_ */
