//Lowest Common Ancestor in a Binary Tree

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
//My Approach :
/*
bool ancestor(Node* root, int d,vector<Node*>& v)
    {
        if(root==NULL)
            return false;
        if(root->data==d)

        {   v.push_back(root);
            return true;
        }
        v.push_back(root);

        bool c1 = ancestor(root->left,d,v);
        if(c1)
            return c1;

        bool c2= ancestor(root->right,d,v);
        if(c2)
            return c2;
        v.pop_back();
        return c2;
    }

    Node* lca(Node* root ,int n1 ,int n2 )
    {
       vector<Node*> An1,An2;
       ancestor(root,n1,An1);
       ancestor(root,n2,An2);

       Node* lca=root;
       int i=0,j=0;
       while(i<An1.size() && j<An2.size() && An1[i]==An2[j])
       {
           lca = An1[i];
           i++;j++;
       }
       return lca;
    }

*/

//Approach : (recursive) (babbar)
/*
Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root==NULL)
            return NULL;

        if(root->data == n1)
            return root;
        if(root->data == n2)
            return root;

        Node* L = lca(root->left,n1,n2);
        Node* R= lca(root->right,n1,n2);

        if(L==NULL && R==NULL)
            return NULL;
        else if(L!=NULL && R==NULL)
            return L;
        else if(L==NULL && R!=NULL)
            return R;
        else
            return root;
    }
*/




//7 1 10 -1 2 9 11 -1 4 8 -1 -1 12 -1 -1 -1 -1 -1 -1
//25 20 35 15 22 30 45 -1 -1 -1 -1 -1 32 -1 -1 -1 -1
    int main()
    {
        Node* root = NULL;
        root=buildFromLevelOrderTraversal(root);
        BFS(root);

        lca(root,9,11);
        return 0;
    }
