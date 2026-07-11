class Solution {
public:

    bool isSafe(int row,int col ,int digit,vector<vector<char>>& board){
        int startrow = (row/3)*3;
        int startcol = (col/3)*3;
        for(int i=0;i<9;i++){
            if(board[row][i]==digit){
                return false;
            }
            if(board[i][col]==digit){
                return false;
            }
        }
        for(int i=startrow;i<startrow+3;i++){
            for(int j=startcol;j<startcol+3;j++){
                if(board[i][j]==digit){
                    return false;
                }
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char digit='1';digit<='9';digit++){
                        if(isSafe(i,j,digit,board)){
                            board[i][j]=digit;
                            if(solve(board)){
                                return true;
                            }
                            board[i][j]='.';
                            
                        }
                    }
                    return false;
                }
            }
            
        }
        return true;

    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        
    }
};