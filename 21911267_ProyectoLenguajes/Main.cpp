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

//c++11
//Toma el primer de una lista
/*std::vector<int> v = {3, 1, 4};
auto vi = std::begin(v);
std::cout << *vi << '\n';*/

//c++14
/*constexpr float exp(float x, int n)
{
	return n == 0 ? 1 :
		n % 2 == 0 ? exp(x * x, n / 2) :
		exp(x * x, (n - 1) / 2) * x;
		//ASÍ SE LLAMA
		float x = exp(5, 6);
	cout << x << endl;

}*/

/*
basic_string<char> s = "hola";
cout << s;
*/

//c++17
/*any a = 21;
	cout << any_cast<int>(a);*/

	/*
	*
	* auto get_value(int t) {
		if constexpr (nullptr)
			return t; // deduces return type to int for T = int*
		else
			return t;  // deduces return type to int for T = int
	}

	//para llamar
	  cout << get_value(2);

	*/

	/*
	switch (1) {
		case 1: {  int x = 0;
			std::cout << x << '\n';
			break;
		} // scope of 'x' ends here
		default: std::cout << "default\n"; // no error
			break;
		}
	*/

	/*inline int sum(int a, int b)
	{
		return a + b;
	}*/