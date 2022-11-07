#include<bits/stdc++.h>
using namespace std;

/*
If u see in while loop, first i am conducting a operation k (window size) times then after
i am asking whether it conducted that operation k times or not. If yes then i am removing
first element (which is pointed by i) and again conducting that operation;

Actually hum yaha kya kr rhe h ki i and j ko 0 rakh diye. k->(window size) hai. Hum loop
chalate h and j ko badhate jate h (kaam bhi karate jate h) . Hum check bhi kr rhe in every
iteration ki kya window size tk pahuncha through (j-i<k) or (j-i+1<k). Jb tak nahi pahuncha
h tb tk sirf j ko badha rhe.
Jese hi pohonch gya to hum first element jo i point kr rha usko nikalte h and i and j ko ++
kr dete h. Isse kya hoga ki i hamesha shuruat wale element ko point krte rahega and j hamesha
last wali element ko. Or tu sliding window ka concept to janta hi h.
*/

bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int,int> mp;
        int i=0,j=0, n= nums.size();

        //Sliding window technique
        while(j<n)
        {
            if(mp.find(nums[j])!=mp.end())
            { return true;}
            else
            {  mp[nums[j]]++; }

            // From this line we are implementing sliding window
            if(j-i<k)
            {    j++;}
            else
            {
                mp.erase(nums[i]);
                i++;j++;
            }
        }
        return false;
    }

  // Same logic but More Optimized and short Code:-
      bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            // mp.count() will tell whatever ith index that I want, have I seen it before?
            if(mp.count(nums[i]))
            {
                // if I have already seen this number, then check for condition abs(i - j) <= k
                if(abs(i-mp[nums[i]])<=k)
                    return true;
            }
            // if I have not seen this number before, insert the number with its position in the map
            // and if the number is already present in the map, then update the position of that number
            mp[nums[i]] = i;
        }
        // after the complete traversal, if we don't find a pair to satisfy the condition, return false
        return false;
    }





int main()
{
    vector<int>num= {1,2,3,1,1};
    bool flag = containsNearbyDuplicate(num,0);
    if(flag)
        cout<<"True";
    else
        cout<<"False";

    return 0;
}
