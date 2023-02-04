#include<iostream>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K)
{
    vector<long long> ans;
    queue<int> Q;
    long long int i=0,j=0;
    while(j<N)
    {
        if(A[j]<0)
            Q.push(j);

        if(j-i<K)
        {
            if(j==K-1)
            {
               if(Q.empty()) ans.push_back(0);
               else ans.push_back(A[Q.front()]);
            }
            j++;

        }
        else
        {
           if(Q.empty())
            {
                ans.push_back(0);
                i++;j++;
            }
            else
            {
                while(j-Q.front()>=K)
                {    Q.pop(); if(Q.empty()) break;}

                if(Q.empty()) ans.push_back(0);
                else ans.push_back(A[Q.front()]);


                i++;j++;
            }

        }
    }
    return ans;

}


int main()
{

}
