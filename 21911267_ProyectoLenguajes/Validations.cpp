#include "Validations.h"
#include <iostream>
#include <string>
#include <string.h>
#include <any>
#include <stack>

using namespace std;

Validations::Validations() {

}

//Funcion para revisar si se ingresó un operador al final de expresión
bool Validations::checkFinalOperator(string expre)noexcept(false) //--> C++17
{

	if (expre.at(expre.length() - 1) == '+') {
		return false;
	}
	else if (expre.at(expre.length() - 1) == '-') {
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
	else if (expre.at(expre.length() - 1) == '.') {
		return false;
	}
	else {
		return true;
	}

}

bool Validations::checkOperatorRules(string expre)noexcept(false) {//--> C++17

	for (int x = 0; x < expre.length(); x++) {
		//Que no ingrese operadores al inicio
		if (expre.at(0) == '+' || expre.at(0) == '-' || expre.at(0) == '*' || expre.at(0) == '/' || expre.at(0) == '%' || expre.at(0) == '^' || expre.at(0) == ')') {
			return false;
		}

		//Que no ingrese operadores juntos
		if (expre.at(x) == '+' || expre.at(x) == '-' || expre.at(x) == '*' || expre.at(x) == '/' || expre.at(x) == '^' || expre.at(x) == '%' || expre.at(x) == '(')
		{
			if (expre.at(x + 1) == '+' || expre.at(x + 1) == '-' || expre.at(x + 1) == '*' || expre.at(x + 1) == '/' || expre.at(x + 1) == '^' || expre.at(x + 1) == '%' || expre.at(x + 1) == ')')
			{
				return false;
			}
		}

		//Revisar que no haya operador de primero al inicio de paréntesis
		if (expre.at(x) == '+' || expre.at(x) == '-' || expre.at(x) == '*' || expre.at(x) == '/' || expre.at(x) == '^' || expre.at(x) == '%')
		{
			if (expre.at(x - 1) == '(')
			{
				return false;
			}
		}
		return true;

	}
}

//Revisar si cerró paréntesis
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

//Que no ingrese dos caracteres seguidos
			  /*if (isalpha(expre.at(x)) && isalpha(expre.at(x + 1)) && expre.at(x) != 'p' && expre.at(x + 1) != 'i')
			  {
				  cout << "¡No ingrese dos caracteres seguidos!" << endl;
				  return false;
			  }*/

bool Validations::checkCharacters(string expre)noexcept(false) {//--> C++17


	any val = true; //-->C++17
	for (int x = 0; x < expre.length() - 1; x++)
	{
		//Para validar que no ingrese dos caracteres seguidos
		if (isalpha(expre.at(x)) && isalpha(expre.at(x + 1)) && expre.at(x) != 'p' && expre.at(x + 1) != 'i')
		{
			val = false;
		}
		switch (any_cast<bool>(val)) {//-->C++17
		case false: {
			bool check = any_cast<bool>(val);
			if (!check) {
				cout << "¡No ingrese dos caracteres seguidos!" << endl;
				return false;
				break;
			}

		}
		}
	}
	return true;

}

//Revisar si no ingresó carácter y numero juntos
bool Validations::checkNumChar(string expre)noexcept(false) {
	for (int x = 0; x < expre.length() - 1; x++)
	{
		if (x > 0) {
			if ((isalpha(expre.at(x) && (isdigit(expre.at(x + 1)) || isdigit(expre.at(x - 1))))) || (isdigit(expre.at(x)) && (isalpha(expre.at(x + 1)) || isalpha(expre.at(x - 1))))) {
				return false;
			}
		}
		else if (x == 0) {
			if ((isalpha(expre.at(x)) && isdigit(expre.at(x + 1))) || (isdigit(expre.at(x)) && isalpha(expre.at(x + 1)))) {
				return false;
			}
		}

	}
	return true;
}

//revisar que sea un numero despues de punto
bool Validations::checkDecimal(string expre)noexcept(false) {//-->C++17

	for (int x = 0; x < expre.length() - 1; x++) {
		if (expre.at(x) == '.' && !isdigit(expre.at(x + 1))) {
			return false;
		}
	}
	return true;
}

//Revisar si denominador es distinto de 0
bool Validations::checkInvalidDeno(string expre)noexcept(false) {//-->C++17
	for (int x = 0; x < expre.length() - 1; x++) {
		if (expre.at(x) == '/' || expre.at(x) == '%') {
			if (expre.at(x + 1) == '0') {
				return false;
			}
		}
	}
	return true;
}

Validations::~Validations() {

}