class Solution {
public:
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int v=isConnected.size();
        vector<int> adj[v];
        int ans=0;
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(i!=j && isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(v,0);
        
        for(int i=0;i<v;i++)
        {
            if(vis[i] == 0)
            {
                ans++;
                vis[i]=1;
                queue<int> q;
                q.push(i);
                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();
                    
                    for(auto it: adj[node])
                    {
                        if(!vis[it])
                        {
                            vis[it]=1;
                            q.push(it);
                        }
                    }
                }
            }
        }
        
    return ans;
    }
};