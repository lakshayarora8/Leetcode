class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        int maxrows=0;
        unordered_map<int,int> mp;
        for(auto it: nums)
        {
            mp[it]++;
            maxrows=max(maxrows,mp[it]);
        }
        
        vector< vector<int>> ans(maxrows);
        
        
        for( auto it: mp)
        {
            for(int i=0;i< it.second; i++)
            {
                ans[i].push_back( it.first );
            }
            
        }
        
        return ans;
    }
};