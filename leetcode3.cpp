class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char, int> count;
        for(int r=0, l=0; r<s.size(); r++) {
            count[s[r]]++;
            while(count[s[r]]==2) {
                count[s[l]]--;
                l++;
            }
            if(r-l+1>ans) ans = r-l+1;
        }
        return ans;
    }
};