//Longest Common Subsequence
/*
Given two strings text1 and text2, return the length of their longest common subsequence.
If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters
(can be none) deleted without changing the relative order of the remaining characters.

Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
*/

// But this algo is only applicable whin length of strings is not greater than 32 , bcz its time complexity is
// 2^n. So, if n will be greater than 32 than it will show Time Limit Exceeded

#include<bits/stdc++.h>
using namespace std;

 int LCS(string s1, string s2, int i=0, int j=0)
{
    if(i>=s1.size() || j>=s2.size())
        return 0;
    if(s1[i]==s2[j])
        return (1+ LCS(s1,s2,i+1,j+1));
    else
        return max(LCS(s1,s2,i+1,j),LCS(s1,s2,i,j+1));
}

int main()
{
    string s1 = "abcde";
    string s2 = "bde";
    cout<<LCS(s1,s2);
    return 0;
}
