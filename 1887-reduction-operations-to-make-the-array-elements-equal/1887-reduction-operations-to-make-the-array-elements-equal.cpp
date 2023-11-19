class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
       int  sum=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i] != nums[i+1])
            {
                sum+=n-i-1;
            }
        }
        return sum;
    }
};