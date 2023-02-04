//The Celebrity Problem
#include<bits/stdc++.h>
using namespace std;


//My Approach :
/*
int celebrity(vector<vector<int> >& M, int n)
    {
        vector<int>knows(n,0);
        vector<int>known(n,0);

        for(int i=0;i<M.size();i++)
        {
            for(int j=0;j<M[0].size();j++)
            {
                if(M[i][j]==1)
                {
                    knows[i]++;
                    known[j]++;
                }
            }
        }
        int cnt=0;
        for(int k=0;k<n;k++)
        {
            if(knows[k]==0)
                cnt++;
        }
        if(cnt>1 ||cnt<=0)
            return -1;

        for(int k=0;k<n;k++)
        {
            if(knows[k]==0 && known[k]>0)
                return k;
        }
        return -1;
    }
*/

//Brute Force :
/*

/*


//Approach 2 : (Optimal)
/*
bool is_Size_One(stack<int>& jar)
    {
        if(jar.empty())
            return false;
        int temp = jar.top();
        jar.pop();
        if(jar.empty())
        {
            jar.push(temp);
            return true;
        }
        jar.push(temp);
        return false;
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n)
    {
        stack<int> jar;
        for(int i=0;i<n;i++)
            jar.push(i);
        while(!is_Size_One(jar))
        {
            int a= jar.top();jar.pop();
            int b= jar.top();jar.pop();
            if(M[a][b]==1)
            {
                jar.push(b);
            }
            else if(M[b][a]==1)
            {
                jar.push(a);
            }
        }
        //cout<<jar.top();
        for(int i=0; i<M[0].size();i++)
        {
            if(M[jar.top()][i]!=0)
                return -1;
        }
        for(int i=0;i<M.size();i++)
        {
            if(M[i][jar.top()]==0 && i!=jar.top())
                return -1;
        }
        return jar.top();
    }
*/
