#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <stack>
#include <sstream>
#include <any>

using namespace std;

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

int main() {
    
  
}