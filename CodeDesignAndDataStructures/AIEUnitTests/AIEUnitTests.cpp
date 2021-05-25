#include "pch.h"
#include "CppUnitTest.h"

#include "../CodeDesignAndDataStructures/LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AIEUnitTests
{
	TEST_CLASS(AIELinkedListTest)
	{
	public:
		
		TEST_METHOD(Can_Create_Empty_List)
		{
			LinkedList<int> list;

			Assert::IsNull(list.FirstNode());
			Assert::IsNull(list.LastNode());

			Assert::IsTrue(list.IsEmpty());

			Assert::IsTrue(list.begin() == list.end());

			Assert::IsTrue(list.Count() == 0);
		}

		TEST_METHOD(Can_Create_List_With_Initialiser_List)
		{
            LinkedList<int> list = { 10, 20, 30, 40 };
            
            Assert::IsNotNull(list.FirstNode());
            Assert::IsNotNull(list.LastNode());
            
            Assert::AreEqual(list.FirstNode()->value, 10);
            Assert::AreEqual(list.LastNode()->value, 40);
            
            Assert::IsFalse(list.IsEmpty());
			
			int arr[5] = { 10, 20, 30, 40 };
            int index = 0;

            for (auto iter = list.begin(); iter != list.end(); iter++)
            {
				Assert::AreEqual(*iter, arr[index]);
                index++;
            }

			Assert::IsTrue(list.Count() == 4u);
		}

		TEST_METHOD(PushBack_List)
		{
			LinkedList<int> list = { 10, 20, 30 };

			list.PushBack(40);

			Assert::IsNotNull(list.FirstNode());
			Assert::IsNotNull(list.LastNode());

			Assert::AreEqual(list.FirstNode()->value, 10);
			Assert::AreEqual(list.LastNode()->value, 40);

			Assert::IsFalse(list.IsEmpty());

			Assert::IsTrue(list.Count() == 4u);
		}

		TEST_METHOD(PushFront_List)
		{
			LinkedList<int> list = { 20, 30, 40 };

			list.PushFront(10);

			Assert::IsNotNull(list.FirstNode());
			Assert::IsNotNull(list.LastNode());

			Assert::AreEqual(list.FirstNode()->value, 10);
			Assert::AreEqual(list.LastNode()->value, 40);

			Assert::IsFalse(list.IsEmpty());

			Assert::IsTrue(list.Count() == 4u);
		}

		TEST_METHOD(PopBack_List)
		{
			LinkedList<int> list = { 10, 20, 30, 40 };

			list.PopBack();

			Assert::IsNotNull(list.FirstNode());
			Assert::IsNotNull(list.LastNode());

			Assert::AreEqual(list.FirstNode()->value, 10);
			Assert::AreEqual(list.LastNode()->value, 30);

			Assert::IsFalse(list.IsEmpty());

			Assert::IsTrue(list.Count() == 3u);
		}

		TEST_METHOD(PopFront_List)
		{
			LinkedList<int> list = { 10, 20, 30, 40 };

			list.PopFront();

			Assert::IsNotNull(list.FirstNode());
			Assert::IsNotNull(list.LastNode());

			Assert::AreEqual(list.FirstNode()->value, 20);
			Assert::AreEqual(list.LastNode()->value, 40);

			Assert::IsFalse(list.IsEmpty());

			Assert::IsTrue(list.Count() == 3u);
		}

		TEST_METHOD(Clear_List)
		{
			LinkedList<int> list = { 10, 20, 30, 40 };

			list.Clear();

			Assert::IsNull(list.FirstNode());
			Assert::IsNull(list.LastNode());

			Assert::IsTrue(list.IsEmpty());

			Assert::IsTrue(list.begin() == list.end());

			Assert::IsTrue(list.Count() == 0);
		}

		TEST_METHOD(Remove_From_List)
		{
			// Test 1 in middle

			LinkedList<int> list1 = { 10, 20, 30, 40 };

			for (auto iter = list1.begin(); iter != list1.end();)
			{
				if (*iter == 30)
				{
					list1.Remove(iter);
				}
			}

			Assert::IsNotNull(list1.FirstNode());
			Assert::IsNotNull(list1.LastNode());

			Assert::AreEqual(list1.FirstNode()->value, 10);
			Assert::AreEqual(list1.LastNode()->value, 40);

			Assert::IsFalse(list1.IsEmpty());

			Assert::IsTrue(list1.Count() == 3u);

			for (auto iter = list1.begin(); iter != list1.end();)
			{
				Assert::IsFalse(*iter == 30);
			}

			// Test 2 on end

			LinkedList<int> list2 = { 10, 20, 30, 40 };

			for (auto iter = list2.begin(); iter != list2.end();)
			{
				if (*iter == 40)
				{
					list2.Remove(iter);
				}
			}

			Assert::IsNotNull(list2.FirstNode());
			Assert::IsNotNull(list2.LastNode());

			Assert::AreEqual(list2.FirstNode()->value, 10);
			Assert::AreEqual(list2.LastNode()->value, 30);

			Assert::IsFalse(list2.IsEmpty());

			Assert::IsTrue(list2.Count() == 3u);

			for (auto iter = list2.begin(); iter != list2.end();)
			{
				Assert::IsFalse(*iter == 40);
			}

			// Test 3 on beginning

			LinkedList<int> list3 = { 10, 20, 30, 40 };

			for (auto iter = list3.begin(); iter != list3.end();)
			{
				if (*iter == 10)
				{
					list3.Remove(iter);
				}
			}

			Assert::IsNotNull(list3.FirstNode());
			Assert::IsNotNull(list3.LastNode());

			Assert::AreEqual(list3.FirstNode()->value, 20);
			Assert::AreEqual(list3.LastNode()->value, 40);

			Assert::IsFalse(list3.IsEmpty());

			Assert::IsTrue(list3.Count() == 3u);

			for (auto iter = list3.begin(); iter != list3.end();)
			{
				Assert::IsFalse(*iter == 10);
			}

			// Test 4 remove multiple

			LinkedList<int> list4 = { 20, 10, 20, 30, 20 };

			for (auto iter = list4.begin(); iter != list4.end();)
			{
				if (*iter == 20)
				{
					list4.Remove(iter);
				}
			}

			Assert::IsNotNull(list4.FirstNode());
			Assert::IsNotNull(list4.LastNode());

			Assert::AreEqual(list4.FirstNode()->value, 10);
			Assert::AreEqual(list4.LastNode()->value, 30);

			Assert::IsFalse(list4.IsEmpty());

			Assert::IsTrue(list4.Count() == 2u);

			for (auto iter = list4.begin(); iter != list4.end();)
			{
				Assert::IsFalse(*iter == 20);
			}
		}

		TEST_METHOD(Insert_Into_List)
		{

		}
	};
}
