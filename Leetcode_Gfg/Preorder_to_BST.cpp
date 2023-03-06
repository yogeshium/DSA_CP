//Preorder to BST

#include<bits/stdc++.h>
using namespace std;


typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}



                            //Solution


//Approach 2 : (using inorder and preorder) O(nlog(n))
int Bsearch(vector<int>& A, int s, int e, int t)
    {
        int mid = s+(e-s)/2;
        while(s<=e)
        {
            if(A[mid]==t)
                return mid;
            else if(A[mid]>t)
                e=mid-1;
            else
                s=mid+1;
            mid = s+(e-s)/2;
        }
        return -1;
    }
    void makeBST(Node* &root, int pre[], vector<int>& in , int& i, int s, int e)
    {
        //cout<<"\ni= "<<i<<" s= "<<s<<" e= "<<e<<" pre[i]= "<<pre[i];
        if(i>=in.size())
            return ;
        int idx = Bsearch(in , s, e, pre[i]);
        if(idx==-1)
        {  i=i-1;}
        else
        {
            root=newNode(pre[i]);
            //cout<<"\n  "<<root->data;
            i=i+1;
            makeBST(root->left, pre,in,i,s,idx-1);
            i=i+1;
            makeBST(root->right, pre,in,i,idx+1,e);
        }
    }

    Node* post_order(int pre[], int size)
    {
        vector<int> in;
        for(int i=0;i<size;i++)
            in.push_back(pre[i]);

        sort(in.begin(), in.end());
        Node* root = NULL; int i=0;
        makeBST(root, pre, in, i, 0, size-1);
        return root;
    }

//(This concept also worked in check bST)
//Approach 3: (most optimal)
/*
void makeBST_pre(Node* &root, int pre[], int& i, int n,pair<int,int> range)
    {
        //cout<<"\n i= "<<i<<" n ="<<n<<" pair : "<<range.first<<" "<<range.second;
        if(i>=n)
            return;
        if(pre[i]<range.first || pre[i]>range.second)
        {
            i=i-1;return;
        }

        root = newNode(pre[i]);
        pair<int,int> rleft = make_pair(range.first, pre[i]);
        pair<int,int> rright = make_pair(pre[i],range.second);
        i=i+1;
        makeBST_pre(root->left, pre,i,n,rleft);
        i=i+1;
        makeBST_pre(root->right, pre,i,n,rright);
    }

    Node* post_order(int pre[], int size)
    {
        int i=0;Node* root=NULL;
        pair<int,int> range = make_pair(INT_MIN,INT_MAX);
        makeBST_pre(root, pre, i, size, range);
        return root;
    }
*/


int main()
{
    int pre[] = {40,30,35,80,100};
    vector<int>A = {30,35,40,80,100};
    for(int i=0;i<5;i++)
        cout<<Bsearch(A,0,5,pre[i]);

}
