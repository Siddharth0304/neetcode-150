class Solution {
public:
    int helper(string word1,string word2,int i,int j,vector<vector<int>> &dp){
        if(j<0)
            return i+1;
        if(i<0)
            return j+1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int cost=1e7;
        if(word1[i]==word2[j])
            cost=min(cost,helper(word1,word2,i-1,j-1,dp));
        else
            cost=min(cost,1+min({helper(word1,word2,i-1,j,dp),helper(word1,word2,i,j-1,dp),helper(word1,word2,i-1,j-1,dp)}));  
        return dp[i][j]=cost;
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,1e7));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0)
                    dp[i][j]=j;
                else if(j==0)
                    dp[i][j]=i;
                else{
                    if(word1[i-1]==word2[j-1])
                        dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                    else
                        dp[i][j]=min(dp[i][j],1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}));
                }
            }
        }
        return dp[n][m];
    }
};
