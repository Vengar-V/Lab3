#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab3_3/Lab3_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int N = 3;
			int tmp = 0;
			Route* r = new Route[N];
			r[0].num = 23;
			r[1].num = 12;
			r[2].num = 3;
			Sort(r, N);
			Assert::AreEqual(3, r[0].num);
		}
	};
}
