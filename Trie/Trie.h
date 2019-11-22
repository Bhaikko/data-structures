#include "Node.h"

class Trie
{
    private:
        Node* root;
        void insert_word(Node* root, std::string);
        void delete_word(Node* root, std::string);
        bool search_word(Node* root, std::string);

    public:
        Trie();
        void insert_word(std::string word);
        void delete_word(std::string word);
        bool search_word(std::string word);
};