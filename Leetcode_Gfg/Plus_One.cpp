#include<bits/stdc++.h>
using namespace std;

//My Aproach 9ms :
/*
 vector<int> plusOne(vector<int>& digits)
    {
        vector<int> ans;
        int carry = 0;
        int i=digits.size()-1;
        int val = digits[i]+1;
        carry = val/10;
        ans.push_back(val%10);
        val = 0;
        i--;
        while(i>=0 && carry !=0)
        {
            val =digits[i] + carry ;
            carry = val/10;
            val = val%10;
            ans.push_back(val);
            i--;
        }
        while(i>=0)
        {  ans.push_back(digits[i]);
            i--;
        }
        while(carry!=0)
        {   val= carry;
            carry = val/10;
            val = val%10;
            ans.push_back(val);
        }
        //reverse
        int p1=0, p2 = ans.size()-1;
        while(p1<p2)
        {
            int temp = ans[p1];
            ans[p1] = ans[p2];
            ans[p2] = temp;
            p1++;p2--;
        }

        return ans;
    }
*/

// 4ms Code Aproach:

    vector<int> plusOne(vector<int>& digits)
    {
        for(int i = digits.size() - 1;i >= 0;i--){
            if(digits[i] != 9){
                digits[i]++;
                return digits;
            }
            else
                digits[i] = 0;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }

    int main()
    {

        vector<int> digits = {1,2,3};
        vector<int> ans = plusOne(digits);

        cout<<"\n Answer : ";
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
    }
