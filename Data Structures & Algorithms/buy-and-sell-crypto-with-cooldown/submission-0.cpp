class Solution {
public:
    int helper(vector<int> &prices,int i,int f,vector<vector<int>> &dp){
        if(i>=prices.size())
            return 0;
        if(dp[i][f]!=-1)
            return dp[i][f];
        int buy=0,sell=0;
        if(f==1){
            buy=max(helper(prices,i+1,1,dp),-prices[i]+helper(prices,i+1,0,dp));
        }
        else{
            sell=max(helper(prices,i+1,0,dp),prices[i]+helper(prices,i+2,1,dp));
        }
        return dp[i][f]=max(buy,sell);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int> (2,-1));
        return helper(prices,0,1,dp);
    }
};
