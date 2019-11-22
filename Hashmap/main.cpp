#include "Map.h"

int main()
{
    Map* map = new Map();

    map->insert_data("A", 65);
    map->insert_data("B", 66);
    map->insert_data("C", 67);
    map->insert_data("D", 68);
    map->insert_data("E", 69);

    std::cout << map->search("A") << std::endl;
    std::cout << map->search("B") << std::endl;
    std::cout << map->search("C") << std::endl;
    std::cout << map->search("D") << std::endl;
    std::cout << map->search("E") << std::endl;
    std::cout << map->search("F") << std::endl;

    map->insert_data("A", 123);
    std::cout << map->search("A") << std::endl;

    map->erase_data("A");
    std::cout << map->search("A") << std::endl;

    return 0;
}