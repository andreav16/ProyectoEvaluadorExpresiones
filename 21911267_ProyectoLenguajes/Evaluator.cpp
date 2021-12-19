#include "Evaluator.h"
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

Evaluator::Evaluator() {

}
/*constexpr float exp(float x, int n)
{
	return n == 0 ? 1 :
		n % 2 == 0 ? exp(x * x, n / 2) :
		exp(x * x, (n - 1) / 2) * x;
		//ASÍ SE LLAMA
		float x = exp(5, 6);
	cout << x << endl;

}*/


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
	string result = "";
	vector<string> operators;

	

}

Evaluator::~Evaluator() {

}