/*
题解链接:
https://leetcode.cn/problems/regular-expression-matching/solution/leetcode10-by-lxc656-z-wkp0/
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> f(n+1, vector<bool>(m+1));
        s = ' '+s, p = ' '+p;
        f[0][0] = true; //边界条件，空串自然匹配
        for(int i=0; i<=n; i++) {
            for(int j=1; j<=m; j++) { //字符串p为空时肯定不能匹配
                if(j+1<=m && p[j+1]=='*') {
                    continue;
                } else {
                    if(p[j] == '*') {
                        f[i][j] = f[i][j-2] || 
                        (i>=1 && j>=2) && f[i-1][j] && (s[i]==p[j-1] || p[j-1] == '.');
                    }
                    if(i>=1 && j>=1 && p[j] != '*') {
                        f[i][j] = f[i-1][j-1] && (s[i] == p[j] || p[j] == '.');
                    }
                }
            }
        }
        return f[n][m];
    }
};