#include<bits/stdc++.h>
using namespace std;

 bool Check(int x, int y, int k, vector<vector<char>>& M, string W)
    {
        if(k==W.size())
            return true;
        if(x<0 || y<0 || x>=M.size()||y>=M[0].size())
            return false;
        //cout<<"\n      "<<M[x][y]<<"  "<<W[k]<<" ";
        if(M[x][y]!=W[k])
            return false;
        char temp = M[x][y];
        M[x][y]='$';
        if(Check(x-1,y,k+1,M,W) ||Check(x+1,y,k+1,M,W) ||Check(x,y-1,k+1,M,W)|| Check(x,y+1,k+1,M,W))
            return true;
        M[x][y]=temp;
        return false;

    }

    bool exist(vector<vector<char>>& board, string word)
    {
       int row = board.size(), col = board[0].size();
       for(int i=0;i<row;i++)
       {
           for(int j=0;j<col;j++)
              {
                  //cout<<"\n Checking : "<<board[i][j]<<" i "<<i<<" j "<<j;
                  if(Check(i,j,0,board, word))
                    return true;
              }
       }
       return false;
    }

int main()
{

   vector<vector<char>> board ={{'A','B','C'},{'S','F','C'},{'A','D','E'}};
   //string word = "ABCCED";

    cout<<exist(board, "SEE");
    return 0;
}
