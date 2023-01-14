//921. Minimum Add to Make Parentheses Valid

#include<bits/stdc++.h>
using namespace std;


//My Approach = Babbar
int minAddToMakeValid(string s)
    {
        stack<char> jar;
        for(int i=0;s[i]!=0;i++)
        {
            if(s[i]=='(')
                jar.push(s[i]);
            else
            {
                if(jar.empty())
                    jar.push(s[i]);
                else if(jar.top()=='(')
                {
                    jar.pop();
                }
                else
                    jar.push(s[i]);
            }
        }
        int cnt=0;
        while(!jar.empty())
        {
            cnt++;
            jar.pop();
        }
        return cnt;
    }
