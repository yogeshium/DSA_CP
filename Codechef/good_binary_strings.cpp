//Good Binary Strings : GOODBINSTR

/*
Given a binary string SS, find the number of
 indices such that flipping the value at this
 index makes SS have an equal number of 01 and 10 substrings.
*/


#include <iostream>
using namespace std;

/*
Observation :
    If given string is bad (not good) string
    :-  if we try to flip the first and last
        bit then we will get a good string

        but if we try to flip the middle bits,
        it will remain bad string.

    If given string is good string
    :-  if we try to flip the middle bits , it
        will remain good string.

        but if we try to flip the first and last
        bits then we will get a bad (not good) string.
*/

bool check(string s)
{
    int oz=0,zo=0;
    for(int i=0;i<s.length()-1;i++)
    {
        if(s[i]=='0')
        {
            if(s[i+1]=='1')
                zo++;
        }
        else
        {
            if(s[i+1]=='0')
                oz++;
        }
    }
    return (zo==oz);
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        getline(cin>>ws,s);
        int cnt =0, len = s.length();
        if(check(s))
            cnt = cnt + len-2;
        else
            cnt = cnt + 2;

        cout<<cnt<<endl;

    }
	return 0;
}
