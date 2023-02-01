#include "HuffmanTree.hpp"
#ifndef VECTOR
#define VECTOR
#include <vector>
#endif
#ifndef MAP
#define MAP
#include <map>
#endif
namespace Tahsin
{
    template <typename T>
    HuffmannTree<T>::HuffmannTree(HuffmanNode<T> *root)
    {
        this->root = root;
    }
    template <typename T>
    HuffmannTree<T>::HuffmannTree(std::vector<T> elements)
    {
        std::map<T, int> quantity;
        for (T t : elements)
        {
            if (quantity.count(t))
                quantit[t]++;
            else
                quantity.insert(std::pair<T, int>(t, 1));
        }
    }
    template <typename T>
    HuffmannTree<T>::~HuffmannTree() {}
    template <typename T>
    T HuffmannTree<T>::GetValue(size_t path)
    {
        if (root == nullptr)
            return default;
        else
        {
            std::vector<bool> temp;
            while (path > 0)
            {
                temp.push_back(path % 2 == 0);
                path /= 2;
            }
            HuffmanNode<T> *current = root;
            for (bool b : temp)
            {
                try
                {
                    if (b)
                    {
                        current = current->right;
                    }
                    else
                    {
                        current = current->left;
                    }
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << 'not found';
                }
            }
            return current->GetValue();
        }
    }
}