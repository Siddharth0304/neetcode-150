class Solution {
public:
    int n,m;
    vector<vector<long long>> dp;
    long long helper(vector<vector<int>> &points,int row,int col){
        if(row==n)
            return 0;
        if(dp[row][col+1]!=-1)
            return dp[row][col+1];
        long long ans=0;
        for(int i=0;i<m;i++){
            long long loss=col==-1?0:1LL*abs(i-col);
            ans=max(ans,1LL*points[row][i]-loss+helper(points,row+1,i));
        }
        return dp[row][col+1]=ans;
    }
    long long maxPoints(vector<vector<int>>& points) {
        n=points.size(),m=points[0].size();
        dp.resize(n+1,vector<long long> (m+2,-1));
        return helper(points,0,-1);
    }
};