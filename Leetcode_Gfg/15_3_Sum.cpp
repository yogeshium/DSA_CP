//15. 3Sum
//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

#include<bits/stdc++.h>
using namespace std;

//Approach 1: (brute force)  (308/311 - testcases passed)
/*
     vector<vector<int>> threeSum(vector<int>& nums)
    {
        set<vector<int>> us;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                for(int k=j+1;k<nums.size();k++)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                       vector<int> temp;
                       temp.push_back(nums[i]);
                       temp.push_back(nums[j]);
                       temp.push_back(nums[k]);

                       sort(temp.begin(),temp.end());//sort karo iss triplet ko

                       us.insert(temp);//Ab store karo
                       //Sort krke insert kr rhe tabhi ye unique triplets rakh payega. Ab aesa kyu hai ye pta nahi.
                    }
                }
            }
        }

        set<vector<int>> :: iterator itr;
        vector<vector<int>> ans;
        for(itr = us.begin();itr!= us.end();itr++)
        {
           ans.push_back(*itr);
        }
        return ans;
    }
*/



//Approach 2 : (Better) (Two Pointer)
/*
     vector<vector<int>> threeSum(vector<int>& nums)
    {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++)
        {
            if(hash.find(nums[i])==hash.end())
            {
                hash[nums[i]]=1;
            }
            else
            {
                hash[nums[i]]++;
            }
        }
        set<vector<int>> us;
        for(int i=0;i<nums.size();i++)
        {
            hash[nums[i]]--;
            for(int j=i+1;j<nums.size();j++)
            {
                hash[nums[j]]--;int k=-(nums[i]+nums[j]);
                if(hash.find(k)!=hash.end())
                {
                    if(hash[-(nums[i]+nums[j])]!=0)
                     {
                         vector<int> temp;
                        if(nums[i]>nums[j])
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(k);
                        sort(temp.begin(),temp.end());
                        us.insert(temp);
                     }

                }

                hash[nums[j]]++;
            }
            hash[nums[i]]++;
        }
        set<vector<int>> :: iterator itr;
        vector<vector<int>> ans;
        for(itr = us.begin();itr!= us.end();itr++)
        {
           ans.push_back(*itr);
        }
        return ans;
    }
*/


//Approach 3 : (Optimal)
/*
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int a=0;
        while(a<nums.size())
        {
            int i=a+1, j=nums.size()-1;
            while(i<j)
            {
                if(nums[i]+nums[j]<(-1*nums[a]))
                    i++;
                else if(nums[i]+nums[j]> (-1*nums[a]))
                    j--;
                else
                {
                    ans.push_back({nums[a],nums[i],nums[j]});
                    int b=nums[i], c= nums[j];
                    while(nums[i]==b && i<j){i++;}// to jump over duplicate i
                    while(nums[j]==c && i<j){j--;}// to jump over duplicate j
                }
            }
            int na = nums[a];
            while(a<nums.size()) // to jump over duplicate a
            {
                if(nums[a]==na)
                    a++;
                else
                    break;
            }
        }
        return ans;
    }
*/

