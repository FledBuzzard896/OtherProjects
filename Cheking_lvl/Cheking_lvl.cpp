#include "pch.h"
#include "CppUnitTest.h"
#include "../Distribution_of_mobs_REPO/Distribution_of_mobs_REPO.cpp"
#include "vector"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Chekinglvl
{
	TEST_CLASS(Chekinglvl_Good)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			REPO_Game TEST;

			vector<string> lst{"Robe"};

			Assert::AreEqual(lst, TEST.translating_for_RUS(lst));
		}
	};

	TEST_CLASS(Chekinglvl_Bad)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			REPO_Game TEST;

			vector<string> lst{"Vector is empty"};

			Assert::AreEqual(lst, TEST.translating_for_RUS(vector<string>()));
		}
	};
}
