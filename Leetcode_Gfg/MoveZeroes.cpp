 #include<bits/stdc++.h>
 using namespace std;


 // My Approach 43ms - 34%   19.3mb
 /*
 void moveZeroes(vector<int>& nums) {

        int i=0,j=0;
        while(i<nums.size() && j<nums.size())
        {
            if(nums[i]!=0)
            {
                i++;
            }
            else if(nums[j] == 0)
                j++;
            else
            {
                if(j>i)
                {
                    int temp = nums[i];
                    nums[i] = nums [j];
                    nums[j] =temp;
                    i++;
                    j++;
                }
                else
                    j++;

            }
        }
    }
*/

   //Faster Approach 30ms - 75.43%   19.2mb
   void moveZeroes(vector<int>& nums)
   {
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                swap(nums[i],nums[count]);
                count++;
            }
        }
    }


    int main()
    {

        vector<int> n= {1,4,5,3,12,0,9,8};
        moveZeroes(n);

        cout<<"Output : ";
        for(int i=0;i<n.size();i++)
            cout<<n[i]<<" ";
    }

