#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class Node
{
    public:

        int universe_size;
        int minimum;
        int maximum;
        Node* summary;
        std::vector<Node*> clusters;


        int high(int x) 
        {
            int div = ceil(sqrt(universe_size));
            return x / div;
        }

        int low(int x)
        {
            int mod = ceil(sqrt(universe_size));
            return x % mod;
        }

        int generate_index(int x, int y)
        {
            int ru = ceil(sqrt(universe_size));
            return x * ru + y;
        }

        Node(int size)
        {
            this->universe_size = size;
            this->minimum = -1;
            this->maximum = -1;

            if (size <= 2) {
                this->summary = NULL;
                this->clusters = std::vector<Node*>(0, NULL);
            } else {
                int numberOfClusters = ceil(sqrt(size));

                this->summary = new Node(numberOfClusters);
                this->clusters = std::vector<Node*>(numberOfClusters, NULL);

                for (int i = 0; i < numberOfClusters; i++) {
                    this->clusters[i] = new Node(ceil(sqrt(size)));
                }
            }
        }
};