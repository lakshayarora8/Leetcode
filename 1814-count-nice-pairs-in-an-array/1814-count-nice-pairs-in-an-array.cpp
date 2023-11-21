class Solution {
public:
    
    int reverseDigits(int n) 
{ 
        int rem=0,reverse=0;
   while(n!=0)    
  {    
     rem=n%10;      
     reverse=reverse*10+rem;    
     n/=10;    
  }
        
    return reverse;
} 

    int countNicePairs(vector<int>& nums) {
        
            const int MOD = 1000000007;
        unordered_map<int,int> mp;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            int reverse= reverseDigits(nums[i]);
            mp[(nums[i]-reverse)]++;
        }
        
         for (auto it : mp) {
            int pairs = it.second;
            count = (count + (1LL * pairs * (pairs - 1) / 2) % MOD) % MOD;
        }
        
        return count;
        
        
    }
};