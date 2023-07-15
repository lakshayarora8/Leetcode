class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m=mat.size();
        int n=mat[0].size();
        queue<pair< pair<int,int>,int>> q;
        vector< vector<int>> ans(m, vector<int> (n,0));
        
        vector< vector<int>> vis(m, vector<int> (n,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        
        
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int distance=q.front().second;
            
            q.pop();
            
            ans[row][col]=distance;
            for(int i=0;i<4;i++)
            {
                int newrow= row+drow[i];
                int newcol= col+dcol[i];
                
                if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && !vis[newrow][newcol])
                {
                    q.push({{newrow,newcol},distance+1});
                    vis[newrow][newcol]=1;
                }        
                
            }
            
        }
        return ans;
        
    }
};