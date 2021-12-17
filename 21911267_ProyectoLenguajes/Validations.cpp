#include "Validations.h"
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

Validations::Validations() {

}

//Funcion para revisar el operador final
bool Validations::checkFinalOperator(string expre)noexcept(false) //--> C++17
{
	
	if (expre.at(expre.length()-1) == '+') {
		return false;
	}else if (expre.at(expre.length()-1) == '-') {
		return false;
	}
	else if (expre.at(expre.length() - 1) == '*') {
		return false;
	}
	else if (expre.at(expre.length() - 1) == '/') {
		return false;
	}
	else if (expre.at(expre.length() - 1) == '%') {
		return false;
	}
	else if (expre.at(expre.length() - 1) == '^') {
		return false;
	}
	else {
		return true;
	}

}

bool Validations::checkOperatorRules(string expre)noexcept(false) {//--> C++17

	for (int x = 0; x < expre.length(); x++) {
		if (expre.at(0) == '+' || expre.at(0) == '-' || expre.at(0) == '*' || expre.at(0) == '/' || expre.at(0) == '%' || expre.at(0) == '^' || expre.at(0) == ')') {
			return false;
		}

		if (expre.at(x) == '+' || expre.at(x) == '-' || expre.at(x) == '*' || expre.at(x) == '/' || expre.at(x) == '^' || expre.at(x) == '%' || expre.at(x) == '(')
		{
			if (expre.at(x+1) == '+' || expre.at(x+1) == '-' || expre.at(x+1) == '*' || expre.at(x+1) == '/' || expre.at(x+1) == '^' || expre.at(x+1) == '%' || expre.at(x+1) == ')')
			{
				return false;
			}
		}

		//revisar numeros negativos
		//esta agregarle que si despues de ( es -
		if (expre.at(x) == '+' || expre.at(x) == '-' || expre.at(x) == '*' || expre.at(x) == '/' || expre.at(x) == '^' || expre.at(x) == '%')
		{
			if (expre.at(x-1) == '(')
			{
				return false;
			}
		}
		return true;

	}
}

bool Validations::checkParenthesis(string expre)noexcept(false) {//--> C++17
	int leftPar = 0, rightPar = 0;

	for (int x = 0; x < expre.length(); x++)
	{
		if (expre.at(x) == '(') {
			leftPar++;
		}
		else if (expre.at(x) == ')') {
			rightPar++;
		}

		if (leftPar == rightPar) {
			leftPar = rightPar = 0;
		}
	}
	if (leftPar != rightPar) {
		return false;
	}
	return true;
}


bool Validations::checkCharacters(string expre)noexcept(false) {//--> C++17
	
	for (int x = 0; x < expre.length(); x++)
	{
		if (expre.at(x) != 'p' && expre.at(x) != 'i' && expre.at(x) != 'e' && isalpha(expre.at(x)))
		{
			return false;
		}
		if (expre.at(0) == 'i')
		{
			return false;
		}
		if (x != 0 && expre.at(x) == 'i' && expre.at(x - 1) != 'p')
		{
			return false;
		}
		if (x != expre.length() - 1 && (expre.at(x) == 'p' && expre.at(x + 1) != 'i'))
		{
			return false;
		}
		if (expre.at(expre.length() - 1) == 'p')
		{
			return false;
		}
	}
	return true;
	
}

Validations::~Validations() {

}