#include<bits/stdc++.h>
using namespace std;

/*
Approach : (Exactly My Approach)
First task is to check if the string is not a single character, if it is then no answer exists
After this one important fact is to be used, "THE GIVEN STRING IS A PALINDROME"

This makes the takes simpler as any character at a distance x from the beginning
is same as the character at a distance x from the end
Which means we only have to traverse half of the string
So Start the traversal, if a character at the i(th) position is not 'a'

Check if the length is odd and i = length/2

If yes, break the loop (Since our string is like aaaa...*...aaaa), we h=will have to replace the last 'a' with 'b'

Change the character at the position i, to 'a', this works because the character from the end is not same as 'a' (NOW)
Return the manipulated String

If by now, nothing has been returned, the string is either all (a)s or of type
aaaa...*...aaaa, where * can be any character other than 'a' and the length is surely odd for the string of this type

What to do ?
Just change the last 'a' of the string to 'b' and return the string
*/

//Code:
    string breakPalindrome(string p)
    {
        int i=0;
        int len = p.length();
        if(len==1)
            return "";

        for(i=0;i<len/2;i++)
        {
            if(p[i]!='a')
            {
                p[i]='a';
                return p;
            }

        }
        p[len-1]='b';
        return p;
    }

int main()
{

    string s = breakPalindrome("abccba");
    cout<<"\n"<<s;
    return 0;
}
