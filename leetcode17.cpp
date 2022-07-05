//题解链接：https://leetcode.cn/problems/letter-combinations-of-a-phone-number/solution/leet-by-lxc656-z-oeuy/
class Solution {
public:
    vector<string> ans;
    vector<string> map = {
        "", "",  //故意设置的无效映射
        "abc", "def", "ghi",
        "jkl", "mno", "pqrs",
        "tuv", "wxyz"
    };
    vector<string> letterCombinations(string digits) {
        dfs_traverse(digits, 0, "");
        return ans;
    }
    //dht means "digits have traversed"
    void dfs_traverse(string digits, int dht, string path) {
        if(digits.size() == 0) {
            return;
        } else if(dht == digits.size()) {
            ans.push_back(path);
            return;
        } else {
            int index = digits[dht]-'0';
            for(auto digit:map[index]) {
                dfs_traverse(digits, dht+1, path+digit);
            }
        }
    }
};