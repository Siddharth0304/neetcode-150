class Solution {
public:
    int helper(vector<int> &nums,int target,int i,vector<vector<int>> &dp){
        if(i==nums.size())
            return target==0;
        if(dp[i][target]!=-1)
            return dp[i][target];
        int take=0;
        int notTake=helper(nums,target,i+1,dp);
        if(target>=nums[i])
            take=helper(nums,target-nums[i],i+1,dp);
        return dp[i][target]=take+notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int s=0;
        for(auto &it:nums)
            s+=it;
        target=s+target;
        if(target%2==1 || target<0)
            return 0;
        target/=2;
        vector<vector<int>> dp(nums.size(),vector<int> (target+1,-1));
        return helper(nums,target,0,dp);
    }
};
