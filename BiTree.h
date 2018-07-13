#pragma once

namespace DataStructure
{
    struct BiTreeNode
    {
        int value;
        BiTreeNode* left;
        BiTreeNode* right;

        BiTreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
    };

    class BiTree
    {
    public:
        BiTree();
        ~BiTree();

        BiTreeNode* CreateByOrder(int* values, int size);
        void PreOrderTraverse(BiTreeNode* root);

        static void TestPreOrderTraverse();
    };
}

