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
	a:	cout << endl << "Ingrese expresión en notación infija:";
		getline(cin, expression);
		expression = val.removeSpaces(expression);
		if (expression == "exit") {
			break;
		}
		if (!val.checkFinalOperator(expression)) {
			cout << "¡ERROR! No puede ingresar un operador al final de expresión" << endl;
			goto a;
		}
		if (!val.checkOperatorRules(expression)) {
			goto a;
		}
		if (!val.checkParenthesis(expression)) {
			cout << "¡ERROR! Paréntesis incompletos" << endl;
			goto a;
		}
		if (!val.checkCharacters(expression)) {
			goto a;
		}
		if (!val.checkDecimal(expression)) {
			cout << "¡ERROR! Número decimal incompleto" << endl;
			goto a;
		}
		if (!val.checkInvalidDeno(expression)) {
			cout << "¡ERROR! Denominador inválido" << endl;
			goto a;
		}
		if (!val.checkNumChar(expression)) {
			cout << "¡ERROR! No ingresar dígito junto con caracter" << endl;
			goto a;
		}
		expression = val.finalExpression(expression);
		evaluador.PostfixToResult(evaluador.convertToPostfix(expression));

	} while (expression != "exit");


}
