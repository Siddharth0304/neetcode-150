class Solution {
public:
    int helper(string text1,string text2,int n,int m,vector<vector<int>> &dp){
        if(n==-1 || m==-1)
            return 0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        int cost=0;
        if(text1[n]==text2[m])
            cost=1+helper(text1,text2,n-1,m-1,dp);
        else
            cost=max(helper(text1,text2,n-1,m,dp),helper(text1,text2,n,m-1,dp));
        return dp[n][m]=cost;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return helper(text1,text2,n-1,m-1,dp);
    }
};
