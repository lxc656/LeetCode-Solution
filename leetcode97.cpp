class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size();
        if(s3.size() != l1 + l2) {
            return false;
        }
        s1 = ' ' + s1, s2 = ' ' + s2, s3 = ' '+s3;
        vector<vector<bool>> f(l1+1, vector<bool>(l2+1));
        for(int i=0; i<=l1; i++)
            for(int j=0; j<=l2; j++) {
                if(!i && !j) {
                    f[i][j] = true;
                } else {
                    if(i && s3[i+j] == s1[i]) {
                        f[i][j] = f[i-1][j];
                    }
                    if(j && s3[i+j] == s2[j]) {
                        f[i][j] = f[i][j-1] | f[i][j];
                    }
                }
            }
        return f[l1][l2];            
    }
};