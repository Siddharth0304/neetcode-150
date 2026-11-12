class Solution {
public:
    int n;
    vector<vector<long long>> dp;
    long long helper(vector<int> &coins,int idx,int amount){
        if(amount==0) return 0;
        if(idx>=n || amount<0) return 1e9;
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        long long take=INT_MAX;
        long long notTake=helper(coins,idx+1,amount);
        if(coins[idx]<=amount)
            take=min(take,1+helper(coins,idx,amount-coins[idx]));
        return dp[idx][amount]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        dp.assign(n,vector<long long> (amount+1,-1));
        sort(coins.rbegin(),coins.rend());
        long long ans=helper(coins,0,amount);
        return ans>=1e9?-1:ans;
    }
};
