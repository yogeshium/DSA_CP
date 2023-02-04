//103 Binary Tree Zigzag Level Order Traversal


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




void reverse(vector<int> & ans)
    {
        int i=0, j=ans.size()-1;
        while(i<j)
        {
            int temp = ans[i];
            ans[i]=ans[j];
            ans[j]=temp;

            i++;j--;
        }
    }

    vector<vector<int>> zigzagLevelOrder(Node* root)
    {
        vector<vector<int>> res;
        bool flag = true;
        queue<Node*> q;
        q.push(root);q.push(NULL);
        vector<int> ans;
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            if(temp==NULL)
            {
                if(flag)
                    res.push_back(ans);
                else
                {
                    reverse(ans);
                    res.push_back(ans);
                }
                ans.clear();
                flag= !flag;
                if(!q.empty())
                    q.push(NULL);
            }
            else
            {
                ans.push_back(temp->data);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        for(int i=0;i<res.size();i++)
        {
            for(int j=0;j<res[i].size();j++)
                cout<<res[i][j]<<" ";
            cout<<"\n";
        }

        return res;
    }



int main()
{
    Node* root = NULL;
    root = buildFromLevelOrderTraversal(root);
    zigzagLevelOrder(root);
    return 0;
}
