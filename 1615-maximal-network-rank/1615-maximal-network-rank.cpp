class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
      vector<int>  adj[n];
        
        vector<vector<int>> connected(n,vector<int> (n,0));
        int m=roads.size();
        for(int i=0;i<m;i++)
        {
            int first=roads[i][0];
            int second=roads[i][1];
            connected[first][second]=1;
            connected[second][first]=1;
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        int ans=0,maxnetwork;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                maxnetwork=0;
                if( i == j) continue;
                maxnetwork= adj[i].size() + adj[j].size();
                if( connected[i][j])
                    maxnetwork-=1;
                ans=max(ans,maxnetwork);
                
            }
        }
        
        
        
        return ans;
    }
};