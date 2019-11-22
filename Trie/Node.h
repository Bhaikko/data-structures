#include <iostream>
#include <string>

class Node
{
    public:
        char data;
        Node** children;
        bool isTerminal;

        Node(char data)
        {   
            this->data = data;
            this->children = new Node*[26];

            for (int i = 0; i < 26; i++) {
                this->children[i] = NULL;
            }

            isTerminal = false;
        }
};