#include <bits/stdc++.h>
using namespace std;

     bool isPossible(int A[], int N, int M, int bar)
    {
        int s = 1, pages = 0;
        for(int i=0;i<N;i++)
        {
         
            if(A[i]>bar) return false;

            if(pages + A[i]> bar)
            {
                s=s+1;
                pages = A[i];
            }
            else
            {

                pages = pages + A[i];
            }
        }
        if(s>M)
            return false;

        return true;
    }

    int findPages(int A[], int N, int M)
    {
        if(M>N)
            return -1;
        int s= 0, e=0, ans =-1, mid;
        for(int i=0;i<N;i++)
            e= e+A[i];
        while(s<=e)
        {
            mid = s+(e-s)/2;
            
            if(isPossible(A,N,M,mid))
            {
                ans = mid;
                e = mid-1;
            }
            else
                s= mid+1;
        }
        return ans;
    }

int main() 
{
    int A[4]={12,34,67,90};
    cout<<"\nAnswer: "<<findPages(A,4,2);
    
    return 0;
}