#include "list_f.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    list_f::Node *list = list_f::toList(v);

//    list_f::printList(list);

//    list = list_f::reverseList(list);
//    list_f::printList(list);

    list->next->next->next->next->next->next->next->next = list->next;

    std::cout << std::boolalpha <<  list_f::hasCycle(list) << std::endl;
    std::cout << list_f::cycleListCount(list) << std::endl;

//    list_f::deleteList(list);

    return 0;
}

