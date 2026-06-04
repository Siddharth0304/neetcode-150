class Solution {
public:
    bool pos(string t){
        if(t[0]=='0')
            return false;
        if(t.size()>=3)
            return false;
        if(t.size()==2){
            if(t[0]=='1' || (t[0]=='2' && t[1]<='6'))
                return true;
            else
                return false;
        }
        return true;
    }
    int helper(string s,int idx,vector<int> &dp){
        if(idx==s.size())
            return 1;
        if(dp[idx]!=-1)
            return dp[idx];
        int ways=0;
        for(int i=idx;i<s.size();i++){
            if(pos(s.substr(idx,i-idx+1)))
                ways+=helper(s,i+1,dp);
        }
        return dp[idx]=ways;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return helper(s,0,dp);
    }
};
