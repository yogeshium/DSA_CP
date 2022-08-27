#include <bits/stdc++.h>
using namespace std;

int main()
{

    //Aproach 1:
    int search(vector<int>& v, int t) {
        int l = 0, r = v.size() - 1;

        while(l <= r) {
            int m = (l + r) / 2;

            if(v[m] == t)
                return m;

            else if(v[l] <= v[m])
                {
                if(v[l] <= t and t <= v[m])
                    {
                        r = m - 1;
                    }
                else
                    {
                        l = m + 1;
                    }
                }
            else
            {
                if(v[m] <= t and t <= v[r])
                {
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
        }
        return -1;
    }



    //Aproach 2:

     int getPivot(vector<int>& nums)
    {
        int s= 0, e= nums.size()-1;
       int mid = s+(e-s)/2;
         while(s<e)
         {

             if(nums[mid]>= nums[0])
                {
                    s= mid+1;
                }
             else
                {
                    e= mid;
                }
             mid = s+(e-s)/2;
         }
        return s;
    }

    int Bsearch(int s, int e, vector<int>& nums, int k)
    {
        int mid = s+(e-s)/2;
        while(s<=e)
        {
            if(nums[mid]==k)
                return mid;
            else if(nums[mid]>k)
            {
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
         mid = s+(e-s)/2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target)
    {
      int pivot = getPivot(nums);
        if(target>=nums[pivot] && target<=nums.back())
        {
            return Bsearch(pivot, nums.size()-1, nums, target);
        }
        else
        {
            return Bsearch(0, pivot-1, nums, target);
        }
    }

}
