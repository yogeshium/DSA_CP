//K Sum Paths
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

//Babbar Approach :

void Count(Node* root, vector<int> path, int k, int& ans, int m)
    {
        if(root==NULL)
            return ;
        path.push_back(root->data);

        Count(root->left,path,k,ans,m);
        Count(root->right,path,k,ans,m);

        //check for k sum
        int sum=0;
        for(int i=path.size()-1;i>=0;i--)
        {
            sum = sum+path[i];
            if(sum==k)
                ans= (ans+1)%m;
        }
        path.pop_back();
    }

    int sumK(Node *root,int k)
    {
        int m=1000000007;
        vector<int> path;
        int ans=0;
        Count(root,path, k, ans,m);
        return ans;
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
