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
};




#endif EVALUATOR_H