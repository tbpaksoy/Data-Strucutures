enum TreeColor
{
    Red,
    Black
};
class RedBlackNode
{
public:
    TreeColor color;
    RedBlackNode() {}
    RedBlackNode(RedBlackNode *parent)
    {
        this->color = color;
        this->parent = parent;
    }
    ~RedBlackNode() {}
    RedBlackNode *Left()
    {
        return children[0];
    }
    RedBlackNode *Right()
    {
        return children[1];
    }
    bool IsLeaf()
    {
        return children[0] == nullptr && children[1] == nullptr;
    }
    bool IsRoot()
    {
        return parent == nullptr;
    }

private:
    RedBlackNode *parent;
    RedBlackNode *children[2];
};
class RedBlackTree
{
private:
    RedBlackNode *root;
};
