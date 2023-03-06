//Burning Tree
//Minimum Time to Burn the entire binary tree
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

Node* findTarget(Node* root, int t)
    {
        if(root==NULL)
            return NULL;
        if(root->data == t)
            return root;
        Node* ans= findTarget(root->left,t);
        if(ans)
            return ans;
        return findTarget(root->right,t);
    }

    void burnTime(Node* root,map<Node*, Node*>& ntp ,map<Node*,bool>& burnt , int t, int& ans)
    {
        if(root==NULL)
            return;
        if(burnt.find(root)!=burnt.end()) return ;

        burnt[root]=true;

        if(t>ans) ans= t;

        if(root->left)
            burnTime(root->left,ntp,burnt,t+1,ans);
        if(root->right)
            burnTime(root->right,ntp,burnt,t+1,ans);
        if(ntp[root])
            burnTime(ntp[root],ntp,burnt,t+1,ans);

    }

    int minTime(Node* root, int t)
    {
        //Step 1 : Mapping create Node to Parent
        map<Node*, Node*>nodeToParent;
        queue<Node*> q;
        q.push(root);nodeToParent[root]=NULL;
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();

            if(temp->left)
            {
                nodeToParent[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                nodeToParent[temp->right]=temp;
                q.push(temp->right);
            }
        }

        //Step 2 : find target Node

        Node* target = findTarget(root,t);

        //Step 3 : Calculate the time
        int res=0;
        map<Node*,bool>burnt;
        burnTime(target,nodeToParent,burnt,0,res);
        return res;
    }


int main()
{

}
