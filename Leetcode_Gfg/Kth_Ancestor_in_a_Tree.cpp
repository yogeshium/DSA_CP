//Kth Ancestor in a Tree
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
bool ancestor(Node* root, int d,vector<int>& v)
    {
        if(root==NULL)
            return false;
        if(root->data==d)

        {
            //v.push_back(root->data);
            return true;
        }
        v.push_back(root->data);

        bool c1 = ancestor(root->left,d,v);
        if(c1)
            return c1;

        bool c2= ancestor(root->right,d,v);
        if(c2)
            return c2;
        v.pop_back();
        return c2;
    }


int kthAncestor(Node *root, int k, int node)
{
    vector<int> A;
    ancestor(root,node,A);
    if(A.size()==0|| k>A.size())
        return -1;

    return A[A.size()-k];

}  return ans;

*/



//My Approach :(Recursive)
/*
vector<int> solve(Node* root, int k, int node , int cnt)
{
    if(root==NULL)
    {
        vector<int> v={0,cnt,-1};
        return v;
    }
    if(root->data == node)
    {
        vector<int> v={1,cnt,-1};
        return v;
    }

     vector<int> L = solve(root->left,k, node,cnt+1);
     if(L[0]==1)
     {
         if(L[1]-k==cnt)
         {
             L[2]=root->data;
             return L;
         }
         return L;
     }
     vector<int> R= solve(root->right, k, node, cnt+1);
     if(R[0]==1)
     {
         if(R[1]-k==cnt)
         {
             R[2]=root->data;
             return R;
         }
         return R;
     }

     return R;
}

int kthAncestor(Node *root, int k, int node)
{
    vector<int> ans = solve(root,k,node,0);
    return ans[2];
}
*/

//Babbar Approach ( recursive):
/*
Node* solve(Node* root, int &k, int node)
{
    if(root==NULL)
        return NULL;
    if(root->data==node)
        return root;

    Node* L = solve(root->left,k,node);
    Node* R = solve(root->right,k,node);

    if(L !=NULL && R==NULL)
    {
        k--;
        if(k<=0)
        {
            k=INT_MAX;
            return root;
        }
        return L;
    }
    else if(L==NULL &&R!=NULL )
    {
        k--;
        if(k<=0)
        {
            k=INT_MAX;
            return root;
        }
        return R;
    }

    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    Node* ans= solve(root,k,node);
    if(ans==NULL || ans->data==node)
        return -1;
    return ans->data;
}
*/







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
