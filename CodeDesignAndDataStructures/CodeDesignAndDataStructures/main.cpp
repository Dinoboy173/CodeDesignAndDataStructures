#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList<int> list;

    list.PushFront(30);
    list.PushFront(20);
    list.PushFront(10);

    list.Clear();

    list.PushBack(40);
    list.PushBack(50);
    list.PushBack(60);

    list.PopBack();

    list.PopFront();

    
}
