class Solution {
public:
    bool helper(string &s,set<string> &se,int idx,vector<int> &dp){
        if(idx==s.size())
            return true;
        if(dp[idx]!=-1)
            return dp[idx];
        for(int i=idx;i<s.size();i++){
            if(se.find(s.substr(idx,i-idx+1))!=se.end()){
                if(helper(s,se,i+1,dp))
                    return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> se(wordDict.begin(),wordDict.end());
        vector<int> dp(s.size(),-1);
        return helper(s,se,0,dp);
    }
};
