#include<bits/stdc++.h>

using namespace std;

//faster Aproach
int findPeakElement(vector<int>& nums) {
        // support variables
        int l = 0, mid, r = nums.size() - 1;
        // edge cases:
        // mono-element input or first element as a peak
        if (!r || nums[0] > nums[1]) return 0;
        // last element as a peak
        if (nums[r - 1] < nums[r]) return r;
        // binary searching the input
        while (l < r) {
            mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1]) {
                if (nums[mid] > nums[mid - 1]) return mid;
                else r = mid;
            }
            else l = mid;
        }
        return -1;
    }


//My aproach
	//same peak in mountain

int main() {
	// Your code goes here;

	return 0;
}