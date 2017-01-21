/**
 * A node of a binary tree.
 *
 * Comparable must be a type that supports comparisons
 * using the relational operators.
 */
#ifndef BINARY_NODE_H
#define BINARY_NODE_H

using namespace std;

template <class Comparable>
class BinaryNode
{
public:
    BinaryNode(Comparable data);
    BinaryNode(const Comparable& data, BinaryNode *left, BinaryNode *right);
    virtual ~BinaryNode();

    Comparable data;
    int        height;  // node height

    BinaryNode *left;
    BinaryNode *right;
};

/**
 * Constructor.
 * @param data the data item.
 */
template <class Comparable>
BinaryNode<Comparable>::BinaryNode(Comparable data)
    : data(data), height(0), left(nullptr), right(nullptr)
{
}

/**
 * Constructor.
 * @param data the data item.
 * @param left the left link.
 * @param right the right link.
 */
template <class Comparable>
BinaryNode<Comparable>::BinaryNode(const Comparable& data,
                                   BinaryNode *left, BinaryNode *right)
  : data(data), height(0), left(left), right(right)
{
}

/**
 * Destructor.
 */
template <class Comparable>
BinaryNode<Comparable>::~BinaryNode()
{
}

#endif // BINARY_NODE_H