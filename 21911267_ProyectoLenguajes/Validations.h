#pragma once
#ifndef VALIDATIONS_H
#define VALIDATIONS_H

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Validations {

public:
	Validations();
	~Validations();
	bool checkFinalOperator(string);
	bool checkOperatorRules(string);
	bool checkParenthesis(string);
	bool checkCharacters(string);
	bool checkDecimal(string);
	bool checkInvalidDeno(string);
	string removeSpaces(string);


};

#endif // !VALIDATIONS_H
