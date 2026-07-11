class Solution {
public:

    bool isSafe(int row, int col, vector<string>& board){
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q'){
                return false;
            }}
        int i = row;
        int j = col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q')
                return false;
                i--;
                j--;
        }
        i=row;
        j=col;
        while(i>=0 && j<board.size()){
            if(board[i][j]=='Q')
                return false;
                i--;
                j++;
        }
        return true;
        
    }

    void solve(int k ,vector<string>&board , vector<vector<string>>& ans,int n){
        if(k==n){
            ans.push_back(board);
            return;
        }
        
        for(int i=0 ; i<board.size();i++){
            if(isSafe(k,i,board)){
                board[k][i]='Q';
                solve(k+1,board,ans,n);
                board[k][i]='.';
                }
        }
        

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        solve(0,board,ans,n);
        return ans;    
    }
};