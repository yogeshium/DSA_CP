//Determine if Two Trees are Identical

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
bool isIdentical(Node *r1, Node *r2)
    {
        if(r1==NULL && r2==NULL)
            return true;
        if((r1!=NULL && r2==NULL)||(r1==NULL && r2!=NULL))
            return false;

        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);
        bool root = r1->data == r2->data;

        return left&right&root;
    }
*/





int main()
{

}
