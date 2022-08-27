#include <bits/stdc++.h>
using namespace std;

int main()
{

}
// My Code Solution :
 int pivotIndex(vector<int>& nums) {

        int i,presum1=0,presum2=0;
        for(int i=1;i<nums.size();i++)
            presum2= presum2+nums[i];

        if(presum1==presum2)
            return 0;

        for(i=1;i<nums.size();i++)
        {
            presum1= presum1 + nums[i-1];
            presum2= presum2 - nums[i];
            if(presum1 == presum2)
                return i;
        }
            return -1;
    }

// Fastest Code Solution :

 int pivotIndex(vector<int>& nums) {
        // Initialize rightSum to store the sum of all the numbers strictly to the index's right...
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        // Initialize leftSum to store the sum of all the numbers strictly to the index's left...
        int leftSum = 0;
        // Traverse all elements through the loop...
        for (int idx = 0; idx < nums.size(); idx++) {
            // subtract current elements with from rightSum...
            rightSum -= nums[idx];
            // If the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right...
            if (leftSum == rightSum)
                return idx;     // Return the pivot index...
            // add current elements with leftSum...
            leftSum += nums[idx];
        }
        return -1;
