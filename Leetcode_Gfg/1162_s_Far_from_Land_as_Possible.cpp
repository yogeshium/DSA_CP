//1162. As Far from Land as Possible

#include<bits/stdc++.h>
using namespace std;

//Solution:
/*
Normally, we would run breadth-first search from each cell simultaneonly,
tracking water cells we visited. Sort of like Dijkastra’s algorithm.
However, I wanted to try a depth-first search solution, as it seemed
easier to implement at the time.
*/



//Approach 1 : BFS
/*
 we find our land cells and put surrounding water cells in the queue.
 We mark water cells as visited and continue the expansion from land
 cells until there are no more water cells left.
*/
/*
int maxDistance(vector<vector<int>>& grid)
    {
        queue<pair<int,int>> q;
        int vis[grid.size()][grid.size()];
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                if(grid[i][j]==1)
                {
                    vis[i][j]=1;
                    q.push(make_pair(i,j));
                }
                else
                {
                    vis[i][j]=0;
                }
            }
        }
        if(q.empty() || q.size()==grid.size()*grid.size())
            return -1;

        while(!q.empty())
        {
            pair<int,int> i = q.front();
            q.pop();
            if(i.first-1>=0)
            {
                if(vis[i.first-1][i.second]!=1)
                {
                    grid[i.first-1][i.second]=grid[i.first][i.second]+1;
                    vis[i.first-1][i.second]=1;
                    q.push(make_pair(i.first-1,i.second));
                }
            }
            if(i.second-1>=0)
            {
                if(vis[i.first][i.second-1]!=1)
                {
                    grid[i.first][i.second-1]=grid[i.first][i.second]+1;
                    vis[i.first][i.second-1]=1;
                    q.push(make_pair(i.first,i.second-1));
                }
            }
            if(i.first+1<grid.size())
            {
                if(vis[i.first+1][i.second]!=1)
                {
                    grid[i.first+1][i.second]=grid[i.first][i.second]+1;
                    vis[i.first+1][i.second]=1;
                    q.push(make_pair(i.first+1,i.second));
                }
            }
            if(i.second+1<grid.size())
            {
                if(vis[i.first][i.second+1]!=1)
                {
                    grid[i.first][i.second+1]=grid[i.first][i.second]+1;
                    vis[i.first][i.second+1]=1;
                    q.push(make_pair(i.first,i.second+1));
                }
            }
        }
        int max =-1;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                if(grid[i][j]>max)
                    max = grid[i][j];
            }
        }
        return max-1;
    }

*/



//Approach : DFS
/*
For each 'land' cell, start DFS and record the distance in 'water' cells.
If the distance in the 'water' cell is smaller than the current distance,
we stop there. Otherwise, we update the distance to the smaller value and keep going.
*/
