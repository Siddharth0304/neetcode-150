class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }

        int x=n,y=m;
        string s="";
        while(x>0 && y>0){
            if(str1[x-1]==str2[y-1]){
                s.push_back(str1[x-1]);
                x--;
                y--;
            }
            else{ 
                if(dp[x-1][y]>dp[x][y-1]){
                    s.push_back(str1[x-1]);
                    x--;
                }
                else{
                    s.push_back(str2[y-1]);
                    y--;
                }
            }
        }

        while(x>0){
            s.push_back(str1[x-1]);
            x--;
        }

        while(y>0){
            s.push_back(str2[y-1]);
            y--;
        }

        reverse(s.begin(),s.end());
        return s;
    }
};