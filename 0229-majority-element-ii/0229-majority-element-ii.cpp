class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        map<int,int> mp;

        vector<int> v;
        int n=nums.size();
        n=floor(n/3);

        for(auto it:nums)
        {
            mp[it]++;
        }

        for(auto it:mp)
        {
            if(it.second > n)
            v.push_back(it.first);
        }

        return v;
        
    }
};