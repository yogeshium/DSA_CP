#include<bits/stdc++.h>
using namespace std;

 int countPrimes(int n)
    {
        if(n<3)
            return 0;
        bool prime[n];
        prime[0]=false;prime[1]=false;
        for(int i=2;i<n;i++)
            prime[i]=true;

        for(int i=2;i<n;i++)
        {
            if(prime[i]==true)
            {
                for(int j=2;i*j<n;j++)
                {
                    prime[i*j] = false;
                }
            }

        }
        int count=0;
        for(int i=2;i<n;i++)
        {
            if(prime[i]==true)
                count++;
        }

        return count;

    }

int main()
{
    int n=100;
    cout<<"Total no. of prime no.s strictly less than "<<n<<" is "<<countPrimes(n);

    return 0;
}
