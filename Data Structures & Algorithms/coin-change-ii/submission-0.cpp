class Solution {
public:
    int helper(vector<int> &coins,int amount,int i,vector<vector<int>> &dp){
        if(amount==0)
            return 1;
        if(i==coins.size())
            return 0;
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        int notTake=helper(coins,amount,i+1,dp);
        int take=0;
        if(amount>=coins[i]){
            take=helper(coins,amount-coins[i],i,dp);
        }
        return dp[i][amount]=take+notTake;
        
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        return helper(coins,amount,0,dp);
    }
};
