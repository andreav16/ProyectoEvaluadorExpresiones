#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <stack>
#include <sstream>
#include <any>
#include "Validations.h"
#include "Evaluator.h"
#include <locale.h>

using namespace std;

int main() {

	Validations val;
	Evaluator evaluador;
	auto expression = ""s; //-->C++14
	setlocale(LC_ALL, "spanish");

	cout << "--EVALUADOR DE EXPRESIONES POSTFIJAS--" << endl << "Para salir escriba \"exit\" ";
	do {
	a:	cout << endl << "Ingrese expresi�n en notaci�n infija:";
		getline(cin, expression);
		expression = val.removeSpaces(expression);
		if (expression == "exit") {
			break;
		}
		if (!val.checkFinalOperator(expression)) {
			cout << "�ERROR! No puede ingresar un operador al final de expresi�n" << endl;
			goto a;
		}
		if (!val.checkOperatorRules(expression)) {
			goto a;
		}
		if (!val.checkParenthesis(expression)) {
			cout << "�ERROR! Par�ntesis incompletos" << endl;
			goto a;
		}
		if (!val.checkCharacters(expression)) {
			goto a;
		}
		if (!val.checkDecimal(expression)) {
			cout << "�ERROR! N�mero decimal incompleto" << endl;
			goto a;
		}
		if (!val.checkInvalidDeno(expression)) {
			cout << "�ERROR! Denominador inv�lido" << endl;
			goto a;
		}
		if (!val.checkNumChar(expression)) {
			cout << "�ERROR! No ingresar d�gito junto con caracter" << endl;
			goto a;
		}
		expression = val.finalExpression(expression);
		evaluador.PostfixToResult(evaluador.convertToPostfix(expression));

	} while (expression != "exit");


}
