class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int sol=nums[0], count=1;
        
        for(int i=1;i<nums.size();i++)
        {
            if( count == 0 )
            {
                sol=nums[i];
                count=1;
            }
            else if( sol == nums[i])
                count++;
            else
                count--;
        }
        return sol;
        
    }
};