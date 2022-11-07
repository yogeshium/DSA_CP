#include <bits/stdc++.h>
using namespace std;

/*
Basic Idea :

The alphabets in a permutation that is to be searched will always be the same, and so will their count.

The thing that counts in s2 is that each substring has the same number of characters as in s1. As a result,
we make a hashmap that contains the count of each character in the string s1. After that, we slide a window
over the string s2 and lower the number for characters that appear in the window. When all of the counters in
the hashmap reach 0, we've found the permutation.
*/

 bool checkInclusion(string s1, string s2)
    {
       int m= s1.size(), n= s2.size();

       unordered_map<char,int> S;  //Use hashmap to store the frequencies of all the characters present in string s1.
        for(auto it : s1)
        {  S[it]++;}

       int i=0,j=0,ans = S.size();//Use the ans variable to see if all of the characters in the map have the same
                                       // frequency, indicating that an anagram has been found.
       int k= m; //Window Size

       while(j<n)
       {
           if(S.find(s2[j])!=S.end())
           {    //If a character is found that already exists in the map, reduce its frequency by one.
               S[s2[j]]--;

               if(S[s2[j]]==0)
               //If the frequency of a specific character on the map is 0, it means that all occurrences of that
               //character is found inside the current window size.
                    ans--;
           }

           if(j-i+1<k)
                j++;
           else if(j-i+1==k)
           {
               if(ans == 0)
                    return true; // Anagram found

                 //Check if that character is present in the map while sliding the window, then increase its frequency
                 // by one, as we decreased its frequency when we first met it while crossing the window.
               if(S.find(s2[i])!=S.end())
                {
                    S[s2[i]]++;
                    if(S[s2[i]]==1)
                        ans++;
                }
                i++;j++;
           }
       }
    return false;
    }


int main()
{
    if(checkInclusion("abcdxabcde","abcdeabcdx"))
        cout<<"\n\nTrue";
    else
        cout<<"\n\nFalse";
    return 0;
}
