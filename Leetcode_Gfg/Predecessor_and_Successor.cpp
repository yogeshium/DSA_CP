//Predecessor and Successor
#include<bits/stdc++.h>
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



//Using Recursion
//Inorder traversal
void inorder(Node* root)
{
    if(root==NULL)
        return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//Using Recursion
//Preorder traversal
void preorder(Node* root)
{
    if(root==NULL)
        return ;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

//Using Recursion
//Postorder traversal
void postorder(Node* root)
{
    if(root==NULL)
        return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}



//Insert a Node in Binary Search Tree - Recursion
Node* insertIntoBST(Node* root, int d)
{
    if(root==NULL)
    {
        root=new Node(d);
        return root;
    }

    if(d>root->data)
        root->right=insertIntoBST(root->right,d);
    else
       root->left= insertIntoBST(root->left,d);
    return root;
}




//Insert a Node in Binary Search Tree - Iterative
Node* insertIntoBST_ITR(Node* root,int d)
{
    Node* nn = new Node(d);
    if(root==NULL)
        return nn;

    Node* temp = root;
    while(temp)
    {
        if(d>temp->data)
        {
            if(temp->right)
                temp = temp->right;
            else
            {temp->right=nn; break;}
        }
        else
        {
            if(temp->left)
                temp = temp->left;
            else
            {temp->left = nn;break;}
        }
    }
    return root;
}




//Inorder Predecessor and Inorder Successor

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    Node* temp = NULL;
    pre=NULL; suc=NULL;
    //Predecessor Nikal - key tak ka sbse bara number
    temp=root;
    while(temp)
    {
        if(temp->key<key)
        {
            pre=temp; temp = temp->right;
        }
        else
            temp=temp->left;
    }
    temp=root;
    //Successor Nikal - key se agla bara number
    while(temp)
    {
        if(temp->key>key)
        {
            suc=temp; temp = temp->left;
        }
        else
            temp=temp->right;
    }

}
