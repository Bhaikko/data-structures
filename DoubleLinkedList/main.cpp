#include "./DoubleLinkedList.h"


int main() 
{
    DoubleLinkedList* list = new DoubleLinkedList();

    int input;

    // 2 3 4 -1
    while(true) {
        std::cin >> input;
        if (input == -1) {
            break;
        }

        list->add_front(input);
    }

    // 2 4 5 -1
    while(true) {
        std::cin >> input;
        if (input == -1) {
            break;
        }

        list->add_end(input);
    }

    list->forward_traverse();
    list->backward_traverse();

    list->delete_node_from_front(0);
    list->delete_node_from_front(3);
    list->delete_node_from_front(2);

    list->forward_traverse();
    list->backward_traverse();
    return 0;
}