#include "Node.cpp"
#include <iostream>
using namespace std;
class Stack
{
private:
    OneWayNode *first = nullptr;

public:
    void Push(OneWayNode *node)
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
        if (first && first->next)
        {
            OneWayNode *before = nullptr;
            OneWayNode *active = first;
            while (active->next)
            {
                before = active;
                active = active->next;
            }
            if(before) before->next = nullptr;
            return active;
        }
        else if(first)
        {
            OneWayNode *result = first;
            first = nullptr;
            return result;
        }
        else
        {
            return nullptr;
        }
    }
    Stack() {}
    ~Stack() {}
};
int main()
{
    Stack *s = new Stack();
    s->Push(new OneWayNode(1));
    s->Push(new OneWayNode(2));
    s->Push(new OneWayNode(3));
    s->Push(new OneWayNode(4));
    s->Push(new OneWayNode(5));
    cout << "added" << endl;
    cout << s->Pop()->data << endl;
    cout << s->Pop()->data << endl;
    cout << s->Pop()->data << endl;
    cout << s->Pop()->data << endl;
    cout << s->Pop()->data << endl;
    return 0;
}