#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06.4Recur/Lab_06.4Recur.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int inmin = 0;
			double* p;
			p = new double[5];
			p[0] = 2.;
			p[1] = 7.3;
			p[2] = 78.;
			p[3] = 6.;
			p[4] = 45.;
			double S = minl(p, 5, inmin, 1, p[0]);

			Assert::AreEqual(S, 2.);
		}
	};
}
