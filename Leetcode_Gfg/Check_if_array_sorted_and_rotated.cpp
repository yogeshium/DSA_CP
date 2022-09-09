#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums)
    {
        int i;
      int pair = 0;
        for(i=1;i<nums.size();i++)
        {
            if(nums[i-1]>nums[i])
            {
                pair++;
            }

        }
        if(nums[i-1]>nums[0])
            pair++;

        if(pair>1)
            return false;
        return true;
    }


    int main()
    {
        vector<int> n= {1,2,3,4,5,6};
        cout<<"Answer: "<<check(n);
        return 0;
    }
