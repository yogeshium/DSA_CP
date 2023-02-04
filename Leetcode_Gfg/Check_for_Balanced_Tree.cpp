//Check for Balanced Tree

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left, *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root)
{
    cout<<"\nEnter the data (-1 for NULL) : ";
    int d;cin>>d;
    root = new Node(d);

    if(d==-1) return NULL;
    cout<<"\nInsert in Left : ";
    root->left = buildTree(root->left);
    cout<<"\nInsert in Right : ";
    root->right = buildTree(root->right);

    return root;
}


//Level Order Traversal
void BFS(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);

    }
}



//Approach 1 :
/*
    int height(Node* root)
    {
        if(root==NULL)
            return 0;
        return max(height(root->left), height(root->right))+1;
    }

    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(root==NULL)
            return true;

        bool c1 = isBalanced(root->left);
        bool c2 = isBalanced(root->right);

        bool c3= abs(height(root->left)-height(root->right)) <=1;

        return c1&c2&c3;
    }
*/



//Approach 2 :
/*
pair<bool,int> B(Node* root)
    {
        if(root==NULL)
        {
            pair<bool,int> r(true,0);
            return r;
        }

        pair<bool,int> left = B(root->left);
        pair<bool,int> right = B(root->right);

        bool c1= left.first;
        bool c2= right.first;
        bool c3= abs(left.second-right.second)<=1;

        pair<bool,int> ans;
        ans.first = c1&c2&c3;
        ans.second = max(left.second,right.second)+1;
        return ans;
    }

    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
       return B(root).first;
    }
*/





int main()
{

}
