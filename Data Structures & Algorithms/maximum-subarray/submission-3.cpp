class Solution {
public:
    int n;
    vector<vector<long long>> dp;
    long long helper(int idx,vector<int> &nums,int flag){
        if(idx>=n) return flag==0?LLONG_MIN/2:0;
        if(flag==2) return 0;
        if(dp[idx][flag]!=-1e15) return dp[idx][flag];

        long long ans=LLONG_MIN/2;
        if(flag==0)
            ans=max({ans,helper(idx+1,nums,0),nums[idx]+helper(idx+1,nums,1)});
        else 
            ans=max({ans,nums[idx]+helper(idx+1,nums,1),helper(idx+1,nums,2)});
        return dp[idx][flag]=ans;
    }
    int maxSubArray(vector<int>& nums) {
        n=nums.size();
        dp.assign(n,vector<long long> (3,-1e15));
        return helper(0,nums,0);
    }
};
