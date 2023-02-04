//Sum Tree

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



//Approach :
/*
pair<bool,int> Solve(Node* root)
    {
        if(root==NULL)
        {
            pair<bool,int> r(true,0);
            return r;
        }
        if(root->left == NULL && root->right==NULL)
        {
            pair<bool,int> r(true,root->data);
            return r;
        }

        pair<bool,int> left = Solve(root->left);
        pair<bool,int> right = Solve(root->right);


        bool c1 = left.first && right.first;
        bool c2 = root->data == (left.second+right.second);

        pair<bool,int> ans;

        ans.first = c1&&c2;
        ans.second = root->data + left.second + right.second;

        return ans;
    }

    bool isSumTree(Node* root)
    {
         return Solve(root).first;
    }
*/





int main()
{

}
