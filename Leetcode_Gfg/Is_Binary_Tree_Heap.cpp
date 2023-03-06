//Is Binary Tree Heap

#include<bits/stdc++.h>
using namespace std;

/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/


                                //Solution

//My approach :
/*
bool isHeap(struct Node* tree)
    {
        queue<struct Node*> q;
        q.push(tree);
        bool flg=false;
        while(!q.empty())
        {
            struct Node* root=q.front();
            q.pop();

            if(root->left && flg==false)
            {
                if(root->data<root->left->data)
                    return false;
                q.push(root->left);
            }
            else if(root->left && flg==true)
            { return false;}
            else if(root->left==NULL && flg==false)
            {flg=true;}

            if(root->right && flg==false)
            {
                if(root->data<root->right->data)
                    return false;
                q.push(root->right);
            }
            else if(root->right && flg==true)
            { return false;}
            else if(root->right==NULL && flg==false)
            {flg=true;}

        }
        return true;
    }
*/


//Babbar Approach :
