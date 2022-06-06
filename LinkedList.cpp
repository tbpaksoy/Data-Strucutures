#include "Node.cpp"
#include <iostream>
using namespace std;
class OneWayLinkedList
{
public:
    void AddNode(OneWayNode *node)
    {
        if (node)
        {
            if (start == 0)
                start = node;
            else
            {
                OneWayNode *active = start;
                while (active->next != nullptr)
                {
                    active = active->next;
                }
                active->next = node;
                return;
            }
        }
    }
    void RemoveNode(int index)
    {
        int length = GetLength();
        if (index < length && length != -1)
        {
            OneWayNode *wanted = GetNode(index);
            OneWayNode *before = 0;
            OneWayNode *scan = start;
            if (scan->next != 0)
                while (scan->next != wanted)
                {
                    scan = scan->next;
                }
            before = scan;
            before->next = wanted->next;
        }
    }
    OneWayNode *GetNode(int index)
    {
        int length = GetLength();
        if (index < length && length != -1)
        {
            OneWayNode *active = start;
            while (index > 0)
            {
                active = active->next;
                index--;
            }
            return active;
        }
        else
            return 0;
    }
    OneWayLinkedList() {}
    ~OneWayLinkedList() {}
    OneWayNode *start=nullptr;
    int GetLength()
    {
        int length = 0;
        if (start)
        {
            OneWayNode *active = start;
            length++;
            while (active->next != 0)
            {
                active = active->next;
                length++;
            }
        }
        return length;
    }
};

int main()
{
    OneWayLinkedList *list = new OneWayLinkedList();
    list->AddNode(new OneWayNode(4));
    list->AddNode(new OneWayNode(44));
    list->AddNode(new OneWayNode(25));
    list->AddNode(new OneWayNode(94));
    list->AddNode(new OneWayNode(21));
    list->AddNode(new OneWayNode(46));
    int length = list->GetLength();
    for(int i = 0; i < length ; i++)
    {
        cout << list->GetNode(i)->data << endl;
    }
    cout << endl;
    list->RemoveNode(1);
    list->RemoveNode(3);
    length = list->GetLength();
    for(int i = 0; i < length ; i++)
    {
        cout << list->GetNode(i)->data << endl;
    }
    return 0;
}