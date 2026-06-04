class Solution {
public:
    bool isValid(vector<string> &board, int r, int c, int n){
        for(int i=r-1;i>=0;i--)
            if(board[i][c]=='Q') return false;
        
        for(int i=r-1,j=c-1; i>=0 && j>=0; i--,j--)
            if (board[i][j]=='Q') return false;
        
        for (int i=r-1,j=c+1; i>=0 && j<board.size(); i--,j++) 
            if(board[i][j]=='Q') return false;
        
        return true;
    }
    void dfs(vector<vector<string>> &ans,vector<string> &board,int n, int i){
        if(i==n){
            ans.push_back(board);
            return;
        }

        for(int j=0;j<n;j++){
            board[i][j]='Q';
            if(isValid(board,i,j,n)){
               dfs(ans,board,n,i+1);
            }
            board[i][j]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n,'.'));
        dfs(ans,board,n,0);
        return ans;
    }
};
