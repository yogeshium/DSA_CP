//Vertical Traversal of Binary Tree


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
//Level Order Traversal showing level wise
void BFS_show_level_wise(Node* root)
{
    queue<Node*> q;
    q.push(root);q.push(NULL);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<"\n";
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);

        }
    }
}



                                        //Solution

//My Approach:

vector<int> verticalOrder(Node *root)
    {
        map<int,vector<int>> mp;
        queue<pair<Node*,int>> q;

        int m1=INT_MAX,m2=INT_MIN;
        q.push(make_pair(root,0));
        while(!q.empty())
        {
            pair<Node*,int> temp = q.front();
            q.pop();

            if(temp.second>m2)
                m2 = temp.second;
            if(temp.second<m1)
                m1=temp.second;
            mp[temp.second].push_back(temp.first->data);

            if(temp.first->left)
            {
                pair<Node*,int> p(temp.first->left,temp.second-1);
                q.push(p);
            }
            if(temp.first->right)
            {
                pair<Node*,int> p(temp.first->right,temp.second+1);
                q.push(p);
            }
        }
        vector<int>res;

        for(int i=m1;i<=m2;i++)
        {
            for(int j=0;j<mp[i].size();j++)
            {
                res.push_back(mp[i][j]);
            }
        }
        return res;
    }

int main()
{

    return 0;
}
