class Solution {
public:
    bool exi(vector<vector<char>>& board, string word, int p,int i,int j,int n,int m){
        if(i>=n || i<0 || j>=m || j<0 || board[i][j]!=word[p])
            return false;
        if(p==word.size()-1)
            return true;
        board[i][j]='#';
        if(exi(board,word,p+1,i-1,j,n,m) ||
           exi(board,word,p+1,i+1,j,n,m) ||
           exi(board,word,p+1,i,j-1,n,m) ||
           exi(board,word,p+1,i,j+1,n,m) 
        )
            return true;
        board[i][j]=word[p];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(exi(board,word,0,i,j,n,m))
                        return true;
                }
            }
        }
        return false;
    }
};
