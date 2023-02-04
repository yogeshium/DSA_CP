//Bottom View of Binary Tree

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
    cout<<"\nEnter root = ";
    int d; cin>>d;
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

//Babbar :
/*
vector <int> bottomView(Node *root)
    {
        map<int, Node*> mp;
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));

        int m1=INT_MAX,m2=INT_MIN;

        while(!q.empty())
        {
            pair<Node*,int> t=q.front();
            q.pop();

            if(t.second<m1)
                m1=t.second;
            if(t.second>m2)
                m2= t.second;

            mp[t.second]=t.first;

            if(t.first->left)
                q.push(make_pair(t.first->left,t.second-1));
            if(t.first->right)
                q.push(make_pair(t.first->right,t.second+1));

        }
        vector<int> res;
        for(int i=m1;i<=m2;i++)
        {
            res.push_back(mp[i]->data);
        }
        return res;
    }
*/







int main()
{
    Node* root = NULL;
    root =buildFromLevelOrderTraversal(root);
    //BFS(root);


    return 0;
}
