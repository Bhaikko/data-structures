#include "./LinkedList.h"


int main() 
{
    LinkedList* list = new LinkedList();

    int input;

    while (true) {
        std::cin >> input;

        if (input == -1) {
            break;
        }

        list->insertNode(input);
    }
    // 2 3 1 3 4 5 6 1 2 3 -1

    list->printList();

    list->deleteNode(2);
    list->deleteNode(0);

    list->printList();

    std::cout << list->length() << std::endl;

    LinkedList* reversedList = list->reverse();
    reversedList->printList();

    return 0;
}