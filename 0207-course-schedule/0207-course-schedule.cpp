class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
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
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            count++;
            
            for( auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
            
        }
        
        return count==numCourses;
        
        
        
    }
};