class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    int helper(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int cost=1;
        for(int k=0;k<4;k++){
            int r=i+dx[k];
            int c=j+dy[k];
            if(r>=0 && r<matrix.size() && c>=0 && c<matrix[0].size() && matrix[r][c]>matrix[i][j]){
                cost=max(cost,1+helper(r,c,matrix,dp));
            }
        }
        return dp[i][j]=cost;
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=0,n=matrix.size();
        vector<vector<int>> dp(matrix.size(),vector<int> (matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans=max(ans,helper(i,j,matrix,dp));
            }
        }
        return ans;
    }
};
