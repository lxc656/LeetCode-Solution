//N皇后
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> table;
    vector<bool> row, col, dg, udg;
    vector<vector<string>> solveNQueens(int n) {
        table = vector<string>(n, string(n, '.'));
        row = col = vector<bool>(n, false);
        dg = udg = vector<bool>(2*n+1, false);
        dfs(0, n);
        return ans;
    }
    void dfs(int depth, int n) {
        if(depth==n) {
            ans.push_back(table);
            return;
        }
        for(int i=0; i<n; i++) {
            if(!row[i]&&!col[i]&&!dg[depth-i+n]&&!udg[depth+i]) {
                row[i] = col[i] = dg[depth-i+n] = udg[depth+i] = true;
                table[depth][i] = 'Q';
                dfs(depth+1, n);
                row[i] = col[i] = dg[depth-i+n] = udg[depth+i] = false;
                table[depth][i] = '.';
            }
        }
    }
};