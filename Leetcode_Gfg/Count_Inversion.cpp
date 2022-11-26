#include<bits/stdc++.h>
using namespace std;

// merge sort method


// the left and right halves are sorted
// considering one single iteration, if while merging no element in right array comes before any element in left array
// then there are no inversions
// and if one element in right array comes before k elements in left array then there are k inversions

// counting these inversions

// this works for all interations because after each merge sort iteration, there will be no inversions left in that segment
// only inversions left are the inversions between left and right arrays

// count recursively

// O(n log(n)) normal merge sort


    long long int Count(long long int A[], long long l1, long long r1, long long l2, long long r2)
    {
        long long s=l1, i=0;
        long long int ans= 0;
        long long int res[r2-l1+1];
        while(l1<=r1 && l2<=r2)
        {
            if(A[l1]<=A[l2])
                res[i++]=A[l1++];
            else
                {res[i++]=A[l2++];ans = ans+ r1-l1+1;}
        }
        while(l1<=r1)
        {
            res[i++]=A[l1++];
        }
        while(l2<=r2)
        {
            res[i++]=A[l2++];
        }
        for(int j=s;j<=r2;j++)
        {
            A[j]=res[j-s];
        }

        return ans;
    }
    void Divide(long long A[], long long s, long long e, long long int & ans)
    {
        if(s>=e)
            return ;

        long long mid = s+(e-s)/2;
        Divide(A,s,mid,ans);
        Divide(A,mid+1,e,ans);
        ans = ans + Count(A,s,mid, mid+1, e);
    }

    long long int inversionCount(long long arr[], long long N)
    {
        long long int ans =0;
        Divide(arr, 0, N-1, ans);
        return ans;
    }


    int main()
    {
        long long arr[6]={4,5,6,1,2,3};
        cout<<"\n"<<inversionCount(arr,6);
    }
