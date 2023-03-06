//Largest BST

#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


                        //Solution
//My Approach : (Optimized) same as babbar
struct Info
    {
        public:

        bool flag;
        int mn;
        int mx;
        int nn;

        Info(bool f , int mini, int maxi , int n)
        {
            flag = f;
            mn= mini;
            mx = maxi;
            nn = n;
        }
    };

    struct Info solve(Node* root, int& ans)
    {
        if(root==NULL)
        {
            struct Info r(true, 0, 0, 0);
            return r;
        }


        struct Info L = solve(root->left, ans);
        struct Info R = solve(root->right, ans);

        //cout<<"\n root = "<<root->data<<" ans = "<< ans;
        //cout<<"\n   L = "<<L.flag<<" "<<L.mn<<" "<<L.mx<<" "<<L.nn ;
        //cout<<"\n   R = "<<R.flag<<" "<<R.mn<<" "<<R.mx<<" "<<R.nn;

        struct Info r(true, 0, 0, 0);
        if(L.flag && R.flag)
        {
            if(L.mx==0 && R.mn==0)
            {
                r.mn = root->data;
                r.mx=root->data;
                r.nn=1;
            }
            else if((L.mx==0 && R.mn!=0)&&(root->data<R.mn))
            {
                r.mn=root->data;
                r.mx = R.mx;
                r.nn= R.nn+1;
            }
            else if((R.mn==0 && L.mx!=0)&& (root->data>L.mx))
            {
                r.mn = L.mn;
                r.mx= root->data;
                r.nn= L.nn+1;
            }
            else if((L.mx!=0 && R.mn!=0)&&(root->data>L.mx && R.mn>root->data))
            {
                r.mn = L.mn;
                r.mx= R.mx;
                r.nn = L.nn+R.nn +1;
            }
            else
            {
                r.flag = false;
            }
        }
        else
        {
            r.flag = false;
        }
        if(r.nn>ans)
                ans= r.nn;

        return r;
    }

    int largestBst(Node *root)
    {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
