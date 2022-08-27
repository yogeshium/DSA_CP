#include <bits/stdc++.h>
using namespace std;

//For Integer part of root only - My Aproach

int sqrtInteger(int x)
{
    if(x==0 || x==1)
            return x;
        int s= 0, e=x;
        int mid;

        while(s<e)
        {
            mid = s+(e-s)/2;

            if(mid == (int)(x/mid))
                return mid;
            else if(mid > (int)(x/mid))
            {
                e= mid-1;
            }
            else
                s= mid+1;
        }
       if((int)(x/s) - s <0)
           return s-1;
        else
            return s;
}

//For Integer part of root only - Babbar Approach
/*
long long int sqrtInteger(int x)
{

        int s= 0, e=x;
        long long int mid;
        int ans = -1;
        while(s<=e)
        {
           long long int sq = mid*mid;

            if(sq == x)
                return mid;
            else if(sq>x)
            {
                e= mid-1;
            }
            else
            {
                ans = mid;
                s= mid+1;
            }
            mid = s+(e-s)/2;

        }
        cout<<ans<<"\n";
        return ans;
}
*/


double morePrecision(int n, int precision, int tempsol)
{
        double ans = tempsol;
        double factor = 1;
        for(int i=1;i<=precision;i++)
        {
            factor = factor/10;
            for(double j=ans ;j*j<n;j=j+factor)
            {
                ans = j;
            }
        }
        return ans;
}

int main()
{
            int tempsol= sqrtInteger(43);
            cout<<tempsol<<endl;
        cout<<" Answer: "<<morePrecision(43,4,tempsol);

        return 0;
}
