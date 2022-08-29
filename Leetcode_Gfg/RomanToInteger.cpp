#include <bits/stdc++.h>
using namespace std;
int romanToInt(string s) 
    {
        int sum =0;
        int len = s.length();
        for(int i=len-1;i>=0;i--)
        {
            if(s[i] == 'I')
                sum = sum + 1;
            else if(s[i]=='V')
            {
                sum = sum+5;
                if(i-1>=0)
                {
                    if(s[i-1]=='I')
                    {
                        sum = sum -1;
                        i--;
                    }
                        
                }
                    
            }
            else if(s[i]=='X')
            {
                sum = sum + 10;
                if(i-1>=0)
                {
                    if(s[i-1]=='I')
                    {
                         sum = sum -1;
                        i--;
                    }
                }
            }
            else if(s[i]=='L')
            {
                sum = sum + 50;
                if(i-1>=0)
                {
                    if(s[i-1]=='X')
                    {
                        sum = sum -10;
                        i--;
                    }
                }
                
            }
             else if(s[i]=='C')
            {
                sum = sum+100;
                if(i-1>=0)
                {
                    if(s[i-1]=='X')
                    {
                         sum = sum -10;
                        i--;
                    }
                }
            }
            else if(s[i]=='D')
            {
                sum = sum+500;
               if(i-1>=0)
                {
                    if(s[i-1]=='C')
                    {
                        sum = sum -100;
                        i--;
                    }
                }
            }
            else
            {
                sum = sum+1000;
                if(i-1>=0)
                {
                    if(s[i-1]=='C')
                    {
                         sum = sum -100;
                        i--;
                    }
                }
            }
        
        }
        return sum;
    }

int main() {
	string s = "LVIII";
	cout<<romanToInt(s);
	
	return 0;
}