//85. Maximal Rectangle
#include<bits/stdc++.h>
using namespace std;


/*
// Largest Rectangle in Histogram:
   void prevSmaller(vector<int> A, vector<int>& L)
    {
        stack<int> s;s.push(-1);
        for(int i=0;i<A.size();i++)
        {
            if(s.top()!=-1)
            {
                while(A[s.top()]>=A[i])
                {
                    s.pop();
                    if(s.top()==-1)
                        break;
                }
            }
            L[i] = s.top();
            s.push(i);
        }
    }
    void nextSmaller(vector<int> A, vector<int>& R)
    {
        stack<int> s;s.push(A.size());
        for(int i=A.size()-1;i>=0;i--)
        {
            if(s.top()!=A.size())
            {
                while(A[s.top()]>=A[i])
                {
                    s.pop();
                    if(s.top()==A.size())
                        break;
                }
            }
            R[i] = s.top();
            s.push(i);
        }
    }

    int largestRectangleArea(vector<int> A)
    {
        vector<int> L(A.size());
        prevSmaller(A,L);
        vector<int> R(A.size());
        nextSmaller(A,R);


        // for(int i=0;i<L.size();i++)
        //     cout<<L[i]<<" ";
        // cout<<"\n";
        // for(int i=0;i<R.size();i++)
        //     cout<<R[i]<<" ";

        int res=0;
        for(int i=0;i<A.size();i++)
        {
            int area= (R[i]-L[i]-1)*A[i];
            if(res<area)
                res= area;

        }
        return res;
    }

Yaha se h actual:

    int maximalRectangle(vector<vector<char>>& mat)
    {
        vector<int> curr(mat[0].size(),0);

        for(int i=0;i<mat[0].size();i++)
            curr[i]=mat[0][i]-'0';

        int maxArea=largestRectangleArea(curr);

        for(int i=1;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]=='1')
                    curr[j]= mat[i][j]-'0' + curr[j];
                else
                    curr[j]=0;
            }

            maxArea=max(maxArea,largestRectangleArea(curr));

        }
        return maxArea;
    }
*/
