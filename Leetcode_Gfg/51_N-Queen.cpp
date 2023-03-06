//51. N-Queen

#include<bits/stdc++.h>
using namespace std;

                            //Solution

//Approach 1 : (My approach)

void show(int **chess, int n)
    {
        cout<<endl;
         for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    cout<<chess[i][j]<<" ";
                cout<<"\n";
            }
        cout<<endl;
    }
    void mark(int **chess,int a, int b, int n)
    {
                 //Horizontal
                for(int j=b+1;j<n;j++)
                    chess[a][j]++;
                for(int j=b-1;j>=0;j--)
                    chess[a][j]++;

                //Vertical
                for(int i=a+1;i<n;i++)
                    chess[i][b]++;
                for(int i=a-1;i>=0;i--)
                    chess[i][b]++;

                //Diagonal 1
                for(int i=a+1, j=b+1;i<n && j<n;i++,j++)
                    chess[i][j]++;
                for(int i=a-1, j=b-1; i>=0 && j>=0;i--,j--)
                    chess[i][j]++;

                //Diagonal 2
                for(int i=a+1,j=b-1;i<n && j>=0;i++,j--)
                    chess[i][j]++;
                for(int i=a-1,j=b+1;i>=0 && j<n;i--,j++)
                    chess[i][j]++;
    }

    void unmark(int **chess, int a, int b, int n)
    {
                chess[a][b]=0;
                //Horizontal
                for(int j=b+1;j<n;j++)
                    chess[a][j]--;
                for(int j=b-1;j>=0;j--)
                    chess[a][j]--;

                //Vertical
                for(int i=a+1;i<n;i++)
                    chess[i][b]--;
                for(int i=a-1;i>=0;i--)
                    chess[i][b]--;

                //Diagonal 1
                for(int i=a+1, j=b+1;i<n && j<n;i++,j++)
                    chess[i][j]--;
                for(int i=a-1, j=b-1; i>=0 && j>=0;i--,j--)
                    chess[i][j]--;

                //Diagonal 2
                for(int i=a+1,j=b-1;i<n && j>=0;i++,j--)
                    chess[i][j]--;
                for(int i=a-1,j=b+1;i>=0 && j<n;i--,j++)
                    chess[i][j]--;
    }

    void solve(int **mat, int a, int n, vector<vector<string>>& result)
    {
        //Base Case (vese iska use nahi hai)
        if(a>=n)
            return;

        for(int b=0;b<n;b++)
        {
            if(mat[a][b]==0)
            {
                //Mark the queen place
                mat[a][b]=-1;

                if(a==n-1)  //Store Answer
                {
                    cout<<"\n Final: ";show(mat,n);
                    vector<string> ans;
                    for(int i=0;i<n;i++)
                    {
                        string s="";
                        for(int j=0;j<n;j++)
                        {
                            if(mat[i][j]==-1)
                                s.push_back('Q');
                            else
                                s.push_back('.');
                        }
                        ans.push_back(s);
                    }
                    result.push_back(ans);
                }

                // Mark krdo attack area
                mark(mat,a,b,n);

                //Recursive call
                solve(mat,a+1,n,result);

                //Unmark krdo attack area
                unmark(mat,a,b,n);
            }
        }
    }

    //Main Functions
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;
        int **chess = new int*[n];
        for(int i=0;i<n;i++)
            chess[i]= new int[n];

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                chess[i][j]=0;

        solve(chess,0, n, result);
        return result;
    }


//Approach 2: (obtimize)
/*

*/
