#include "Trie.h"

int main()
{
    Trie* trie = new Trie();

    std::cout << (trie->search_word("air") ? "true" : "false") << std::endl;
    trie->insert_word("air");
    std::cout << (trie->search_word("air") ? "true" : "false") << std::endl;

    trie->insert_word("airo");
    trie->insert_word("aim");
    std::cout << (trie->search_word("airo") ? "true" : "false") << std::endl;
    std::cout << (trie->search_word("aim") ? "true" : "false") << std::endl;

    trie->delete_word("aim");
    std::cout << (trie->search_word("aim") ? "true" : "false") << std::endl;
    std::cout << (trie->search_word("aiming") ? "true" : "false") << std::endl;

    trie->insert_word("aiming");
    std::cout << (trie->search_word("aiming") ? "true" : "false") << std::endl;
    trie->insert_word("big");
    trie->insert_word("bigger");

    std::cout << (trie->search_word("bigger") ? "true" : "false") << std::endl;
}