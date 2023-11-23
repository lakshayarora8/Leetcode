class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int left=0,right=nums.size()-1,l=right;
        vector<int> ans(nums.size());
        
        while(left <= right)
        {
            if( abs(nums[left]) >= abs(nums[right]))
            {
                ans[l--]=nums[left]*nums[left];
                left++;
            }
            else
            {
                ans[l--]=nums[right]*nums[right];
                right--;
            }
        }
        
        return ans;
        
    }
};