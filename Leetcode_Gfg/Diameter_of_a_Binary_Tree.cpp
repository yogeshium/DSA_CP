//Diameter of a Binary Tree

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



//Approach 1 :
/*
int Max(int a, int b, int c)
   {
       if(a>b)
       {
           if(a>c)
            return a;
            else
            return c;
       }
       else
            if(b>c)
                return b;
            else
                return c;
   }

    int height(Node* node)
    {
        if(node==NULL)
            return 0;
        return max(height(node->left), height(node->right))+1;
    }

    int diameter(Node* root)
    {
        if(root==NULL)
            return 0;
        return Max(diameter(root->left), diameter(root->right), height(root->left) + 1 + height(root->right));
    }
*/

//Approach 2 :

/*
pair<int,int> diameterFast(Node* node)
    {
        if(node==NULL)
        {
            pair<int,int> p(0,0);
            return p;
        }

        pair<int,int> left = diameterFast(node->left);
        pair<int,int> right = diameterFast(node->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second+1;

        pair<int,int> ans;
        ans.first = max(op1,max(op2,op3));
        ans.second = max(left.second, right.second) + 1;
        return ans;

    }

    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root)
    {
         return diameterFast(root).first;
    }
*/





int main()
{

}
