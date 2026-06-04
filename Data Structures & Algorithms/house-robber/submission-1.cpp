class Solution {
public:
    int helper(vector<int> &nums,int i,vector<int>& dp){
        if(i>=nums.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int a=helper(nums,i+1,dp);
        int b=nums[i]+helper(nums,i+2,dp);
        return dp[i]=max(a,b);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+2,0);
        for(int i=n-1;i>=0;i--){
            dp[i]=max(dp[i+1],nums[i]+dp[i+2]);
        }
        return dp[0];
    }
};
