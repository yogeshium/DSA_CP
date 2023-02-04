//84. Largest Rectangle in Histogram
#include<bits/stdc++.h>
using namespace std;


//Brute Force :
/*
int largestRectangleArea(vector<int>& A)
    {
        int area = 0;
        for(int i=0;i<A.size();i++)
        {
            int len=A[i],b=1;
            int left=i-1, right=i+1;
            while(left>=0)
            {
                if(A[left]>=len)
                {left--;b++;}
                else
                 break;
            }
            while(right<A.size())
            {
                if(A[right]>=len)
                {right++;b++;}
                else
                    break;
            }
            //cout<<A[i]<<" "<<b<<" "<<len*b<<endl;
            if(area<len*b)
                area= len*b;
        }
        return area;
    }
*/

//Approach 2 : Using Stack
/*
    void prevSmaller(vector<int> A, vector<int>& L)
    {
        stack<int> s;s.push(-1);
        for(int i=0;i<A.size();i++)
        {
            if(s.top()!=-1)
            {
                while(A[s.top()]>=A[i])
                {
                    s.pop();
                    if(s.top()==-1)
                        break;
                }
            }
            L[i] = s.top();
            s.push(i);
        }
    }
    void nextSmaller(vector<int> A, vector<int>& R)
    {
        stack<int> s;s.push(A.size());
        for(int i=A.size()-1;i>=0;i--)
        {
            if(s.top()!=A.size())
            {
                while(A[s.top()]>=A[i])
                {
                    s.pop();
                    if(s.top()==A.size())
                        break;
                }
            }
            R[i] = s.top();
            s.push(i);
        }
    }

    int largestRectangleArea(vector<int>& A)
    {
        vector<int> L(A.size());
        prevSmaller(A,L);
        vector<int> R(A.size());
        nextSmaller(A,R);


        for(int i=0;i<L.size();i++)
            cout<<L[i]<<" ";
        cout<<"\n";
        for(int i=0;i<R.size();i++)
            cout<<R[i]<<" ";

        int res=0;
        for(int i=0;i<A.size();i++)
        {
            int area= (R[i]-L[i]-1)*A[i];
            if(res<area)
                res= area;

        }
        return res;
    }
*/



//Approach 3 : (Divide and Conquer)
/*
The idea is simple: for a given range of bars, the maximum area can either
from left or right half of the bars, or from the area containing the middle
two bars. For the last condition, expanding from the middle two bars to find
a maximum area is O(n), which makes a typical Divide and Conquer solution with
T(n) = 2T(n/2) + O(n).
Thus the overall complexity is O(nlgn) for time and O(1) for space (or O(lgn)
considering stack usage).
*/

/*
int maxCombineArea(const vector<int> &height, int s, int m, int e) {
        // Expand from the middle to find the max area containing height[m] and height[m+1]
        int i = m, j = m+1;
        int area = 0, h = min(height[i], height[j]);
        while(i >= s && j <= e) {
            h = min(h, min(height[i], height[j]));
            area = max(area, (j-i+1) * h);
            if (i == s) {
                ++j;
            }
            else if (j == e) {
                --i;
            }
            else {
                // if both sides have not reached the boundary,
                // compare the outer bars and expand towards the bigger side
                if (height[i-1] > height[j+1]) {
                    --i;
                }
                else {
                    ++j;
                }
            }
        }
        return area;
    }
    int maxArea(const vector<int> &height, int s, int e) {
        // if the range only contains one bar, return its height as area
        if (s == e) {
            return height[s];
        }
        // otherwise, divide & conquer, the max area must be among the following 3 values
        int m = s + (e-s)/2;
        // 1 - max area from left half
        int area = maxArea(height, s, m);
        // 2 - max area from right half
        area = max(area, maxArea(height, m+1, e));
        // 3 - max area across the middle
        area = max(area, maxCombineArea(height, s, m, e));
        return area;
    }
    int largestRectangleArea(vector<int> &height) {
        if (height.empty()) {
            return 0;
        }
        return maxArea(height, 0, height.size()-1);
    }
*/
