//K-th Largest Sum Contiguous Subarray

#include<bits/stdc++.h>
using namespace std;


int kthLargest(vector<int> &A,int n,int k)
    {
        priority_queue<int, vector<int>,greater<int>> mh;

        int cnt=0;
        for(int i=0;i<A.size();i++)
        {
            int sum = 0;
            for(int j=i;j<A.size();j++)
            {
                sum =sum+A[j];
                if(cnt<k)
                {
                    mh.push(sum);
                    cnt++;
                }
                else
                {
                    if(sum>mh.top())
                    {
                        mh.pop();
                        mh.push(sum);
                    }
                }
            }
        }

       // print(mh);

        return mh.top();
    }
