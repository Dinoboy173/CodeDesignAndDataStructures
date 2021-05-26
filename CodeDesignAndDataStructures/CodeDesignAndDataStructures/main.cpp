#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList<int> list = { 40, 10, 20, 40, 30, 50, 40, 60, 70, 40 };

    for (auto iter = list.begin(); iter != list.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    std::cout << std::endl;

    for (auto iter = list.begin(); iter != list.end();)
    {
        if (*iter == 40)
        {
            iter = list.Remove(iter);
        }
        else
        {
            iter++;
        }
    }

    auto iter = std::find(list.begin(), list.end(), 70);

    list.Insert(iter, 80);

    std::cout << std::endl;

    /*LinkedList<int> myList = { 10, 20, 30, 40, 50, 60 };
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
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 0" << std::endl;*/
}