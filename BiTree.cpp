#include "stdafx.h"
#include "BiTree.h"
#include <stack>
#include <iostream>
#include <assert.h>
#include <stack>

using namespace std;
using namespace DataStructure;


BiTree::BiTree()
{
}


BiTree::~BiTree()
{
}

BiTreeNode* BiTree::CreateByOrder(int* values, int size)
{
    BiTreeNode* root = new BiTreeNode(values[0]);

    for (int i = 1; i < size; i++)
    {
        BiTreeNode* p = root;
        BiTreeNode* n = new BiTreeNode(values[i]);

        while (true)
        {
            if (n->value < p->value)
            {
                if (p->left)
                {
                    p = p->left;
                }
                else
                {
                    p->left = n;
                    break;
                }
            }
            else
            {
                if (p->right)
                {
                    p = p->right;
                }
                else
                {
                    p->right = n;
                    break;

                }
            }
        }
    }

    return root;
}

BiTreeNode * BiTree::CreateByPreAndInOrder(int * preOrder, int * inOrder, int size)
{
    assert(preOrder != nullptr);
    assert(inOrder != nullptr);
    assert(size > 0);

    BiTreeNode* p = nullptr;

    p = CreateByPreAndInOrder(preOrder, 0, inOrder, 0, size - 1);

    return p;
}

void BiTree::PreOrderTraverse(BiTreeNode* root)
{
    assert(root != nullptr);

    stack<BiTreeNode*> s;
    BiTreeNode* p = root;

    cout << "Pre-Order: ";

    while (p || !s.empty())
    {
        if (p)
        {
            cout << p->value << " ";
            s.push(p);
            p = p->left;
        }
        else
        {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }

    cout << endl;
}

void BiTree::InOrderTraverse(BiTreeNode* root)
{
    assert(root != nullptr);

    stack<BiTreeNode*> s;
    BiTreeNode* p = root;

    cout << "In-Order: ";

    while (p || !s.empty())
    {
        if (p)
        {
            s.push(p);
            p = p->left;
        }
        else
        {
            p = s.top();
            s.pop();
            cout << p->value << " ";
            p = p->right;
        }
    }

    cout << endl;
}

void BiTree::PostOrderTraverse(BiTreeNode * root)
{
    assert(root != nullptr);

    stack<BiTreeNode*> s;
    stack<BiTreeNode*> o;
    BiTreeNode* p = root;

    cout << "Post-Order: ";

    while (p || !s.empty())
    {
        if (p)
        {
            s.push(p);
            o.push(p);
            p = p->right;
        }
        else
        {
            p = s.top();
            s.pop();
            p = p->left;
        }
    }

    while (!o.empty())
    {
        cout << o.top()->value << " ";
        o.pop();
    }

    cout << endl;
}

void BiTree::TestPreOrderTraverse()
{
    BiTree* bt = new BiTree();
    int values[] = { 5, 3, 1, 7, 6, 8};
    BiTreeNode* root = bt->CreateByOrder(values, sizeof(values) / sizeof(int));
    bt->PreOrderTraverse(root);
    bt->InOrderTraverse(root);
    bt->PostOrderTraverse(root);
}

void BiTree::TestBiTree()
{
    BiTree* bt = new BiTree();
    int preOrder[] = { 5, 3, 1, 2, 9, 8, 7 };
    int inOrder[] = { 1, 3, 2, 5, 8, 9, 7 };

    BiTreeNode* root = bt->CreateByPreAndInOrder(preOrder, inOrder, sizeof(preOrder) / sizeof(int));

    bt->PreOrderTraverse(root);
    bt->InOrderTraverse(root);
    bt->PostOrderTraverse(root);
}

BiTreeNode* BiTree::CreateByPreAndInOrder(int* preOrder, int preOrderIndex, int* inOrder, int inOrderLeftIndex, int inOrderRightIndex)
{
    int rootVal = preOrder[preOrderIndex];
    int inOrderIndex = -1;
    BiTreeNode* rootNode = new BiTreeNode(rootVal);

    if (inOrderLeftIndex == inOrderRightIndex)
    {
        return rootNode;
    }

    for (int i = inOrderLeftIndex; i < inOrderRightIndex; i++)
    {
        if (inOrder[i] == rootVal)
        {
            inOrderIndex = i;
        }
    }

    if (inOrderIndex == -1)
    {
        return nullptr;
    }

    rootNode->left = CreateByPreAndInOrder(preOrder, preOrderIndex + 1, inOrder, inOrderLeftIndex, inOrderIndex - 1);
    rootNode->right = CreateByPreAndInOrder(preOrder, preOrderIndex + inOrderIndex - inOrderLeftIndex + 1, inOrder, inOrderIndex + 1, inOrderRightIndex);

    return rootNode;
    

}