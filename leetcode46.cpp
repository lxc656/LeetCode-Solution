class Solution {
public:
    vector<vector<int>> ans;
    bool bitmap[25];
    vector<vector<int>> permute(vector<int>& nums) {
        for(auto x:bitmap) {
            x = false;
        }
        vector<int> path;
        dfs(nums, 0, path);
        return ans;
    }
    void dfs(vector<int>& nums, int num, vector<int>& path) {
        if(num == nums.size()) {
            ans.push_back(path);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(bitmap[nums[i]+10] == false) {
                path.push_back(nums[i]);
                bitmap[nums[i]+10] = true;
                dfs(nums, num+1, path);
                path.pop_back();
                bitmap[nums[i]+10] = false;
            }
        }
    }
};