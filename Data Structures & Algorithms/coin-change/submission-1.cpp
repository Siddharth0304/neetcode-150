class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,1e8));
        for(int i=n;i>=0;i--){
            for(int j=0;j<=amount;j++){
                if(j==0){
                    dp[i][j]=0;
                    continue;
                }
                if(i==n)
                    continue;
                dp[i][j]=dp[i+1][j];
                if(j>=coins[i])
                    dp[i][j]=min(dp[i][j],1+dp[i][j-coins[i]]);
            }
        }
        if(dp[0][amount]==1e8)
            return -1;
        return dp[0][amount];
    }
};
