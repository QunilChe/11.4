#include "pch.h"
#include "CppUnitTest.h"
#include "../11.4/proc.h"
#include "../11.4/11.4.cpp"
using namespace nsVar;
using namespace nsProc;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t = remove_line("gg", 1);
			Assert::AreEqual(t, 1);
		}
	};
}
