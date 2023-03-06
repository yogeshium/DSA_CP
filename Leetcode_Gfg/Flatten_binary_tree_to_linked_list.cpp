//Flatten binary tree to linked list

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



void flatten(Node *root)
    {
        Node* curr = root;
        while(curr!=NULL)
        {
            if(curr->left!=NULL)
            {
               Node* pred =curr->left;
                while(pred->right)
                    pred = pred->right;
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr= curr->right;
        }
    }


//1 2 3 4 5 -1 6 8 7 -1 -1 -1 -1 -1 -1 -1 -1
//1 2 3 4 5 N 6 8 7 N N N N N N N N

int main()
{
    Node* root=NULL;
    root = buildFromLevelOrderTraversal(root);
    MorrisTraverse(root);

    return 0;
}
