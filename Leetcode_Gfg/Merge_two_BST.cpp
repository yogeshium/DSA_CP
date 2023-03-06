//Merge two BST

#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


                        //Solution
//Using extra space O(m+n)
/*
void inorder_BST(Node* root, vector<int>& A)
    {
        if(root==NULL)
            return;
        inorder_BST(root->left, A);
        A.push_back(root->data);
        inorder_BST(root->right,A);
    }

    vector<int> merge(Node *root1, Node *root2)
    {
       vector<int> r1;
       inorder_BST(root1, r1);
       vector<int> r2;
       inorder_BST(root2,r2);

        vector<int> res;
        int i=0,j=0;
        while(i<r1.size() && j<r2.size())
        {
            if(r1[i]<r2[j])
            {
                res.push_back(r1[i]);i++;
            }
            else if(r1[i]>r2[j])
            {
                res.push_back(r2[j]);j++;
            }
            else
            {
                res.push_back(r1[i]);
                res.push_back(r2[j]);
                i++;j++;
            }
        }
        while(i<r1.size())
        {    res.push_back(r1[i]);i++;}

        while(j<r2.size())
        {    res.push_back(r2[j]);j++;}

        return res;
    }
*/




//Approach 2:
/*
    Optimized space complexity - O(h1 + h2)

*/
/*
    //1. convert BST to sorted DLL ( whithout using extra space)

    void BST_to_Sorted_DLL(Node* root, Node*& head)
    {
        if(root==NULL)
            return ;
        BST_to_Sorted_DLL(root->right, head);
        root->right = head;
        if(head!=NULL)
            head->left = root;
        head = root;

        BST_to_Sorted_DLL(root->left,head);
    }

    //2.

    //3.
*/


