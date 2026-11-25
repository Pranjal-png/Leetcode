class Solution {
public:

    void dfs(int r , int c , vector<vector<char>>&grid){
        int m = grid.size();
        int n = grid[0].size();

        if(r<0 || c<0 || r>=m || c>=n || grid[r][c]=='0'){
            return;

        }
        grid[r][c]='0';
        dfs(r+1,c,grid);
        dfs(r-1,c,grid);
        dfs(r,c+1,grid);
        dfs(r,c-1,grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans =0;
        for(int r=0 ; r<grid.size() ; r++){
            for(int c=0 ; c<grid[0].size() ; c++){
                if(grid[r][c] == '1'){
                    ans+=1;
                    dfs(r,c,grid);
                }

            }
        }
        
        return ans;
        
        
    }
};