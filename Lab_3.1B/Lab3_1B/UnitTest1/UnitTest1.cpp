#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab3_1B/Lab3_1B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest31
{
	TEST_CLASS(UnitTest31)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int N = 2;
			Student* s = new Student[N];
			s[0].math = 3;
			s[0].physics = 3;
			s[0].programming = 3;
			s[1].math = 2;
			s[1].physics = 3;
			Assert::AreEqual(2, PhysicsFourOrFive(s, N));
		}
	};
}

