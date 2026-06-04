class Solution {
public:
    int helper(vector<int> &coins,int amount,int i,vector<vector<int>> &dp){
        if(i==coins.size())
            return 1e8;
        if(amount==0)
            return 0;
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        int a=helper(coins,amount,i+1,dp);
        int b=1e8;
        if(amount>=coins[i])
            b=1+helper(coins,amount-coins[i],i,dp);
        return dp[i][amount]=min(a,b);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int minCoins=helper(coins,amount,0,dp);
        if(minCoins==1e8)
            return -1;
        return minCoins;
    }
};
