#pragma once
#ifndef EVALUATOR_H
#define EVALUATOR_H
#include <string>
#include <string.h>
using namespace std;

class Evaluator {

public:
	Evaluator();
	~Evaluator();
	string convertToPostfix(string);
	string PostfixToResult(string);
};




#endif EVALUATOR_H