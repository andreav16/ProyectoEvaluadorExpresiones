#include "pch.h"
#include "CppUnitTest.h"
#include "../21911267_ProyectoLenguajes/Validations.h"
#include "../21911267_ProyectoLenguajes/Evaluator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		Validations val;
		TEST_METHOD(CheckParenthesis)
		{
			string expression = "8+(28/8)+2";
			Assert::IsTrue(val.checkParenthesis(expression));
			
		}
		TEST_METHOD(CheckFinalOperator)
		{
			string expression = "14+(2*8)-2";
			Assert::IsTrue(val.checkFinalOperator(expression));

		}
		TEST_METHOD(CheckFirstOperator)
		{
			string expression = "2+(1+2)*2+(8-6)";
			Assert::IsTrue(val.checkOperatorRules(expression));

		}
		TEST_METHOD(checkCharacters)
		{
			string expression = "8%8+1";
			Assert::IsTrue(val.checkCharacters(expression));

		}
		TEST_METHOD(checkNumChar)
		{
			string expression = "8+5+(3+2)";
			Assert::IsTrue(val.checkNumChar(expression));

		}
		TEST_METHOD(checkDecimal)
		{
			string expression = "8+5.+(8/7)";
			Assert::IsTrue(val.checkDecimal(expression));

		}
		TEST_METHOD(checkInvalidDeno)
		{
			string expression = "8+5+(2/0)";
			Assert::IsFalse(val.checkNumChar(expression));

		}
		TEST_METHOD(CheckParenthesisFailed)
		{
			string expression = "8+5+(3+2";
			Assert::IsTrue(val.checkParenthesis(expression));

		}
		TEST_METHOD(checkCharactersFailed)
		{
			string expression = "8+aa+(3+2)";
			Assert::IsTrue(val.checkCharacters(expression));

		}
		TEST_METHOD(CheckFinalOperatorFailed)
		{
			string expression = "8+5+3+2*";
			Assert::IsFalse(val.checkNumChar(expression));

		}
	};
	
}
