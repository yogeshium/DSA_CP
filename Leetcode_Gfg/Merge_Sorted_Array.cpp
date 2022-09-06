#include <bits/stdc++.h>
using namespace std;

/*
   void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0&&j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[k]=nums1[i];
                i--;
                k--;
            }
            else
            {
                nums1[k]=nums2[j];
                j--;
                k--;
            }
        }
        while(i>=0)
            nums1[k--]=nums1[i--];
        while(j>=0)
            nums1[k--]=nums2[j--];
    }

*/


int main()
{
    vector<int>nums1 = {1,2,5,0,0,0};
    vector<int>nums2 = {3,4,6};
    int m=3, n=3s;

    int j = 0, temp, temp1;
    for(int i = 0; i < (m+n); i++)
    {
        if(j >= n) break;
        if(nums1[i] > nums2[j])
        {
            temp = nums1[i];
            nums1[i] = nums2[j++];
            for(int k = i+1; k < (m+n); k++)
            {
                temp1 = nums1[k];
                nums1[k] = temp;
                temp = temp1;
            }
            continue;
        }
        if(nums1[i] == 0 && i>=m+j)
        {
            nums1[i] = nums2[j++];
        }
    }
    cout<<" Merged Array :";
    for(int i=0;i<nums1.size();i++)
        cout<<nums1[i]<<"  ";
}
