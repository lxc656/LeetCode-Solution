class Solution {
public:
    string minWindow(string s, string t) {
        string ans;
        int cnt = 0;
        unordered_map<char, int> map1, map2;
        for(auto x:t) {
            map1[x]++;
        }
        for(int l=0, r=0; r<s.size(); r++) {
            if(map1[s[r]] > map2[s[r]]) {
                cnt++;
            }
            map2[s[r]]++;
            while(map2[s[l]] > map1[s[l]] && r > l && l < s.size()) {
                map2[s[l]]--;
                l++;
            }
            if(cnt == t.size()) {
                if(ans.empty() || r-l+1 < ans.size()) {
                    ans = s.substr(l, r-l+1);
                }
            }
        }
        return ans;
    }
};