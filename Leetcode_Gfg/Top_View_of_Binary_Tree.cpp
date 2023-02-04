//Top View of Binary Tree

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
    cout<<"\nEnter root = ";
    int d; cin>>d;
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



                                        //Solution

//My Approach :
/*
void traverseReverseLeft(Node* root, vector<int>& ans,int cnt=0)
    {
        if(root==NULL)
            return ;


        if(root->left && cnt!=0)
            traverseReverseLeft(root->left,ans,cnt+1);
        else if(root->left)
            traverseReverseLeft(root->left,ans);
        else if(root->right && cnt==0)
            traverseReverseLeft(root->right,ans,cnt-2);
        else
            traverseReverseLeft(root->right,ans,cnt-1);

        if(cnt==0)
         {
             cout<<root->data<<" ";
             ans.push_back(root->data);
         }
    }

//Test case 12 : (not passed) but i think it should be passed
//7 5 8 2 6 N 56 1 3 N N 10 57 N N N 4 9 51 N N N N N N 13 52 12 45 N 55 11 N 20 49 54 N N N 15 44 48 50 53 N 14 18 23 N 46 N N N N N N N 16 19 21 30 N 47 N 17 N N N 22 28 34 N N N N N N 24 29 N N N N N N

 void traverseRight(Node* root,vector<int>& ans, int cnt=0)
    {
        if(root==NULL)
            return ;

        if(cnt==0)
        {
            cout<<root->data<<" ";
            ans.push_back(root->data);
        }

        if(root->right && cnt!=0)
            traverseRight(root->right,ans,cnt);
        else if(root->right && cnt==0)
            traverseRight(root->right,ans);
        else if(root->left && cnt==0)
            traverseRight(root->left,ans,cnt+2);
        else
            traverseRight(root->left,ans,cnt+1);
    }

    vector<int> topView(Node *root)
    {
        vector<int> res;
        traverseReverseLeft(root->left,res);
        res.push_back(root->data);
        traverseRight(root->right,res);
        return res;
    }

*/

//Babbar :
    //me: code
/*
vector<int> topView(Node *root)
    {
        int m1=INT_MAX, m2=INT_MIN;
        map<int,Node*> mp;

        queue<pair<Node*, int>> q;
        q.push(make_pair(root,0));


        while(!q.empty())
        {
            pair<Node*, int> temp = q.front();
            q.pop();

            if(temp.second>m2)
                m2=temp.second;
            if(temp.second<m1)
                m1=temp.second;

            if(mp.find(temp.second)==mp.end())
                mp[temp.second]=temp.first;

            if(temp.first->left)
                q.push(make_pair(temp.first->left,temp.second-1));
            if(temp.first->right)
                q.push(make_pair(temp.first->right,temp.second+1));

        }
        vector<int> res;
        for(int i=m1;i<=m2;i++)
            res.push_back(mp[i]->data);

        return res;
    }
*/

    //babbar code:
/*
// dont even need map
    void traverse(Node* root,vector<int>& res,int level)
{
    if(root==NULL)
        return;

    if(level==res.size())
        res.push_back(root->data);

    traverse(root->left,res,level+1);
    traverse(root->right,res,level+1);
}

vector<int> leftView(Node *root)
{
    int level=0;
    vector<int> res;
    traverse(root,res,level);

    return res;
}

*/







int main()
{
    Node* root = NULL;
    root =buildFromLevelOrderTraversal(root);
    //BFS(root);


    return 0;
}
