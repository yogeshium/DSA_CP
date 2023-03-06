//37. Sudoku Solver

#include<bits/stdc++.h>
using namespace std;

//Solution

bool checkRCB(vector<vector<char>>& board,int r, int c, int n)
    {
        //row
        for(int i=0;i<board.size();i++)
        {
            if(board[r][i]=='1'+n)
                return true;
        }
        //col
        for(int i=0;i<board.size();i++)
        {
            if(board[i][c]=='1'+n)
                return true;
        }

        //box
        int R=(r/3)*3;
        int C=(c/3)*3;
        for(int i=R;i<R+3;i++)
        {
            for(int j=C;j<C+3;j++)
            {
                if(board[i][j]=='1'+n)
                    return true;
            }
        }
        return false;
    }

    bool solve(vector<vector<char>>& board, int i, int j)
    {
        if(j>=board.size())
        {
            i++;j=0;
        }
        if(i>=board.size())
            return true;

        if(board[i][j]!='.')
            return solve(board,i,j+1);

        for(int n=0;n<9;n++)
        {
            if(!checkRCB(board,i,j,n))
            {
                board[i][j]='1'+n;

                if(solve(board,i,j+1))
                    return true;

                board[i][j]='.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board)
    {
        solve(board,0,0);
    }

int main()
{
    vector<vector<char>> board ;
    vector<char> c1 = {'5','3','.','.','7','.','.','.','.'};
    vector<char> c2 ={'6','.','.','1','9','5','.','.','.'};
    vector<char> c3 ={'.','9','8','.','.','.','.','6','.'};
    vector<char> c4 ={'8','.','.','.','6','.','.','.','3'};
    vector<char> c5 ={'4','.','.','8','.','3','.','.','1'};
    vector<char> c6 ={'7','.','.','.','2','.','.','.','6'};
    vector<char> c7 ={'.','6','.','.','.','.','2','8','.'};
    vector<char> c8 ={'.','.','.','4','1','9','.','.','5'};
    vector<char> c9 ={'.','.','.','.','8','.','.','7','9'};

    board.push_back(c1);
    board.push_back(c2);
    board.push_back(c3);
    board.push_back(c4);
    board.push_back(c5);
    board.push_back(c6);
    board.push_back(c7);
    board.push_back(c8);
    board.push_back(c9);

    solveSudoku(board);
}
