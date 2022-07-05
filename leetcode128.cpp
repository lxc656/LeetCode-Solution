class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> exist; //用unordered_map记录某个数值在/不在集合里（底层是用哈希表实现的）
        for(auto x:nums) {
            exist.insert(x);
        }
        for(auto x:nums) {
            if(exist.count(x) && !exist.count(x-1)) { //规定只从一个连续序列的起点开始枚举，因此有!exist.count(x-1)这个谓词
                int length = 0;
                while(exist.count(x)) {
                    length++;
                    exist.erase(x); //防止日后重复枚举x
                    x++;
                }
                ans = max(ans, length);
            }
        }
        return ans;
    }
};