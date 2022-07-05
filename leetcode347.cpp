class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(auto x:nums) {
            cnt[x]++;
        }
        int sz = nums.size();
        vector<int> freq(sz+1), ans;
        for(auto [x, c]:cnt) {
            freq[c]++;
        }
        int limit = sz, sum = 0;
        while(sum < k) {
            sum+=freq[limit];
            limit--;
        }
        for(auto [x, c]:cnt) {
            if(c>limit) ans.push_back(x);
        }
        return ans;
    }
};