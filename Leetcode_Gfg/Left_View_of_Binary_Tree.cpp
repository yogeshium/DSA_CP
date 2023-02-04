//Left View of Binary Tree

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

//Babbar ke concept pe my approach: (got tle)
/*
//(level wise traversal)
vector<int> leftView(Node *root)
{
    int level=0;
    map<int,Node*> mp;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp==NULL)
        {
            if(!q.empty())
            {
                level++;
                q.push(NULL);
            }
        }
        else
        {
            if(mp.find(level)==mp.end())
                mp[level]=temp;

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    vector<int> res;

    for(int i=0;i<=level;i++)
    {
        res.push_back(mp[i]->data);
    }

    return res;
}
*/

//Babbar Approch :
/*
void traverse(Node* root,map<int,Node*>& mp,int level)
{
    if(root==NULL)
        return;

    if(mp.find(level)==mp.end())
        mp[level]=root;

    traverse(root->left,mp,level+1);
    traverse(root->right,mp,level+1);
}

vector<int> leftView(Node *root)
{
    int level=0;
    map<int,Node*> mp;

    traverse(root,mp,level);
    vector<int> res(mp.size());
    for(auto i:mp)
    {
        res[i.first]=i.second->data;
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
