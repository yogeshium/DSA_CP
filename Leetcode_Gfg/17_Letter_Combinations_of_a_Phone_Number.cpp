#include<bits/stdc++.h>
using namespace std;

 vector<string> Alphabets = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void Combine(string In, int i, vector<string>& Out,string temp)
    {
        //Base Case
        if(i>=In.length())
        {
            Out.push_back(temp);
            return;
        }

        int number= In[i]-'0';
        int len = Alphabets[number-2].length();
        for(int j=0;j<len;j++)
        {
            temp.push_back(Alphabets[number-2][j]);
            Combine(In, i+1, Out, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if(digits.length()<1)
            return {};
        vector<string>output ;

        Combine(digits,0,output,"");
        return output;
    }


    int main()
    {
        vector<string> A=letterCombinations("345");
        for(int i=0;i<A.size();i++)
            cout<<A[i]<<" ";

            return 0;
    }
