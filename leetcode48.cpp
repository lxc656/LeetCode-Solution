class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0, k=matrix.size()-1; j<k; j++, k--) {
                swap(matrix[i][j], matrix[i][k]);
            }
        }
    }
};

/*作者：lxc656-z
链接：https://leetcode.cn/problems/rotate-image/solution/leetcode-by-lxc656-z-jnwc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/