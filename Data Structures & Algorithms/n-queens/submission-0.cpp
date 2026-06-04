class Solution {
public:
    bool isValid(vector<vector<char>> &board, int r, int c, int n){
        int row=0,col=0,d1=0,d2=0;
        for(int i=0;i<n;i++){
            if(board[r][i]=='Q')
                row++;
        }
        for(int i=0;i<n;i++){
            if(board[i][c]=='Q')
                col++;
        }
        int i=r,j=c;
        while(i>=0 && i<n && j>=0 && j<n){
            if(board[i][j]=='Q')
                d1++;
            i++;
            j++;
        }
        i=r,j=c;
        while(i>=0 && i<n && j>=0 && j<n){
            if(board[i][j]=='Q')
                d1++;
            i--;
            j--;
        }
        i=r,j=c;
        while(i>=0 && i<n && j>=0 && j<n){
            if(board[i][j]=='Q')
                d2++;
            i--;
            j++;
        }
        i=r,j=c;
        while(i>=0 && i<n && j>=0 && j<n){
            if(board[i][j]=='Q')
                d2++;
            i++;
            j--;
        }
        if(row>1 || col>1 || d1>2 || d2>2)
            return false;
        
        return true;
    }
    void dfs(vector<vector<string>> &ans,vector<vector<char>> &board,int n, int i){
        if(i==n){
            vector<string> temp;
            for(auto &it:board){
                string s="";
                for(auto &t: it)
                    s+=t;
                temp.push_back(s);
                s="";
            }
            ans.push_back(temp);
            return;
        }

        for(int j=0;j<n;j++){
            board[i][j]='Q';
            if(isValid(board,i,j,n)){
               dfs(ans,board,n,i+1);
            }
            board[i][j]='.';
        }
        // return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n,vector<char>(n,'.'));
        dfs(ans,board,n,0);
        return ans;
    }
};
