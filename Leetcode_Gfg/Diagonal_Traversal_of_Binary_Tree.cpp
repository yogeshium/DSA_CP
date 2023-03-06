//Diagonal Traversal of Binary Tree
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

//Build Tree from Level Order Traversal
Node* buildFromLevelOrderTraversal(Node* root)
{
    queue<Node*> q;
    cout<<"\nEnter root = ";int d; cin>>d;
    root = new Node(d);q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();q.pop();
        cout<<"\nEnter left for "<<temp->data<<" : ";
        int ld;cin>>ld;
        if(ld!=-1)
        {
            temp->left = new Node(ld);
            q.push(temp->left);
        }

        cout<<"\nEnter right for "<<temp->data<<" : ";
        int rd;cin>>rd;
        if(rd!=-1)
        {
            temp->right = new Node(rd);
            q.push(temp->right);
        }
    }
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



                    //Solution

//GFG :

void traverse(Node* root, map<int,vector<int>>& mp, int d)
{
    if(root==NULL)
        return;

    mp[d].push_back(root->data);

    traverse(root->left,mp,d+1);
    traverse(root->right,mp,d);
}

vector<int> diagonal(Node *root)
{
    map<int,vector<int>> mp;

    traverse(root,mp,0);

    vector<int> res;
    for(auto it:mp)
    {
        vector<int> v = it.second;
        for(auto i:v)
        {
            res.push_back(i);
        }
    }
    return res;
}



//7 1 10 -1 2 9 11 -1 4 8 -1 -1 12 -1 -1 -1 -1 -1 -1
//25 20 35 15 22 30 45 -1 -1 -1 -1 -1 32 -1 -1 -1 -1
    int main()
    {
        Node* root = NULL;
        root=buildFromLevelOrderTraversal(root);
        BFS(root);

        int res=0;
        count(root,0,3,res,1000000009);
        cout<<"\n Result : "<<res;
        return 0;
    }
