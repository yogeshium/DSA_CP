//BST to max heap

#include<bits/stdc++.h>
using namespace std;



   void inorder_BST(Node* root, vector<int>& A)
   {
       if(root==NULL)
            return;

        inorder_BST(root->left,A);
        A.push_back(root->data);
        inorder_BST(root->right, A);
   }

   void makeHeap(Node* root, int &i, vector<int>&A)
   {
       if(root==NULL || i>=A.size())
            return;

        makeHeap(root->left,i,A);
        makeHeap(root->right,i,A);

        root->data= A[i];
        i++;
   }

    void convertToMaxHeapUtil(Node* root)
    {
    //Storing data of Binary Search tree in ascending order : inorderTraversal
        vector<int> A;
        inorder_BST(root, A);

    //Make Complete Binary Tree
        //1. Pehle array mai lo sare nodes ko (left , right null kr dena) (level order traverse)
        queue<Node*> q;
        vector<Node*> tree;
        q.push(root);
        while(!q.empty())
        {
            Node* curr= q.front();
            q.pop();

            tree.push_back(curr);

            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);

            curr->left = NULL;
            curr->right = NULL;
        }

        //2. Now ab iss array se Complete Binary tree banao (Level order traverse way)

        root=tree[0];
        q.push(tree[0]);
        int i=1;
        while(!q.empty())
        {
            Node* curr= q.front();
            q.pop();

            if(i<tree.size())
            {
                curr->left = tree[i++];
                q.push(curr->left);
            }
            if(i<tree.size())
            {
                curr->right = tree[i++];
                q.push(curr->right);
            }
        }

    //Making Max Heap - by traversing in (L R N) way and replacing the values

        i=0;
        makeHeap(root,i,A);

    }
