class Solution {
public:
    bool helper(vector<int> &nums,int i,int tot,vector<vector<int>> &dp){
        if(tot==0)
            return true;
        if(i==nums.size())
            return false;
        if(dp[i][tot]!=-1)
            return dp[i][tot];
        int take=false;
        if(tot>=nums[i])
            take=helper(nums,i+1,tot-nums[i],dp);
        int notTake=helper(nums,i+1,tot,dp);
        return dp[i][tot]=take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        int tot=0;
        for(auto &it:nums)
            tot+=it;
        if(tot%2==1)
            return false;
        tot/=2;
        vector<vector<int>> dp(nums.size(),vector<int> (tot+1,-1));
        return helper(nums,0,tot,dp);
        
    }
};
