class Solution {
    private:
     void bfs(int row ,int col,vector< vector<int>> &vis,vector< vector<char>> &grid)
     {
         vis[row][col]=1;
         queue<pair<int,int>> q;
         q.push({row,col});
         row=grid.size();
         col=grid[0].size();
         while(!q.empty())
         {
             int i=q.front().first;
             int j=q.front().second;
            q.pop();
             
             if (i - 1 >= 0 && i - 1 < row && j >= 0 && j < col && !vis[i - 1][j] && grid[i - 1][j] == '1') {
                q.push({i - 1, j});
                vis[i - 1][j] = 1;
            }
            if (i >= 0 && i < row && j + 1 >= 0 && j + 1 < col && !vis[i][j + 1] && grid[i][j + 1] == '1') {
                q.push({i, j + 1});
                vis[i][j + 1] = 1;
            }
            if (i + 1 >= 0 && i + 1 < row && j >= 0 && j < col && !vis[i + 1][j] && grid[i + 1][j] == '1') {
                q.push({i + 1, j});
                vis[i + 1][j] = 1;
            }
            if (i >= 0 && i < row && j - 1 >= 0 && j - 1 < col && !vis[i][j - 1] && grid[i][j - 1] == '1') {
                q.push({i, j - 1});
                vis[i][j - 1] = 1;
            }
         }
     }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        int cnt=0;
        vector< vector<int>> vis(row, vector<int> (col,0));
        for(int i=0;i<row;i++)
        {
            
            for(int j=0;j<col;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        
        return cnt;
    }
};