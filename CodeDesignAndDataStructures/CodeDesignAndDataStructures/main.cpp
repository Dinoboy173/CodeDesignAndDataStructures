#include <iostream>
#include "LinkedList.h"

int main()
{
    int sortAttempts = 0;

    LinkedList<int> list = { 10, 20, 30, 40, 50, 60, 70 };

    for (auto iter = list.begin(); iter != list.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    std::cout << std::endl;

    while (true)
    {
        std::string command = "";

        std::cin >> command;

        if (command == "sort")
        {
            list.Sort();

            sortAttempts++;

            for (auto iter = list.begin(); iter != list.end(); iter++)
            {
                std::cout << *iter << std::endl;
            }
            std::cout << std::endl;
            std::cout << sortAttempts << std::endl << std::endl;
        }
    }

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