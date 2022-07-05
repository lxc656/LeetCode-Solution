class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hashmap;
        for(auto x:strs) {
            string y = x;
            sort(y.begin(), y.end());
            hashmap[y].push_back(x);
        }
        for(auto x:hashmap) {
            ans.push_back(x.second);
        }
        return ans;
    }
};