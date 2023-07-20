class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       
        queue<int> q;
        vector<int> indegree(numCourses,0);
        int count=0;
        vector<int> adj[numCourses];
        int size=prerequisites.size();
        for(int i=0;i<size;i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for(int i=0;i<numCourses;i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }
        
        for(int i=0;i<numCourses;i++)
        {
            if( indegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);            
            for( auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
            
        }
        
        if( ans.size() == numCourses)
            return ans;
        vector<int> khaali;
        return khaali;
        
        
        
    }
};