class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(auto it: nums)
        {
            mp[it]++;
        }
        
        for( auto i:mp)
        {
            pair p= make_pair( i.second,i.first);
            pq.push(p);
            if( pq.size() >k )
            {
                pq.pop();
            }
        }
        
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
        
    }
};