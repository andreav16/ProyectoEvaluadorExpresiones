#include "Validations.h"
#include <iostream>
#include <string>
#include <string.h>
#include <any>
#include <fstream>
#include <algorithm>


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
			cout << "¡ERROR! No ingrese operadores al inicio de expresión" << endl;
			return false;
		}

		//Que no ingrese operadores juntos
		if (expre.at(x) == '+' || expre.at(x) == '-' || expre.at(x) == '*' || expre.at(x) == '/' || expre.at(x) == '^' || expre.at(x) == '%' || expre.at(x) == '(')
		{
			if (expre.at(x + 1) == '+' || expre.at(x + 1) == '-' || expre.at(x + 1) == '*' || expre.at(x + 1) == '/' || expre.at(x + 1) == '^' || expre.at(x + 1) == '%' || expre.at(x + 1) == ')')
			{
				cout << "¡ERROR! No ingrese dos ó más operadores de manera seguida" << endl;
				return false;
			}
		}


	}
	return true;
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
			if (isalpha(expre.at(x)) && ((isdigit(expre.at(x + 1))) || isdigit(expre.at(x - 1))) || (isdigit(expre.at(x)) && (isalpha(expre.at(x + 1)) || isalpha(expre.at(x - 1))))) {
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
		if (expre.find('/') || expre.find('%'))//-->C++11
			if (expre.at(x) == '/' || expre.at(x) == '%') {
				if (expre.at(x + 1) == '0') {
					return false;
				}
			}
	}
	return true;
}

//Eliminar espacios en la expresión ingresada
string Validations::removeSpaces(string expre)noexcept(nullptr) {//-->C++17
	basic_string<char> refactoredExp = "";//-->C++14
	for (int x = 0; x < expre.length(); x++) {
		if (expre.at(x) != ' ')
		{
			refactoredExp += expre.at(x);
		}
	}
	return refactoredExp;
}

inline bool isNumber(const string& s)//-->C++17
{
	return std::ranges::all_of(s.begin(), s.end(),
		[](char c) { return isdigit(c) != 0; });
}

string Validations::finalExpression(string expre)noexcept(nullptr) {//-->C++17
	ifstream txtfile;
	txtfile.open("constantes.txt");
	auto constants = ""s;//-->texto con las constantes y sus valores
	auto s = ""s;//-->String temporal para ir concatenando las constantes del texto
	auto finalExpre = ""s;//-->Aquí se almacena ya la expresión sin variables sino con números
	auto num = ""s;//-> para concatenar mientras hago validación de txt
	int r = 0;//-->contador
	string ing = "";//-->Para que usuario ingrese valor de variable, es temp
	bool ya = true;//-->para verificar si variable ya está en archivo
	if (!txtfile) {
		cout << "¡Error en abrir archivo!" << endl;
		return nullptr;//-->C++11
	}

	while (getline(txtfile, s)) {
		constants += s;
	}

	for (int x = 0; x < expre.length(); x++) {
		if (isalpha(expre.at(x)) && expre.at(x) != 'p' && expre.at(x) != 'i') {
			for (int y = 0; y < constants.length(); y++) {
				if (constants.at(y) == expre.at(x)) {
					r = y + 2;
					while (!isalpha(constants.at(r))) {
						num += constants.at(r);
						r++;
						if (r == constants.length()) {
							goto a;
						}
					}
				a:	finalExpre += num;
					r = 0;
					num = "";
					ya = false;
				}

			}

			if (ya) {
			b:	cout << "Ingrese valor para " << expre.at(x) << ": ";
				getline(cin, ing);
				if (!isNumber(ing)) {
					cout << "Solo puede ingresar dígitos" << endl;
					goto b;
				}
				finalExpre += ing;
			}
			ya = true;


		}
		else if (expre.at(x) == 'p') {
			for (int i = 0; i < constants.length(); i++) {
				if (constants.at(i) == 'p' && constants.at(i + 1) == 'i') {
					r = i + 3;
					while (!isalpha(constants.at(r))) {
						num += constants.at(r);
						r++;
					}
					finalExpre += num;
					r = 0;
					num = "";
				}
			}
		}
		else {
			finalExpre += expre.at(x);
		}


	}
	txtfile.close();
	return finalExpre;
}

Validations::~Validations() {

}