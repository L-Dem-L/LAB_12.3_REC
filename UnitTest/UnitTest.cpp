#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_12.3_REC/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
        TEST_METHOD(TestCountOddElements)
        {
            int values1[] = { 1, 2, 3, 4, 5 };
            int size1 = sizeof(values1) / sizeof(values1[0]);
            Node* head1 = createList(values1, size1);
            Assert::AreEqual(3, countOddElements(head1)); 

            int values2[] = { 1, 2, 3, 4, 5, 6, 7 };
            int size2 = sizeof(values2) / sizeof(values2[0]);
            Node* head2 = createList(values2, size2);
            Assert::AreEqual(4, countOddElements(head2));

            Node* head3 = nullptr;
            Assert::AreEqual(0, countOddElements(head3));

            int values4[] = { 2 };
            int size4 = sizeof(values4) / sizeof(values4[0]);
            Node* head4 = createList(values4, size4);
            Assert::AreEqual(0, countOddElements(head4));

            int values5[] = { -1, -2, -3, -4, -5 };
            int size5 = sizeof(values5) / sizeof(values5[0]);
            Node* head5 = createList(values5, size5);
            Assert::AreEqual(3, countOddElements(head5));

            deleteList(head1);
            deleteList(head2);
            deleteList(head4);
            deleteList(head5);
        }

	};
}
