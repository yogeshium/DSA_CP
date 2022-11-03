#include<bits/stdc++.h>
using namespace std;


// My Approach (using bool array )
/*
I am taking array of bool A for 256 characters(bcz of constraint = ll characters) (this will help us to make record for every character
that whether this character is present in temp or not. I am traversing through string and pushing every character to temprory string (temp)
if that character is never entered in temp before.(After every push i give true value to that character position in A showing that
now this character is present in temp). If that character is already present in temp then i will erase temp from start till the place
where that character is present, now i will push that character to temp ( sliding window technique) . while doing all this , i am also
maintaining a string res that will store maximum substring that ever came in temp. At last i will return res.size();
*/
    string eras(string s, char ch,vector<bool>& A)
    {
        string res = "";int i=0;
       // cout<<"\n                 s = "<<s<<" ch = "<<ch<<" A[ch] "<<A[ch];
        while(s[i]!=ch && i<s.size())
        {
            A[s[i]]=false; // while erasing these characters i also have to put false back to there character position in A.
            i++;
        }
        // I have reached that character
        for(i++;i<s.size();i++)
        {
            res.push_back(s[i]);//, now i will copy all next characters to res so that eventually i will get that string which will
                                // contain string after that character.
        }
        return res;
    }

    int lengthOfLongestSubstring(string s)
    {
       vector<bool> A(256,false);
        int n= s.size();
        if(n<=1)
        return n;
        int i=0;A[s[i]]=true;
        string res="", temp="";
        temp.push_back(s[i]);
        i++;
        while(i<n)
        {
           // cout<<"\n i= "<<i;
            if(A[s[i]])
            {
               // cout<<"\n if    "<<A[s[i]]<<" temp = "<<temp<<" s[i] = "<<s[i];
                temp=eras(temp, s[i],A);
                temp.push_back(s[i]);
                if(res.size()<=temp.size())
                    res=temp;
                A[s[i]]=true; // after pushing that character in temp , i am putting true on that character position in A.
            }
            else
            {
               // cout<<"\n else    "<<A[s[i]]<<" temp = "<<temp<<" s[i] = "<<s[i];
                temp.push_back(s[i]);
                if(res.size()<=temp.size())
                    res=temp;
                A[s[i]]=true;// after pushing that character in temp , i am putting true on that character position in A.
            }
            i++;
        }
        return res.size();
    }



int main()
{
    cout<<endl<<lengthOfLongestSubstring("abcabcbb");
    return 0;
}
