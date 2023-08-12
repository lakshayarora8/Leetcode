class Solution {
public:

int uniquePathsWithObstacles(vector<vector<int>>& ob) {
    int m = ob.size();
    int n = ob[0].size();
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    dp[0][1] =1;
    for(int i =1;i<m+1;i++){
        for(int j =1;j<n+1;j++){
              if(ob[i-1][j-1] ==0){
                dp[i][j] = dp[i][j-1]+dp[i-1][j];
            }else{
                  dp[i][j] = 0;
              }
        }
    }
    return dp[m][n];
}
};