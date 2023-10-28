class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,bool> present,checked;
        
        for(auto it:nums)
        {
            present[it]=true;
        }
        int longest=0,current,start;
        
        for(auto it: nums)
        {
            if(!present[it-1] && !checked[it])
            {
                current=0;
                start=it;
                while(present[start])
                {
                    current++;
                    start++;
                }
                longest=max(longest,current);
                
            }
        }
        return longest;
       
    }
};