//Binary Search Tree

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

//Search in Binary Search Tree
Node* searchBST(Node* root, int val)
    {
        if(root==NULL)
            return NULL;
        if(val==root->data)
            return root;

        Node* temp = NULL;
        if(val>root->data)
            temp=searchBST(root->right,val);
        else
            temp=searchBST(root->left,val);

        return temp;
    }


//Delete in Binary Search Tree
int maxVal(Node* root)
{
    while(root->right)
        root=root->right;
    return root->data;
}
int minVal(Node* root)
{
    while(root->left)
        root=root->left;
    return root->data;
}


Node *deleteNode(Node *root, int x)
{
    if(root==NULL)
        return root;
    if(root->data==x)
    {
        //0 child
        if(root->left==NULL && root->right ==NULL)
        {
            delete root;
            return NULL;
        }

        //1 child left
        if(root->left!=NULL && root->right==NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //1 child right
        if(root->left==NULL && root->right!=NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left!=NULL && root->right!=NULL)
        {
            // Option 1: (left wala le lete hai)
           /* int maxi = maxVal(root->left);
            root->data= maxi;
            root->left=deleteNode(root->left,maxi);
            return root;
            */

            //Option 2:(right wala le lete hai)
            int mini = minVal(root->right);
            root->data = mini;
            root->right=deleteNode(root->right,mini);
            return root;
        }
    }
    else if(x>root->data)
    {   root->right = deleteNode(root->right,x);
         return root;
    }
    else
    {    root->left = deleteNode(root->left,x);
        return root;
    }
    return root;
}




int main()
{
    Node* root=NULL;
    root=insertIntoBST_ITR(root,50);
    root=insertIntoBST_ITR(root,30);
    root=insertIntoBST_ITR(root,70);
    root=insertIntoBST_ITR(root,40);
    root=insertIntoBST_ITR(root,60);
    root=insertIntoBST_ITR(root,80);

    BFS_show_level_wise(root);

    deleteNode(root,70);

    BFS_show_level_wise(root);

}
