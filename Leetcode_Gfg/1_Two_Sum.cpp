//1. Two Sum
//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

#include<bits/stdc++.h>
using namespace std;

//Approach 1 : (Brute Force)
/*
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> ans;
      int n= nums.size();
      int i=0, j=1;
      while(i<n-1)
      {     j=i+1;
          while(j<n)
          {
            if(nums[i]+nums[j]==target)
            {
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
            j++;
          }
          if(ans.size()!=0)
            break;
            i++;
      }
      return ans;
    }
*/


//Approach 2 : (using hash table)
/*
     vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int,int> mp ;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i])==mp.end())
                mp[nums[i]]=i;
            else
                return {mp[target-nums[i]],i};
        }
        return {-1,-1};
    }
*/
