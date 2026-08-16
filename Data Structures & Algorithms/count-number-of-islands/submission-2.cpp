class Solution {
public:
    void dfs(int r, int c, vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        if(r<0 || r>=n || c<0 || c>=m || grid[r][c] == '0') return;

        grid[r][c] = '0';

        dfs(r, c+1, grid);
        dfs(r, c-1, grid);
        dfs(r+1, c, grid);
        dfs(r-1, c, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int cnt = 0;

        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};
