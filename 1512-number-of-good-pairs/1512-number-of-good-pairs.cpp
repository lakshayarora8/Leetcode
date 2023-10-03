class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        
        for(auto it:nums)
        {
            mp[it]++;
        }
        
        int sum=0;
        
        for(auto it:mp)
        {
            if(it.second>=2)
                sum+= ((it.second)*(it.second-1))/2;
        }
        
        return sum;
    }
};