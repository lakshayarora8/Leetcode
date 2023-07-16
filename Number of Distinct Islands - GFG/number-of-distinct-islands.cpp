//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    
    void bfs(int row ,int col,vector< vector<int>> &vis,vector< vector<int>> &grid, set<vector<pair<int,int>>> &ans)
    {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col]=1;
        vector<pair<int,int>> level;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            level.push_back({r - row,c -col});
            for(int i=0;i<4;i++)
            {   
                int newrow=r+drow[i];
                int newcol=c+dcol[i];
                
                if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && grid[newrow][newcol]==1 && !vis[newrow][newcol])
                {
                    vis[newrow][newcol]=1;
                    q.push({newrow,newcol});
                }
            }    
        }
        ans.insert(level);
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        
         int m=grid.size();
        int n=grid[0].size();
        
        vector< vector<int>> vis(m,vector<int> (n,0));
        set<vector<pair<int,int>>> ans;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    bfs(i,j,vis,grid,ans);
                }
            }
        }
        return ans.size();
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends