#include "Node.h"

class VanEmdeTree
{
    private:
        Node* root;

        int minimum(Node* root);
        int maximum(Node* root);
        void insert(Node* root, int key);
        bool isMember(Node* root, int key);
        int successor(Node* root, int key);
        int predecessor(Node* root, int key);
        void delete_key(Node* root, int key);

    public:
        VanEmdeTree(int size) 
        {
            this->root = new Node(ceil(sqrt(size)));
        }

        int minimum() {
            return this->minimum(this->root);
        }

        int maximum() {
            return this->maximum(this->root);
        }

        void insert(int key) {
            this->insert(this->root, key);
        }

        bool isMember(int key) {
            return this->isMember(this->root, key);
        }

        int successor(int key) {
            return this->successor(this->root, key);
        }

        int predecessor(int key) {
            return this->predecessor(this->root, key);
        }

        void delete_key(int key) {
            return this->delete_key(this->root, key);
        }

};

int VanEmdeTree::maximum(Node* root)
{
    return (root->maximum == -1 ? -1 : root->maximum);
}

int VanEmdeTree::minimum(Node* root)
{
    return (root->minimum == -1 ? -1 : root->minimum);
}

void VanEmdeTree::insert(Node* root, int key)
{
    if (root->minimum == -1) {
        // No key present so no need to insert recursively
        root->minimum = key;
        root->maximum = key;
    } else {
        if (key < root->minimum) {
            std::swap(root->minimum, key);
        }

        if (root->universe_size > 2) {
            if (this->minimum(root->clusters[root->high(key)]) == -1) {
                this->insert(root->summary, root->high(key));

                root->clusters[root->high(key)]->minimum = root->low(key);
                root->clusters[root->high(key)]->maximum = root->low(key);
            } else {
                this->insert(root->clusters[root->high(key)], root->low(key));
            }
        } 
    }

    if (key > root->maximum) {
        root->maximum = key;
    }
}

bool VanEmdeTree::isMember(Node* root, int key) {
    if (root->universe_size < key) {
        return false;
    }

    if (root->minimum == key || root->maximum == key) {
        return true;
    } else {
        if (root->universe_size == 2) {
            return false;
        } else {
            return this->isMember(root->clusters[root->high(key)], root->low(key));
        }
    }
}

int VanEmdeTree::successor(Node* root, int key)
{
    if (root->universe_size == 2) {
        if (key == 0 && root->maximum == 1) {
            return 1;
        } else {
            return -1;
        }
    } else if (root->minimum != -1 && key < root->minimum) {
        return root->minimum;
    } else {
        int maxInCluster = this->maximum(root->clusters[root->high(key)]);

        int offset{ 0 }, successorCluster{ 0 };

        if (maxInCluster != -1 && root->low(key) < maxInCluster) {
            offset = this->successor(root->clusters[root->high(key)], root->low(key));
            return root->generate_index(root->high(key), offset);
        } else {
            successorCluster = this->successor(root->summary, root->high(key));

            if (successorCluster == -1) {
                return -1;
            } else {
                offset = this->minimum(root->clusters[successorCluster]);
                return root->generate_index(successorCluster, offset);
            }
        }
    }

}

int VanEmdeTree::predecessor(Node* root, int key)
{
    if (root->universe_size == 2) {
        if (key == 1 && root->minimum == 0) {
            return 0;
        } else {
            return -1;
        }
    } else if (root->minimum != -1 && key > root->maximum) {
        return root->maximum;
    } else {
        int minCluster = this->minimum(root->clusters[root->high(key)]);
        int offset{ 0 }, predecessorCluster{ 0 };

        if (minCluster != -1 && root->low(key) > minCluster) {
            offset = this->predecessor(root->clusters[root->high(key)], root->low(key));
            return root->generate_index(root->high(key), offset);
        } else {
            predecessorCluster = this->predecessor(root->summary, root->high(key));

            if (predecessorCluster == -1) {
                if (root->minimum != -1 && key > root->minimum) {
                    return root->minimum;
                } else {
                    return -1;
                }
            } else {
                offset = this->maximum(root->clusters[predecessorCluster]);
                return root->generate_index(predecessorCluster, offset);
            }
        }
    }
}

void VanEmdeTree::delete_key(Node* root, int key)
{
    if (root->maximum == root->minimum) {
        root->maximum = -1;
        root->minimum = -1;
    } else if (root->universe_size == 2) {
        if (key == 0) {
            root->minimum = 1;
        } else {
            root->minimum = 0;
        }
        root->maximum = root->minimum;
    } else {
        if (key == root->minimum) {
            int firstCluster = this->minimum(root->summary);
            key = root->generate_index(firstCluster, this->minimum(root->clusters[firstCluster]));
            root->minimum = key;
        }

        this->delete_key(root->clusters[root->high(key)], root->low(key));

        if (this->minimum(root->clusters[root->high(key)]) == -1) {
            this->delete_key(root->summary, root->high(key));

            if (key == root->maximum) {
                int maxSummary = this->maximum(root->summary);

                if (maxSummary == -1) {
                    root->maximum = root->minimum;
                } else {
                    root->maximum = root->generate_index(maxSummary, this->maximum(root->clusters[maxSummary]));
                }
            }
        } else if (key == root->maximum) {
            root->maximum = root->generate_index(root->high(key), this->maximum(root->clusters[root->high(key)]));
        }
    }
}