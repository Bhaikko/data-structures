#include "Trie.h"

Trie::Trie()
{
    this->root = new Node('\0');
}

void Trie::insert_word(Node* root, std::string word)
{
    if (word.size() == 0) {
        root->isTerminal = true;
        return;
    }

    int index = word[0] - 'a';
    Node* child;

    if (root->children[index] != NULL) {
        child = root->children[index];
    } else {
        child = new Node(word[0]);
        root->children[index] = child;
    }

    this->insert_word(child, word.substr(1));
}

void Trie::insert_word(std::string word)
{
    this->insert_word(this->root, word);
}

bool Trie::search_word(Node* root, std::string word)
{
    if (word.length() == 0) {
        return root->isTerminal;
    }

    int index = word[0] - 'a';
    Node* child;

    if (root->children[index] != NULL) {
        child = root->children[index];
    } else {
        return false;
    }

    return this->search_word(child, word.substr(1));

}


bool Trie::search_word(std::string word) 
{
    return this->search_word(this->root, word);
}

void Trie::delete_word(Node* root, std::string word)
{
    if (word.length() == 0) {
        root->isTerminal = false;
        return;
    }

    Node* child;
    int index = word[0] - 'a';

    if (root->children[index] != NULL) {
        child = root->children[index];
    } else {
        return;
    }

    // if (!child->isTerminal) {
    //     for (int i = 0; i < 26; i++) {
    //         if (child->children[i] != NULL) {
    //             return;
    //         }
    //         delete child;
    //         root->children[index] = NULL;
    //     }
    // }
    this->delete_word(child, word.substr(1));
}

void Trie::delete_word(std::string word)
{
    this->delete_word(this->root, word);
}