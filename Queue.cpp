#include "Node.cpp"
#include <iostream>
using namespace std;
class Queue
{
private:
    OneWayNode *first = nullptr;
public:
    void Enqueue(OneWayNode *node)
    {
        if (node)
        {
            if (!first)
            {
                first = node;
            }
            else
            {
                OneWayNode *active = first;
                while (active->next)
                {
                    active = active->next;
                }
                active->next = node;
            }
        }
    }
    OneWayNode *Pop()
    {
        if (first)
        {
            OneWayNode *result = first;
            first = first->next;
            return result;
        }
        else
            return nullptr;
    }
    Queue() {}
    ~Queue() {}
};
int main()
{
    Queue *q = new Queue();
    q->Enqueue(new OneWayNode(1));
    q->Enqueue(new OneWayNode(2));
    q->Enqueue(new OneWayNode(3));
    q->Enqueue(new OneWayNode(4));
    cout << q->Pop()->data << endl;
    cout << q->Pop()->data << endl;
    cout << q->Pop()->data << endl;
    cout << q->Pop()->data << endl;
    return 0;
}