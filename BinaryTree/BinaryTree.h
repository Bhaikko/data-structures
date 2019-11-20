#include "Node.h"

class BinaryTree
{
    private:
        Node* root;
        

    private:
        Node* treeInput(Node* root);
        void treePreorderTraversal(Node* root);

    public:
        BinaryTree();
        void input();
        void preOrder();
        void levelWise();

        friend std::ostream& operator << (std::ostream& os, BinaryTree* tree) {
            tree->preOrder();

            return os;
        }
};

