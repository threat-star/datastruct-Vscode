#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include<iostream>
#include<vector>
#include<assert.h>
#include<stack>

using namespace std;

class treeNode
{
public:
    int m_val;    
    treeNode *left;
    treeNode *right;
    treeNode( int val = 0 ) : m_val( val ), left( nullptr ), right( nullptr )
    {

    }
};

class BinaryTree
{
private:
    treeNode* m_root;
    treeNode* getNext( treeNode* root );
    //treeNode* findSlot( int val );
public:
    BinaryTree( treeNode* root = nullptr ) : m_root( root )
    {

    }

    BinaryTree( const vector<int> vec );

    void addNode( int val );
    bool removeNode( int val );
    vector<int> preOrder();
    vector<int> inOrder();
    vector<int> afterOrder();
};

// treeNode* BinaryTree::findSlot( int val )
// {
//     treeNode *tmp = m_root; 
//     while( 1 )
//     {
//         if( tmp == nullptr )
//         {
//             return tmp;
//         }

//         if( val > tmp -> m_val )
//         {
//             tmp = tmp -> right;
//         }
//         else
//         {
//             tmp = tmp -> left;
//         }
//     }
// }

BinaryTree::BinaryTree( const vector<int> vec )
{
    int n = vec.size();
    if( n == 0 )
    {
        return;
    }

    m_root == new treeNode( vec[0] );
    for( int i = 0; i < n; ++i )
    {
        addNode( vec[i] );
    }
}

void BinaryTree::addNode( int val )
{
    if( m_root == nullptr )
    {
        m_root = new  treeNode( val );
        return;
    }

    treeNode *tmp = m_root;
    while( tmp )
    {
        if( val > tmp->m_val )
        {
            if( tmp->right == nullptr )
            {
                treeNode* cur = new treeNode( val );
                tmp -> right = cur;
                break;
            }
            
            tmp = tmp->right;
        }
        else if( val < tmp->m_val )
        {
            if( tmp->left == nullptr )
            {
                treeNode* cur = new treeNode( val );
                tmp -> left = cur;
            }

            tmp = tmp->left;
        }
        else
        {
            cerr << "val existing!";
            break;
        }
    }

}

treeNode* getNext( treeNode* root )
{
    while( root->left )
    {
        root = root->left;
    }

    return root;
}

    // TreeNode* deleteNode(TreeNode* root, int key) 
    // {
    //     if (root == nullptr)    return nullptr;
    //     if (key > root->val)    root->right = deleteNode(root->right, key);     // ??????????????????
    //     else if (key < root->val)    root->left = deleteNode(root->left, key);  // ??????????????????
    //     else    // ????????????????????????????????????
    //     {
    //         if (! root->left)   return root->right; // ??????1???????????????????????????
    //         if (! root->right)  return root->left;  // ??????2???????????????????????????
    //         TreeNode* node = root->right;           // ??????3????????????????????????????????? 
    //         while (node->left)          // ?????????????????????????????????????????????
    //             node = node->left;
    //         node->left = root->left;    // ???????????????????????????????????????????????????????????????????????????
    //         root = root->right;         // ?????????????????????????????????????????????????????????
    //     }
    //     return root;    
    // }

bool BinaryTree::removeNode( int val )
{
    //??????1??? ??????????????????????????????????????????
    //??????2??? ?????????????????????????????????????????????????????????
    //??????3:  ???????????????children????????????????????????????????????????????????
    if (m_root == nullptr) return false;
    
}

vector<int> BinaryTree::preOrder()
{
    //??????
    stack<treeNode*> stk;
    stk.push(m_root);
    while (!stk.empty()) {
        auto& top = stk.top();
        cout << top->m_val << " ";
        stk.pop();
        if (top->right) {
            stk.push(top->right);
        }

        if (top->left) {
            stk.push(top->left);
        }
    }
}

vector<int> BinaryTree::inOrder()
{
     //??????
    stack<treeNode*> stk;
    auto root = m_root;
    while (!stk.empty() || root != nullptr) {
       
        if (root != nullptr) {
            stk.push(root);  
            root = root->left;
        } else {
            root = stk.top();
            cout << root->m_val << " ";
            stk.pop();
            root = root->right;
        }
    }
}

vector<int> BinaryTree::afterOrder()
{
    //h????????????????????????????????????c??????????????????
    if (m_root != nullptr) {
        stack<treeNode*> stk;
        stk.push(m_root);
        treeNode* h = m_root;

        while (!stk.empty()) {
            auto c = stk.top();

            //?????????????????????, ?????????
            if (c->left != nullptr && h != c->left && h != c->right) { 
                stk.push(c->left);
            } else if (c->right != nullptr && h != c->right) {   //?????????????????????
                stk.push(c->right);
            } else {
                //auto top = stk.top();
                cout << c->m_val << " ";
                stk.pop();
                
                h = c;
            }
        }
    }

}

// //????????????????????????????????????;
// treeNode* re_build_tree(vector<int> vec) {
//     int n = vec.size();
//     if (n == 0) {
        
//     }
// }


#endif



