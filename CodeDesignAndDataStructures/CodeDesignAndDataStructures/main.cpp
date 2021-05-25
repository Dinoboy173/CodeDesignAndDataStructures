#include <iostream>
#include "LinkedList.h"

int main()
{
    //LinkedList<int> list = { 40, 10, 20, 40, 30, 50, 40, 60, 70, 40 };

    //for (auto iter = list.begin(); iter != list.end(); iter++)
    //{
    //    std::cout << *iter << std::endl;
    //}

    //std::cout << std::endl;

    //for (auto iter = list.begin(); iter != list.end();)
    //{
    //    // we want to remove all occurences of 99
    //    if (*iter == 40)
    //    {
    //        // remove the node - update iter so that its pointing
    //        // at the next valid item
    //        iter = list.Remove(iter);
    //    }
    //    else
    //    {
    //        // if we didnt remove, we can move to the next item
    //        iter++;
    //    }
    //}

    //auto iter = std::find(list.begin(), list.end(), 30);

    //list.Insert(iter, 35);

    //for (auto& value : list)
    //{
    //    std::cout << value << std::endl;
    //}

    //std::cout << std::endl;

    //LinkedList<int>::Node* rIter = list.LastNode();
    //while (rIter != nullptr)
    //{
    //    std::cout << rIter->value << std::endl;
    //    rIter = rIter->prev;
    //}

    LinkedList<int> myList = { 10, 20, 30, 40, 50, 60 };
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 6" << std::endl;

    myList.PushBack(70);
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 7" << std::endl;
    
    myList.PushFront(5);
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 8" << std::endl;
    
    myList.PopBack();
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 7" << std::endl;
    
    myList.PopFront();
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 6" << std::endl;
    
    myList.Remove(std::find(myList.begin(), myList.end(), 30));
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 5" << std::endl;
    
    myList.PopBack();
    myList.PopBack();
    myList.PopBack();
    myList.PopBack();
    myList.PopBack();
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 0" << std::endl;

    myList = { 10, 20, 30, 40, 50, 60 };
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 6" << std::endl;

    myList.Clear();
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 0" << std::endl;
}