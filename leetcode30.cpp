class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(!words.size()) {
            return {};
        }
        vector<int> ans;
        int w = words[0].size(), n = s.size(), m = words.size();
        unordered_map<string, int> word_cnt;
        for(auto x:words) {
            word_cnt[x]++;
        }
        //遍历w组的情况
        for(int i=0; i<w; i++) {
            //对于每一组情况都要维护一个哈希表来记录滑动窗口内所有的字符串
            unordered_map<string, int> range_cnt;
            //记录当前的滑动窗口里符合要求的字符串的个数
            int count = 0;
            for(int j=i; j+m*w<=n; j+=w) {
                //滑动窗口初始化
                if(j == i) {
                    for(int k=0; k<m; k++) {
                        auto str = s.substr(j+k*w, w);
                        if(range_cnt[str] < word_cnt[str]) {
                            count++;
                        }
                        range_cnt[str]++;
                    }
                }
                //随窗口位置移动更新信息
                if(j>i) {
                    auto str = s.substr(j-w, w);
                    range_cnt[str]--;
                    if(word_cnt[str] > range_cnt[str]) {
                        count--;
                    }
                    str = s.substr(j+m*w-w, w);
                    if(range_cnt[str] < word_cnt[str]) {
                        count++;
                    }
                    range_cnt[str]++;
                }
                if(count == m) {
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};

/*作者：lxc656-z
链接：https://leetcode.cn/problems/substring-with-concatenation-of-all-words/solution/leetcode-by-lxc656-z-4vea/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/