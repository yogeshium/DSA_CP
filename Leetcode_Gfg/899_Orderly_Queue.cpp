#include<bits/stdc++.h>
using namespace std;

/* Approach :
Observation : if(k > 1) - we can rotate character ( under kth position tak). If u dry run it then u will
find that eventually at the end , string will be sorted. So just return sorted string.


But if (k==1) then , we can only rotate first character only everytime. So there can be S.length different
states can be generated and we will return lexicographically smallest string.
*/

 string orderlyQueue(string s, int k)
    {
       if(k>1)
        {
            sort(s.begin(),s.end());
            return s;
        }
        string res = s;
        for(int i=1;i<s.size();i++)
        {
            res = min(res,s.substr(i)+s.substr(0,i));
        }
        return res;
    }

int main()
{
    string ans= orderlyQueue("baaca", 3);
    cout<<"\n Answer : "<<ans;
    return 0;
}
