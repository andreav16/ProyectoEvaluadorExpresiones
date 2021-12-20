#include "Evaluator.h"
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <iomanip>
#include <sstream>
using namespace std;

Evaluator::Evaluator() {
}

constexpr auto sum(auto x, auto y) { return x + y; } //-->C++14
constexpr auto sub(auto x, auto y) { return x - y; } //-->C++14
auto mult = [](auto x, auto y) { return x * y; };//--->C++14
auto divi = [](auto x, auto y) { return x / y; };//--->C++14
auto mod = [](auto x, auto y) { return fmod(x, y); };//--->C++14
auto expn = [](auto x, auto n) { return pow(x, n); };//--->C++14

string Evaluator::convertToPostfix(string expre) {
	string resultExp = "";
	stack<char> operators;
	vector<char> result;
	int prec = 0;
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
				if (operators.top() == '(' || operators.top() == ')') {
					precStack = 4;
				}
				else if (operators.top() == '^') {
					precStack = 3;
				}
				else if (operators.top() == '*' || operators.top() == '/' || operators.top() == '%') {
					precStack = 2;
				}
				else if (operators.top() == '+' || operators.top() == '-') {
					precStack = 1;
				}

				//Para determinar precedencia de operador recorriendo
				if (expre.at(x) == '(' || expre.at(x) == ')') {
					prec = 4;
				}
				else if (expre.at(x) == '^') {
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
			if (x + 1 <= expre.length() - 1 && !isdigit(expre.at(x + 1)) && expre.at(x + 1) != '.') // Si el siguiente char no es final de expresión, ó digito o punto decimal entonces concatenar ',' para dividir 
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
		resultExp += result.at(x);
	}
	result.shrink_to_fit();//-->C++11
	return resultExp;
}

string Evaluator::PostfixToResult(string expre) {
	stack<float> operands;
	vector<string> expression;
	string concat = "";//--> Para factorizar los numeros para poder hacer las operaciones y evaluar
	string result = "";
	float num1 = 0.00;
	float num2 = 0.00;
	float resultOpe = 0.00;//-->Float para almacenar resultado de operación y luego push a pila
	float w = 0;//-->Counter para numero decimal
	string d = "";//-->para ir concatenando para meter a pila de operandos
	for (int x = 0; x < expre.length(); x++) {
		if (expre.at(x) == ',') {
			if (concat != "") {
				expression.push_back(concat);
				concat = "";
			}
		}
		else {
			if (expre.at(x) != ',') {
				concat += expre.at(x);
			}
		}
	}
	if (concat != "") {
		expression.push_back(concat);
		concat = "";
	}

	for (int x = 0; x < expression.size(); x++) {
		if (expression.at(x) != "+" && expression.at(x) != "-" && expression.at(x) != "*" && expression.at(x) != "/" && expression.at(x) != "^" && expression.at(x) != "%") {
			while (expression.at(x).size() > w) {
				d += expression.at(x).at(w);
				w++;
			}
			operands.push(atof(d.c_str()));
			d = "";
			w = 0;
		}
		else {
			num2 = operands.top();
			operands.pop();
			num1 = operands.top();
			operands.pop();

			if (expression.at(x) == "+") {
				resultOpe = sum(num1, num2);
			}
			else if (expression.at(x) == "-") {
				resultOpe = sub(num1, num2);
			}
			else if (expression.at(x) == "/") {
				resultOpe = divi(num1, num2);
			}
			else if (expression.at(x) == "%") {
				resultOpe = mod(num1, num2);
			}
			else if (expression.at(x) == "*") {
				resultOpe = mult(num1, num2);
			}
			else if (expression.at(x) == "*") {
				resultOpe = expn(num1, num2);
			}

		 operands.push(resultOpe);

		}
	}

	cout << "Resultado:"<<operands.top()<< endl;

	return expre;
}

Evaluator::~Evaluator() {

}