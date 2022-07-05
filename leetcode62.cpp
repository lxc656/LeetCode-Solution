class Solution {
public:
    int uniquePaths(int m, int n) {
        int f[m][n];
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!i && !j) {
                    f[i][j] = 1;
                }
                else if(i == 0) {
                    f[i][j] = f[i][j-1];
                }
                else if(j == 0) {
                    f[i][j] = f[i-1][j];
                }
                else {
                    f[i][j] = f[i-1][j] + f[i][j-1];
                }
            }
        }
        return f[m-1][n-1];
    }
};

/*作者：lxc656-z
链接：https://leetcode.cn/problems/unique-paths/solution/by-lxc656-z-napl/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/