class Solution {
public:
    bool helper(string s1,string s2,string s3,int i,int j,int k,int flag,vector<vector<vector<vector<int>>>> &dp){
        if(k==s3.size())
            return true;
        if(i>=s1.size()){
            return s2.substr(j)==s3.substr(k);
        }
        if(j>=s2.size()){
            return s1.substr(i)==s3.substr(k);
        }
        if(dp[i][j][k][flag]!=-1)
            return dp[i][j][k][flag];
        if(flag==0){
            for(int u=i;u<s1.size();u++){
                if(s1[u]==s3[k])
                    if(helper(s1,s2,s3,u+1,j,k+1,0,dp) || helper(s1,s2,s3,u+1,j,k+1,1,dp))
                        return dp[i][j][k][flag]=true;
            }
        }
        else{
            for(int u=j;u<s2.size();u++){
                if(s2[u]==s3[u+i])
                    if(helper(s1,s2,s3,i,u+1,k+1,1,dp) || helper(s1,s2,s3,i,u+1,k+1,0,dp))
                        return dp[i][j][k][flag]=true;
            }
        }
        return dp[i][j][k][flag]=false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
            return false;
        vector<vector<vector<vector<int>>>> dp(s1.size(),vector<vector<vector<int>>>(s2.size(),vector<vector<int>>(s3.size(),vector<int>(2, -1))));
        return helper(s1,s2,s3,0,0,0,0,dp)||helper(s1,s2,s3,0,0,0,1,dp);
    }
};
