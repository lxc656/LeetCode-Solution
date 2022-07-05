class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        for(int start_point = 0; start_point < s.size(); start_point++) {
            int l = start_point - 1;
            int r = start_point + 1;
            while(l>=0&&l<s.size()&&s[l]==s[r]) {
                r++;
                l--;
            }
            if(r-l-1 > ans.size()) ans = s.substr(l+1, r-l-1);
            l = start_point, r = start_point+1;
            while(l>=0&&l<s.size()&&s[l]==s[r]) {
                r++;
                l--;
            }
            if(r-l-1 > ans.size()) ans = s.substr(l+1, r-l-1);
        }
        return ans;
    }
};