class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> vis(row, vector<int> (col,0));
        
        queue< pair<pair<int,int>,int>> q;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int t,tm=0;
            while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
             t=q.front().second;
                tm=max(tm,t);
                q.pop();
                
            for(int i=0;i<4;i++)
            {
                int newrow=r+drow[i];
                int newcol=c+dcol[i];
                
     if(newrow>=0 && newrow<row && newcol<col && newcol>=0 && grid[newrow][newcol]==1 && !vis[newrow][newcol] )
     {
         q.push({{newrow,newcol},t+1});
         vis[newrow][newcol]=1;
     }
   
            }
            
            
        }    
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                    return -1;
            }
        }
        return tm;
    }
};