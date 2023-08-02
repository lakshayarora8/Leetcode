class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(vector<int>& nums,vector<int> &ds,unordered_map<int,int> mp)
    {
        if(ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i< nums.size();i++)
        {
            if(!mp[i])
            {
                ds.push_back(nums[i]);
                mp[i]=1;
                helper(nums,ds,mp);
                mp[i]=0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> ds;
        unordered_map<int,int> mp;
        helper(nums,ds,mp);
        return ans;
        
    }
};