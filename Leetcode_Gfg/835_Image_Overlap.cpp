#include<bits/stdc++.h>
using namespace std;

//835. Image Overlap
/*
You are given two images, img1 and img2, represented as binary, square matrices of size n x n. A binary matrix has only 0s and 1s as values.

We translate one image however we choose by sliding all the 1 bits left, right, up, and/or down any number of units. We then place it on top of the other image. We can then calculate the overlap by counting the number of positions that have a 1 in both images.

Note also that a translation does not include any kind of rotation. Any 1 bits that are translated outside of the matrix borders are erased.

Return the largest possible overlap.
*/

// Approach : See copy or video sol. in youtube

 int countOne(vector<vector<int>>& A, vector<vector<int>>& B, int r,int c)
    {
        int cnt = 0;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A.size();j++)
            {
                if((r+i<0 || r+i>=A.size()) ||(c+j<0 || c+j>=A.size()))
                    continue;
                if(A[i][j] + B[i+r][j+c] ==2)
                    cnt++;
            }
        }
        return cnt;
    }

    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B)
    {
        int n=A.size()-1;
        int ans=0;
        for(int row = -n;row<=n;row++)
        {
            for(int col=-n;col<=n;col++)
            {
                ans= max(ans,countOne(A,B,row,col));
            }
        }
        return ans;
    }


int main()
{
   vector<vector<int>> img1 = {{1,1,0},{0,1,0},{0,1,0}}, img2 = {{0,0,0},{0,1,1},{0,0,1}};
   cout<<largestOverlap(img1,img2);
   return 0;
}
