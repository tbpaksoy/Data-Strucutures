#include <iostream>
using namespace std;
class BSTNode
{
private:
    int data;
    BSTNode *left = nullptr;
    BSTNode *right = nullptr;
    BSTNode *GetSupposed(BSTNode *node)
    {
        if (node->data < data)
        {
            return left;
        }
        else if (node->data > data)
        {
            return right;
        }
        return nullptr;
    }
    friend class BinarySearchTree;

public:
    BSTNode(int data)
    {
        this->data = data;
    }
    ~BSTNode() {}
    static void Explore(BSTNode *node)
    {
        if (node)
        {
            Explore(node->right);
            cout << node->data << endl;
            Explore(node->left);
        }
    }
};

class BinarySearchTree
{
private:
    BSTNode *root = nullptr;

public:
    BinarySearchTree() {}
    ~BinarySearchTree() {}
    void AddNode(BSTNode *node)
    {
        if (node)
        {
            if (!root)
            {
                root = node;
            }
            else
            {
                BSTNode *active = root;
                while (active->GetSupposed(node))
                {
                    active = active->GetSupposed(node);
                }
                if (active->data > node->data)
                {
                    active->left = node;
                    cout << endl
                         << active->data << "'s left is " << node->data << endl;
                }
                else if (active->data < node->data)
                {
                    active->right = node;
                    cout << endl
                         << active->data << "'s right is " << node->data << endl;
                }
            }
        }
    }
    void Explore()
    {
        cout << endl
             << "Root is" << root->data << endl;
        BSTNode::Explore(root);
    }
};
int main()
{
    BinarySearchTree *tree = new BinarySearchTree();
    tree->AddNode(new BSTNode(3));
    tree->AddNode(new BSTNode(9));
    tree->AddNode(new BSTNode(7));
    tree->AddNode(new BSTNode(2));
    tree->AddNode(new BSTNode(4));
    tree->AddNode(new BSTNode(8));
    tree->AddNode(new BSTNode(1));
    tree->AddNode(new BSTNode(0));
    cout << "Done";
    tree->Explore();
}