class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        dfs(path, candidates, target, 0);
        return ans;
    }
    void dfs(vector<int>& path, vector<int>& candidates, int target, int index) {
        if(target == 0) {
            ans.push_back(path);
            return;         
        }
        if(index == candidates.size()) {
            return;
        }
        for(int num=0; num*candidates[index]<=target; num++) {
            for(int i=0; i<num; i++) {
                path.push_back(candidates[index]);
            }
            dfs(path, candidates, target-num*candidates[index], index+1);
            for(int i=0; i<num; i++) {
                path.pop_back();
            }
        }
    }
};

/*作者：lxc656-z
链接：https://leetcode.cn/problems/combination-sum/solution/leet-by-lxc656-z-ypxp/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/