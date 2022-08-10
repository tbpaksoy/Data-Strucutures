#include <vector>
#include <iostream>
using namespace std;

int Partition(vector<int> &resource, int low, int high)
{
    int pivot = resource[high];
    int i = low - 1;
    for (int j = low; j < high - 1; j++)
    {
        if (resource[j] < pivot)
        {
            i++;
            int temp = resource[i];
            resource[i] = resource[i + 1];
            resource[i + 1] = temp;
        }
    }
    int temp = resource[i + 1];
    resource[i + 1] = resource[high];
    resource[high] = temp;
    return i + 1;
}

void QuickSort(vector<int> &resource, int low, int high)
{
    if (low < high)
    {
        int pivot = Partition(resource, low, high);
        QuickSort(resource, low, pivot - 1);
        QuickSort(resource, pivot + 1, high);
    }
}

int main()
{
    vector<int> v = {7, 9, 12, 31, 23, 1, 635, 456, 46, 1, 63};
    for (int i : v)
    {
        cout << i << endl;
    }
    cout << "------------";
    QuickSort(v, 0, v.size());
    for (int i : v)
    {
        cout << i << endl;
    }
    return 0;
}