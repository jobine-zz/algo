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
