#include "singly_linked_list.hpp"
#include <iostream>
int main() {
    LinkedList list1, list2, list3, list4, list5;
    list1.print();  // null

    std::cout << "Inserting 3, 2, 1 using insert_front" << std::endl;
    list1.insert_front(1);
    list1.insert_front(2);
    list1.insert_front(3);
    list1.print();  // 3 -> 2 -> 1 -> null

    std::cout << "Inserting 3, 2, 1 using insert_back" << std::endl;
    list2.insert_back(3);
    list2.insert_back(2);
    list2.insert_back(1);
    list2.print();  // 3 -> 2 -> 1 -> null

    std::cout << "Inserting 3, 2, 1 using insert_at" << std::endl;
    list3.insert_at(0, 1);
    list3.insert_at(0, 2);
    list3.insert_at(0, 3);
    list3.print();  // 3 -> 2 -> 1 -> null

    std::cout << "Searching for 2, 4 in '3 -> 2 -> 1'" << std::endl;
    std::cout << list1.search(2) << std::endl;  // true
    std::cout << list1.search(4) << std::endl;  // false

    std::cout << "Removing for 2, 4 from '3 -> 2 -> 1'" << std::endl;
    std::cout << list1.remove(2) << std::endl;  // true
    std::cout << list1.remove(4) << std::endl;  // false
    list1.print();  // 3 -> 1 -> null

    std::cout << "Printing size 2, 3, 3" << std::endl;
    std::cout << list1.size() << std::endl;  // 2
    std::cout << list2.size() << std::endl;  // 3
    std::cout << list3.size() << std::endl;  // 3

    std::cout << "Inserting in random order  4, 1, 3, 2, 5" << std::endl;
    list4.insert_front(1);
    list4.insert_back(2);
    list4.insert_at(1, 3);
    list4.insert_front(4);
    list4.insert_back(5);
    list4.print();  // 4 -> 1 -> 3 -> 2 -> 5 -> null

    std::cout << "Removing middle element (3)" << std::endl;
    list4.remove(3);

    std::cout << "Removing a head element (4)" << std::endl;
    list4.remove(4);

    std::cout << "Removing a tail element (5)" << std::endl;
    list4.remove(5);

    std::cout << "Inserting and removing 1000 elements" << std::endl;
    for (int i = 0; i < 1000; i++) {
        list5.insert_front(i);
    }
    for (int i = 0; i < 1000; i++) {
        list5.remove(i);
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}