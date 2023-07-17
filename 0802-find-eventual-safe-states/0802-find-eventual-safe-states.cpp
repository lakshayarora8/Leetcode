class Solution {
    private: 
    
    bool dfs(int node,vector<vector<int>>& graph,vector<int> &vis,vector<int> &pathvis,vector<int> &ans)
    {
        vis[node]=1;
        pathvis[node]=1;
        
        for(auto it: graph[node])
        {
            if(!vis[it])
            {
               if( dfs(it,graph,vis,pathvis,ans) == true)
                  return true;
            }
            else if( pathvis[it])
            {
                
                return true;
            }
        }
        
        
        pathvis[node]=0;
        return false;
        
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int size=graph.size();
        
vector<int> vis(size,0);
        vector<int> pathvis(size,0);

        

        vector<int> ans;
        for(int i=0;i<size;i++)
        {
            if(!vis[i])
            {
                dfs(i,graph,vis,pathvis,ans);
            }
            
        }
        
        for(int i=0;i<pathvis.size();i++)
                {
                    if(pathvis[i]==0)
                    ans.push_back(i);
                }
        
        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};