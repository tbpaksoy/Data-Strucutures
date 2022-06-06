#include <iostream>
#include <vector>
#include <queue>
#include "Node.cpp"
using namespace std;
void BFS(GraphNode node)
{
    vector<GraphNode> checkTable;
    queue<GraphNode> q;
    checkTable.push_back(node);
    q.push(node);
    cout << endl
         << node.symbol;
    for (GraphNode temp : node.linked)
    {
        q.push(temp);
    }
    while (!q.empty())
    {
        node = q.front();
        bool exists = false;
        for (GraphNode temp : checkTable)
        {
            if (temp.symbol == node.symbol)
            {
                exists = true;
                break;
            }
        }
        if (!exists)
        {
            cout << endl
                 << node.symbol;
            for (GraphNode temp : node.linked)
            {
                q.push(temp);
            }
        }
        q.pop();
        checkTable.push_back(node);
    }
}
int main()
{
    GraphNode a = GraphNode('a');
    GraphNode b = GraphNode('b');
    GraphNode c = GraphNode('c');
    GraphNode d = GraphNode('d');
    GraphNode e = GraphNode('e');
    GraphNode f = GraphNode('f');
    GraphNode h = GraphNode('h');
    GraphNode j = GraphNode('j');
    b.Link(f);
    h.Link(j);
    h.Link(d);
    e.Link(c);
    d.Link(c);
    a.Link(b);
    a.Link(c);
    BFS(a);

    return 0;
}