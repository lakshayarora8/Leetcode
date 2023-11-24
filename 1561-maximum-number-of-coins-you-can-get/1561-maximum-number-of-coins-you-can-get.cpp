class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        sort(piles.begin(),piles.end());
        int n=piles.size()/3;
        int i=piles.size()-2;
        int sum=0;
        while(n--)
        {
            sum+=piles[i];
            i-=2;
        }
        
        return sum;
    }
};