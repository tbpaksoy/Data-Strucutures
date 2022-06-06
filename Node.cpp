#include <vector>
using namespace std;
class OneWayNode
{
public:
    OneWayNode(int data)
    {
        this->data = data;
    }
    ~OneWayNode() {}
    int data;
    OneWayNode *next = 0;
};
class TwoWayNode
{
public:
    TwoWayNode(int data)
    {
        this->data = data;
    }
    TwoWayNode() {}
    int data;
    TwoWayNode *next = 0;
    TwoWayNode *back = 0;
};
struct GraphNode
{
public:
    char symbol;
    vector<GraphNode> linked;
    GraphNode(char symbol)
    {
        (*this).symbol = symbol;
    }
    ~GraphNode() {}
    void Link(GraphNode &node)
    {
        node.linked.push_back(*this);
        linked.push_back(node);
    }
};
