class Solution {
public:
    bool helper(int i,int j,string s,string p,vector<vector<int>> &dp){
        if(i>=s.size() && j>=p.size())
            return true;
        if(j>=p.size())
            return false;
        if(i>=s.size()){
            while(j+1<p.size() && p[j+1]=='*')
                j+=2;
            return j>=p.size();
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        bool ans=false;
        if(j+1<p.size() && p[j+1]=='*'){
            if(s[i]==p[j] || p[j]=='.')
                ans=helper(i+1,j,s,p,dp) || helper(i,j+2,s,p,dp);
            else
                ans=helper(i,j+2,s,p,dp);
        }
        else if(s[i]==p[j] || p[j]=='.')
            ans=helper(i+1,j+1,s,p,dp);
        return dp[i][j]=ans;
    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return helper(0,0,s,p,dp);
    }
};
