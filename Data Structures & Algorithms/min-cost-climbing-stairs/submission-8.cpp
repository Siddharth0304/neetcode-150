class Solution {
public:
    int helper(vector<int> &cost,int i,vector<int> &dp){
        if(i>=cost.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        return dp[i]=cost[i]+min(helper(cost,i+1,dp),helper(cost,i+2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,0);
        dp[n-1]=cost[n-1];
        for(int i=n-2;i>=0;i--){
            dp[i]=cost[i]+min(dp[i+1],dp[i+2]);
        }
        return min(dp[0],dp[1]);
    }
};
