namespace Tahsin
{
    template <typename T>
    class HuffmanNode
    {
    private:
        T value;
        HuffmanNode<T> *right;
        HuffmanNode<T> *left;
        int total;

    public:
        HuffmanNode(T value);
        ~HuffmanNode();
        bool IsLeaf();
        HuffmanNode<T> GetRight();
        HuffmanNode<T> GetLeft();
        int Total();
        HuffmanNode<T> *Unite(HuffmanNode<T> *node);
        bool HasData();
        T GetValue();
    };
}