class Solution {
public:
    const int MOD=1e9 +7;
    int solve(int ind, int currMax, int currCost,int n, int m, int k,vector<vector<vector<int>>>& dp ){
        
        if(currCost>k)return 0;
        if(ind == n){
            if(currCost == k){
                return 1;
            }return 0;
        }        
        if(dp[ind][currMax][currCost]!=-1) return dp[ind][currMax][currCost];
        int ans=0;
        for(int i=1;i<=m;i++){
            if(i>currMax){
                ans+=solve(ind+1,i,currCost+1,n,m,k,dp);     //we keep the check directly by comparing the current number with the till now maximum number 
            }else{
                ans+=solve(ind+1,currMax,currCost,n,m,k,dp);
            }
            ans=ans%MOD;
        }

        return dp[ind][currMax][currCost]= ans;
    }
    int numOfArrays(int n, int m, int k) {

        //index , current MAX, currentCost, n, m, k

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));

        return solve(0,0,0,n,m,k,dp);
        
    }
};