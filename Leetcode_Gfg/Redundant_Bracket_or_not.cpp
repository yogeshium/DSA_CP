//Expression contains redundant bracket or not
#include<bits/stdc++.h>
using namespace std;


//My Approach = Babbar
int checkRedundancy(string s)
    {
        stack<char> jar;
        bool flag;
        for(int i=0;s[i]!='\0';i++)
        {
            flag = false;
            if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
                jar.push(s[i]);
            else
            {
                if(s[i]==')')
                {
                    while(jar.top()!='(')
                    {
                        if(jar.top()=='+' || jar.top()=='-' || jar.top()=='*' || jar.top()=='/')
                        {    flag = true; jar.pop();}
                    }
                    if(flag)
                        jar.pop();
                    else
                        return 1;
                }
            }
        }
        return 0;
    }
