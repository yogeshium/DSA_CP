#include<bits/stdc++.h>
using namespace std;

     vector<int> GeneratePrime(int n)
    {
        vector<int> prime;
        vector<bool> dummy(n,true);
        for(int i=2;i*i<=n;i++)
        {
            if(dummy[i]==true)
            {
                for(int j=i*i;j<=n;j+=i)
                    dummy[j]=false;
            }
        }
        for(int i=2;i<n;i++)
        {
            if(dummy[i]==true)
                prime.push_back(i);
        }
        return prime;
    }

    void SegmentedSieve(long long L, long long R)
    {
        vector<int> prime = GeneratePrime(sqrt(R)+1);
        vector<bool> dummy(R-L+1, true);

        for(auto pr : prime)
        {
            int fm=(L/pr)*pr;
            if(fm<L) fm = fm+pr;

            for(int j=max(fm,pr*pr);j<=R;j+=pr)
                {
                    dummy[j-L]=false;
                }
        }

            cout<<"Prime No. b/w "<<L<<" and "<<R<<" is ";
            for(int i=L;i<=R;i++)
            {
                if(dummy[i-L]==true)
                {
                   cout<<" "<<i;
                }
            }
    }

int main()
{

    SegmentedSieve(1,100);
    return 0;
}
