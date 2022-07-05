class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        word1 = " " + word1;
        word2 = " " + word2;
        vector<vector<int>> status(l1+1, vector<int>(l2+1, 1e8));
        for(int i=0; i<=l1; i++) status[i][0] = i;
        for(int i=1; i<=l2; i++) status[0][i] = i;
        for(int i=1; i<=l1; i++) {
            for(int j=1; j<=l2; j++) {
                int tmp;
                status[i][j] = status[i-1][j]+1;
                status[i][j] = min(status[i][j-1]+1, status[i][j]);
                if(word1[i] == word2[j]) {
                    tmp = status[i-1][j-1];
                }
                else tmp = status[i-1][j-1]+1;
                status[i][j] = min(status[i][j], tmp);
            }
        }
        return status[l1][l2];
    }
};