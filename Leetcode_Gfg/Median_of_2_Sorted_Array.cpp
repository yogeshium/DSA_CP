#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& N1, vector<int>& N2)
    {
      if(N2.size()<N1.size())
        return findMedianSortedArrays(N2,N1);

      int n1 = N1.size(), n2 = N2.size();
      int s=0, e= n1;
        if(N1.size()==0)
        {
            if(n2&1)
            return N2[(n2-1)/2];
            else
            return (N2[n2/2] + N2[n2/2-1])/2.0;
        }

      while(s<=e)
      {
          int cut1= s+((e-s)>>1);
          int cut2= (n1+n2+1)/2 - cut1;

          int l1 = cut1==0?INT_MIN:N1[cut1-1];
          int l2 = cut2==0?INT_MIN:N2[cut2-1];
          int r1 = cut1==n1?INT_MAX:N1[cut1];
          int r2 = cut2==n2?INT_MAX:N2[cut2];

        if(l1<=r2 && l2<=r1)
        {
            if((n1+n2)&1)
                return max(l1,l2);
            else
                return (max(l1,l2) + min(r1,r2))/2.0;
        }
        else if(l1>r2)
            e=cut1-1;
        else
            s=cut1+1;
      }
      return 0.0;
    }

int main()
{
    vector<int> A1={7,12,14,15};
    vector<int> A2 = {1,2,3,4,9,11};
    cout<<findMedianSortedArrays(A1,A2);
    return 0;

}
