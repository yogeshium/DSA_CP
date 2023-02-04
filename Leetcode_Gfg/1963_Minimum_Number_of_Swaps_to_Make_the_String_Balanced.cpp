//1963. Minimum Number of Swaps to Make the String Balanced
#include<bits/stdc++.h>
using namespace std;


//My Approach
int minSwaps(string s)
    {
        stack<char> jar;
        int jarSize=0;
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]=='[')
            {
               jar.push(s[i]);jarSize++;
            }
            else
            {
                if(jar.empty())
                {jar.push(s[i]);jarSize++;}
                else if(jar.top()=='[')
                {jar.pop();jarSize--;}
                else
                {jar.push(s[i]);jarSize++;}
            }
        }

        if(jarSize==0)
            return 0;
        int cnt =0;
        char ch=jar.top();jar.pop();
        while(jarSize)
        {
            if(jar.top()==ch)
            {
                jarSize=jarSize-4;cnt++;
                jar.pop();
                if(jar.empty())
                    break;
                ch=jar.top();
                jar.pop();
            }
            else
            {
                jar.pop();
                cnt++;jarSize = jarSize-2;
                if(jar.empty())
                    break;
                ch=jar.top();
                jar.pop();
            }
        }
        return cnt;
    }
