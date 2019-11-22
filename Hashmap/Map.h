#include "Node.h"

class Map
{
    private:
        Node** bucket;
        int count;
        int bucketSize;

    private:
        int hash(std::string key);
        void resize_bucket();

    public:
        Map();
        void insert_data(std::string key, int value);
        void erase_data(std::string key);
        int search(std::string key);
};