#include<bits/stdc++.h>
using namespace std;
 int BounceSwap(int& a, int& b)
    {
       int temp;
        temp = b;
        b=a;
        return temp;// returning the element
    }

    void rotate(vector<vector<int>>& matrix)
    {
        int sr=0;//Starting Row
        int er = matrix.size()-1;//Ending Row
        int sc = 0; //Starting column
        int ec = matrix[0].size()-1; //Ending column
        int n=ec, i =0;
        while(sr<er && sc<ec)
        {
            for(i=0;i<n;i++)
            {
               int t = matrix[sr][sr+i];
                t=BounceSwap(t,matrix[sr+i][ec]);
                t= BounceSwap(t,matrix[er][ec-i]);
                t= BounceSwap(t, matrix[er-i][sc]);
                t=BounceSwap(t,matrix[sr][sr+i]);
            }
            sr++;er--;sc++;ec--;n=n-2; //A Layer completed. Now go to below layer.
        }
    }

    int main()
    {
        vector<vector<int>> A = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
        cout<<"\nBefore\n";
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A[0].size();j++)
                cout<<A[i][j]<<" ";
            cout<<"\n";
        }
        rotate(A);
        cout<<"\nAfter\n";
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A[0].size();j++)
                cout<<A[i][j]<<" ";
            cout<<"\n";
        }

        return 0;
    }

    /*
    Lets take 3x3 Matrix. If u notice , after 90 degree rotate, the element in [0][0] is now in [0][2], [0][2] in [2][2] , [2][2] in [2][0] and [2][0] in [0][0] .
Again , u see, [0][1] in [1][2] , [1][2] in [2][1] , [2][1] in [1][0], and [1][0] in [0][1] and so on. Did u noticed?
[0][0] element goes to [0][2] and whatever element in [0][2] goes to [2][2] , whatever in [2][2] goes to [2][0] and whatever in [2][0] in [0][0]. This is like bouncing ball , that's why i call it Bouncing Swap.
We have to perform this Bouncing swap at every Layer of matrix .
First, for the upper layer , we will run BounceSwap for all the elements then for lower layer and so on until we get middle most element (starting row == ending row OR starting column == ending column) or nothing (starting row>ending row OR starting column>ending column).
    */
