class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[sum]=1;
        for(int i=0;i<nums.size();i++)
        {
            if( nums[i]%2 ==1 )
                sum+=1;
            
            if( mp[sum-k])
                ans+= mp[sum-k];
            
            mp[sum]++;  
        }
        
        return ans;
    }
};