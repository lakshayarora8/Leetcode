class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int total=0,boundary=0;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        
        vector< vector<int>> vis(m,vector<int> (n,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    total++;
                    if( i== 0 || i==m-1 || j==0 || j==n-1)
                    {
                        vis[i][j]=1;
                        boundary++;
                        q.push({i,j});
                    }
                }
            }
        }
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {   
                int newrow=row+drow[i];
                int newcol=col+dcol[i];
                
                if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && grid[newrow][newcol]==1 && !vis[newrow][newcol])
                {
                    vis[newrow][newcol]=1;
                    q.push({newrow,newcol});
                    boundary++;
                }
            }    
        }
        
        return total-boundary;
    }
};