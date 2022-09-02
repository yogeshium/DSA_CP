#include <bits/stdc++.h>
using namespace std;


//Editorial Code

int numberOfPainters(int arr[], int n, int maxLen)
{
    int total = 0, numPainters = 1;

    for (int i = 0; i < n; i++)
    {
        //cout<<"\n i = "<<i;
        total += arr[i];

        if (total > maxLen)
            {
            total = arr[i];
            numPainters++;
            }
       // cout<<"\n total = "<<total<<" numPainters = "<<numPainters;
    }

    return numPainters;
}

int minTime(int arr[], int n, int k)
{
    int s= INT_MIN, e=0;
        for(int i=0;i<n;i++)
        {
            if (s<arr[i])
                s= arr[i];
            e= e+arr[i];
        }

    while (s < e) {
        int mid = s + (e - s) / 2;

        //cout<<"\ns = "<<s<<" e = "<<e<<" mid = "<<mid;

        int requiredPainters = numberOfPainters(arr, n, mid);

        //cout<<"\nrequiredPainters = "<<requiredPainters;

        if (requiredPainters <= k)
            e = mid;
        else
            s = mid + 1;
    }


    return s;
}


//My Code : (Not Working for some specific testcases)
/*
    int isPossible(int arr[], int n, int k, int bar)
    {
        int c =1;int tim=0;
       for(int i=0;i<n;i++)
       {
            cout<<"\ni = "<<i<<" bar = "<<bar;
            if(tim + arr[i]>bar)
            {
                c++;
                tim = arr[i];
            }
            else
            {
                tim = tim + arr[i];

            }
             cout<<"  c = "<<c<<" tim = "<<tim;
        }
         if(c==k)
         return 0;
        if(c<k)
            return 1;

        return 2;
    }

    long long minTime(int arr[], int n, int k)
    {
        int s= INT_MIN, e=0;
        long long ans=-1;
        for(int i=0;i<n;i++)
        {
            if (s<arr[i])
                s= arr[i];
            e= e+arr[i];
        }
        int mid;
        while(s<=e)
        {

            mid = s + (e-s)/2;
            cout<<"\ns = "<<s<<" e = "<<e<<" mid = "<<mid;
            int flag=isPossible(arr, n,k,mid);
            cout<<"\n flag = "<<flag;
            if(flag==0)
                {
                    ans = mid;
                    e=mid-1;
                }
            else if(flag==1)
                {
                    e=mid-1;
                }
            else
                s=mid+1;
        }
        return ans;
    }
*/



int main()
{
    int arr[] = {15,10,19,10,5,18,7};
    cout<<"\n"<<minTime(arr,7,5);

    return 0;
}
