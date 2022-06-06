#include <iostream>
using namespace std;
class BNode
{
private:
    int degree;

public:
    int keys[1] = {};
    BNode *children[1] = {};
    int GetLength()
    {
        int length = 0;
        for (int i : keys)
        {
            if (i != -1)
            {
                length++;
            }
        }
        return length;
    }
    bool IsLeaf()
    {
        for (BNode *node : children)
        {
            if (node != nullptr)
                return false;
        }
        return true;
    }
    BNode *Search(int value)
    {
        int a = 0;
        while (a < GetLength() && value > keys[a])
        {
            a++;
        }
        if (keys[a] == value)
            return this;
        if (IsLeaf())
            return nullptr;
        return children[a]->Search(value);
    }
    void Traverse()
    {
        int index;
        for (index = 0; index < GetLength(); index++)
        {
            if (!IsLeaf())
            {
                children[index]->Traverse();
                cout << endl
                     << keys[index];
            }
        }
        if (!IsLeaf())
            children[index]->Traverse();
    }
    BNode(int degree)
    {
        this->degree = degree;
        children[degree - 1];
        keys[2 * degree - 1];
        for (int i = 0; i < 2 * degree - 1; i++)
        {
            keys[i] = -1;
        }
    }
    ~BNode() {}
    friend class BTree;
};
class BTree
{
private:
    BNode *root = nullptr;
    int degree;

public:
    BTree(BNode *root)
    {
        degree = root->degree;
        this->root = root;
    }
    ~BTree() {}
    void Traverse()
    {
        if (root)
        {
            root->Traverse();
        }
    }
    BNode *Search(int value)
    {
        return root == nullptr ? nullptr : root->Search(value);
    }
};
