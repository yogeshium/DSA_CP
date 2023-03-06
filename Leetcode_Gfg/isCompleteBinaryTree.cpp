//isCompleteBinaryTree

#include<bits/stdc++.h>
using namespace std;


bool isCBT(Node* root)
    {
        queue<Node*> q;
        bool flag= false;
        q.push(root);
        while(!q.empty())
        {
            Node* curr= q.front();
            q.pop();

            //left
            if(curr->left && flag==false)
                q.push(curr->left);
            else if(curr->left && flag==true)
                return false;
            else if(curr->left==NULL && flag==false)
                flag = true;

            //right
            if(curr->right && flag==false)
                q.push(curr->right);
            else if(curr->right && flag==true)
                return false;
            else if(curr->right==NULL && flag==false)
                flag = true;
        }
        return true;
    }
