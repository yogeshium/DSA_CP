#include<bits/stdc++.h>
using namespace std;

// My Approach (Not Optimal) ( Need to learn Dynamic Programming )

    bool isPalindrome(string s, int i, int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;j--;
        }
        return true;
    }
    string LP(string s, int i, int j)
    {
         if(i>=s.length() || j<0 || i>j)
            return "";
        if(i==j)
          return s.substr(i,1);

      //  cout<<"\n Before isPalindrome "<<s<<" "<<i<<" "<<j;

        if(isPalindrome(s,i,j))
        {
            return s.substr(i,j-i+1);
        }

      //  cout<<"\n After isPalindrome "<<s<<" "<<i<<" "<<j;

        string s1 = LP(s,i+1,j);
        string s2 = LP(s,i,j-1);

       // cout<<"\n s1 = "<<s1<<" s2 = "<<s2;

        if(s1.length()>s2.length())
            return s1;
        return s2;
    }

    string longestPalindrome(string s)
    {
        return LP(s,0, s.length()-1);
    }

int main()
{
  string ans = longestPalindrome("ab");
  cout<<"\n"<<ans;
  return 0;
}
