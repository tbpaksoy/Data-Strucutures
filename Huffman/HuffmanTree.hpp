#ifndef HNode
#define HNode
#include "HuffmanNode.hpp"
#endif
#ifndef STDLIB
#define STDLIB
#include <stdlib.h>
#endif
#ifndef VECTOR
#define VECTOR
#include <vector>
#endif
namespace Tahsin
{
    template <typename T>
    class HuffmannTree
    {
    private:
        HuffmanNode<T> *root;

    public:
        HuffmannTree(HuffmanNode<T> *root);
        HuffmannTree(std::vector<T> elements);
        ~HuffmannTree();
        T GetValue(size_t path);
    };
}