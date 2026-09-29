class Solution {
public:
    bool isValid(vector<vector<char>> &board,int n,int x,int y){
        int c=0;
        for(int i=0;i<n;i++){
            if(board[x][i]=='Q') c++;
        }
        if(c>1) return false;
        c=0;
        for(int i=0;i<n;i++){
            if(board[i][y]=='Q') c++;
        }
        if(c>1) return false;
        c=0;
        
        for(int i=x-1,j=y-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }

        for(int i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 'Q')
                return false;
        }

        return true;
    }
    int helper(vector<vector<char>> &board,int n,int cur){
        if(cur>=n){
            return 1;
        }
        int ans=0;
        for(int j=0;j<n;j++){
            board[cur][j]='Q';
            if(isValid(board,n,cur,j)){
                ans+=helper(board,n,cur+1);
            }
            board[cur][j]=' ';
        }
        return ans;
    }
    int totalNQueens(int n) {
        vector<vector<char>> board(n,vector<char> (n,' '));
        return helper(board,n,0);
    }
};