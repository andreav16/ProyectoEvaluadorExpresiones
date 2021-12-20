#include "Evaluator.h"
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <stack>

Evaluator::Evaluator() {

}

constexpr auto sum(auto x, auto y) {//-->C++14
	return x + y;
}
constexpr auto sub(auto x, auto y) {//-->C++14
	return x - y;
}
auto mult = [](auto x, auto y) { return x * y; };//--->C++14
auto mod = [](auto x, auto y) { return x % y; };//--->C++14
auto expn = [](auto x, auto n) { return pow(x, n); };//--->C++14

string Evaluator::convertToPostfix(string expre) {
	string resultExp = "";
	stack<char> operators;
	vector<char> result;
	int prec= 0;
	int precStack = 0;

	for (int x = 0; x < expre.length(); x++) {
		if (expre.at(x) == '+' || expre.at(x) == '-' || expre.at(x) == '(' || expre.at(x) == ')' || expre.at(x) == '^' || expre.at(x) == '*' || expre.at(x) == '/' || expre.at(x) == '%') {
			if (operators.empty()) {
				operators.push(expre.at(x));
			}
			else if (operators.top() == '(') {
				operators.push(expre.at(x));
			}
			else if (expre.at(x) == '(') {
				operators.push(expre.at(x));
			}
			else if (expre.at(x) == ')') {
				while (operators.top() != '(') {
					result.push_back(operators.top());
					result.push_back(',');
					operators.pop();
				}
				operators.pop();
			}
			else {
				//Para determinar precedencia de operador en pila
				if (operators.top() == '(' || operators.top() ==')') {
					precStack = 4;
				}
				else if (operators.top() == '^') {
					precStack = 3;
				}else if (operators.top() == '*' || operators.top() == '/' || operators.top() == '%') {
					precStack = 2;
				}
				else if (operators.top() == '+' || operators.top() == '-') {
					precStack = 1;
				}

				//Para determinar precedencia de operador recorriendo
				if (expre.at(x) == '(' || expre.at(x) == ')') {
					prec = 4;
				}
				else if (expre.at(x)== '^') {
					prec = 3;
				}
				else if (expre.at(x) == '*' || expre.at(x) == '/' || expre.at(x) == '%') {
					prec = 2;
				}
				else if (expre.at(x) == '+' || expre.at(x) == '-') {
					prec = 1;
				}

				if (prec == precStack) {
					result.push_back(operators.top());
					result.push_back(',');
					operators.pop();
					operators.push(expre.at(x));
				}
				else if (prec > precStack) {
					operators.push(expre.at(x));
					result.push_back(',');
				}
				else if (prec < precStack) {
					result.push_back(operators.top());
					result.push_back(',');
					operators.pop();
					operators.push(expre.at(x));
				}

			}
		}
		else {
			
			result.push_back(expre.at(x));
			if (x + 1 <= expre.length() - 1 && !isdigit(expre.at(x + 1)) && expre.at(x + 1) != '.') // If next char is not end of expression, isn't a digit and isn't decimal point then concat ',' 
			{
				result.push_back(',');
			
			}
		}
	}
	while (!operators.empty()) {
		result.push_back(',');
		result.push_back(operators.top());
		operators.pop();
	}

	for (int x = 0; x < result.size(); x++) {
	    resultExp+=result.at(x);
	}
	result.shrink_to_fit();//-->C++11
	return resultExp;
}

Evaluator::~Evaluator() {

}