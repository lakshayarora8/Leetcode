class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int start=0,end=nums.size()-1;
        int ans=0;
        while(start<=end)
        {
            ans=max(ans, nums[start++]+ nums[end--]);
        }
        return ans;
        
    }
};