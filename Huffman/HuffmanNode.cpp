#include "HuffmanNode.hpp"
namespace Tahsin
{
    template <typename T>
    HuffmanNode<T>::HuffmanNode(T value) : n(value)
    {
        this->value = value;
    }
    template <typename T>
    HuffmanNode<T>::~HuffmanNode() {}
    template <typename T>
    HuffmanNode<T> HuffmanNode<T>::GetLeft()
    {
        return left;
    }
    template <typename T>
    HuffmanNode<T> HuffmanNode<T>::GetRight()
    {
        return right;
    }
    template <typename T>
    bool HuffmanNode<T>::IsLeaf()
    {
        return right == nullptr && left == nullptr;
    }
    template <typename T>
    int HuffmanNode<T>::Total()
    {
        return total;
    }
    template <typename T>
    HuffmanNode<T> *HuffmanNode<T>::Unite(HuffmanNode<T> *node)
    {
        HuffmanNode<T> *result;
        result->total = total + node->total;
        if (total < node->total)
        {
            result->left = this;
            result->right = node;
        }
        else
        {
            result->left = node;
            result->right = this;
        }
        return result;
    }
    template <typename T>
    bool HuffmanNode<T>::HasData()
    {
        return value == default || value == nullptr;
    }
    template <typename T>
    T HuffmanNode<T>::GetValue()
    {
        return this->value;
    }
}