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


//Build Tree
Node* buildTree(Node* root)
{
    cout<<"\nEnter the data (-1 for NULL) : ";
    int d;cin>>d;
    root = new Node(d);

    if(d==-1) return NULL;
    cout<<"\nInsert in Left for "<<root->data<<" : ";
    root->left = buildTree(root->left);
    cout<<"\nInsert in Right for "<<root->data<<" : ";
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


//Reverse Level Order Traversal using stack and queues
void reverse_level_order_traversal(Node* root)
{
   queue<Node*> q;
   stack<Node*> s;


   q.push(root);
   while(!q.empty())
   {
       Node* temp = q.front();
       q.pop();
       s.push(temp);
       if(temp->right)
        q.push(temp->right);
       if(temp->left)
        q.push(temp->left);
   }

   while(!s.empty())
   {
       cout<<s.top()->data<<" ";
       s.pop();
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


//Without Using Recursion (Iterative)
//Inorder Traversal

void inorder_itr(Node* root)
{
    stack<Node*> s;
    Node* curr = root;
    while(curr!=NULL || s.empty()==false)
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr= curr->right;
    }
}

//Without Using Recursion (Iterative)
//Preorder Traversal

void preorder_itr(Node* root)
{
    stack<Node*> s;
    s.push(root);
    while(!s.empty())
    {
        Node* curr = s.top(); s.pop();
        cout<<curr->data<<" ";
        if(curr->right)
            s.push(curr->right);
        if(curr->left)
            s.push(curr->left);
    }
}

//Without Using Recursion (Iterative)
//Postorder Traversal

void postorder_itr(Node* root)
{
    stack<Node*> s;
    s.push(root);
    stack<Node*> print;
    while(!s.empty())
    {
        Node* curr = s.top();s.pop();
        print.push(curr);
        if(curr->left)
            s.push(curr->left);
        if(curr->right)
            s.push(curr->right);
    }

    while(!print.empty())
    {
        cout<<print.top()->data<<" ";
        print.pop();
    }
}





int main()
{
    Node* root = NULL;
    root = buildTree(root);
        //1 2 4 7 -1 -1 8 9 -1 -1 10 -1 -1 5 -1  -1 3 6 -1 -1 -1

    cout<<"\nTree : "<<endl;postorder_itr(root);
    return 0;
}
