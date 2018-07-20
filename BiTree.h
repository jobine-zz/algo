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
        BiTreeNode* CreateByPreAndInOrder(int* preOrder, int* inOrder, int size);
        
        void PreOrderTraverse(BiTreeNode* root);
        void InOrderTraverse(BiTreeNode* root);
        void PostOrderTraverse(BiTreeNode* root);

        static void TestPreOrderTraverse();
        static void TestBiTree();
    private:
        BiTreeNode* CreateByPreAndInOrder(int* preOrder, int preOrderIndex, int * inOrder, int inOrderLeftIndex, int inOrderRightIndex);
    };
}

