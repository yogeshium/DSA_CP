//Boundary Traversal of binary tree


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




void traverseLeft(Node* root, vector<int>& ans)
    {
        if(root==NULL)
            return ;
        if(root->left==NULL && root->right==NULL)
            return;

        ans.push_back(root->data);

        if(root->left)
            traverseLeft(root->left,ans);
        else
            traverseLeft(root->right,ans);
    }

    void traverseLeaf(Node* root, vector<int>& ans)
    {
        if(root==NULL)
            return ;

        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(root->data);
            return ;
        }
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
    }

    void traverseRight(Node* root, vector<int>& ans)
    {
        if(root==NULL)
            return ;
        if(root->left==NULL && root->right==NULL)
            return;

        if(root->right)
            traverseRight(root->right,ans);
        else
            traverseRight(root->left,ans);

         ans.push_back(root->data);

    }

    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root==NULL)
            return ans;

        ans.push_back(root->data);

        //left subtree
        traverseLeft(root->left,ans);

        //left subtree leaf nodes
        traverseLeaf(root->left,ans);

        //Right subtree leaf nodes
        traverseLeaf(root->right,ans);

        //right subtree
        traverseRight(root->right,ans);
        return ans;
    }


int main()
{

    return 0;
}
