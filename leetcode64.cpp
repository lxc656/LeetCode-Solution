class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f(m, vector<int>(n, 0x3f3f3f3f));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!i && !j) {
                    f[i][j] = grid[i][j];
                }
                else if(!i) {
                    f[i][j] = f[i][j-1] + grid[i][j];
                }
                else if(!j) {
                    f[i][j] = f[i-1][j] + grid[i][j];
                }
                else {
                    f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
                }
            }
        }
        return f[m-1][n-1];
    }
};