#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_3.2/Lab_3.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int N = 1;
			Student* s = new Student[N];
			s[0].specialnist = (Specialnist)1;
			s[0].physics = 5;
			s[0].prizv = "Zheplinskyi";
			Assert::AreEqual(-1, BinarP(s, N, s[0].prizv, s[0].specialnist, 1));

		}
	};
}
