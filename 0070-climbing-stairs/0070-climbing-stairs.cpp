class Solution {
public:
    int climbStairs(int n) {
        
        if(n<=1) return 1;
        
        int prev2=1,prev=1,curr;
        
        for(int i=2;i<=n;i++)
        {
            curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
        
    }
};