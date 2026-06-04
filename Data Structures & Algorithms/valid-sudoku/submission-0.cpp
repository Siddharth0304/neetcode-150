class Solution {
public:
    bool checkRow(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            set<char> se;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                    continue;
                if(se.find(board[i][j])!=se.end())
                    return false;
                else
                    se.insert(board[i][j]);
            }
        }
        return true;
    }
    bool checkCol(vector<vector<char>>& board){
        for(int j=0;j<9;j++){
            set<char> se;
            for(int i=0;i<9;i++){
                if(board[i][j]=='.')
                    continue;
                if(se.find(board[i][j])!=se.end())
                    return false;
                else
                    se.insert(board[i][j]);
            }
        }
        return true;
    }
    bool checkBox(vector<vector<char>>& board){
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                set<int> se;
                for(int l=i;l<i+3;l++){
                    for(int m=j;m<j+3;m++){
                        if(board[l][m]=='.')
                            continue;
                        if(se.find(board[l][m])!=se.end())
                            return false;
                        else
                            se.insert(board[l][m]);
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool rowWise=checkRow(board);
        bool colWise=checkCol(board);
        bool boxWise=checkBox(board);

        return rowWise && colWise && boxWise;
    }
};
