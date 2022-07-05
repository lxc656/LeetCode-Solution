class Solution {
public:
    int longestValidParentheses(string s) {
        int answer = 0;
        int range_start = -1;
        stack<int> stk; //栈里存的都是index
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                stk.push(i);
            }
            else {
                if(stk.size()) {
                    stk.pop();
                    if(stk.size()) {
                        answer = max(answer, i-stk.top());
                    }
                    else {
                        answer = max(answer, i-range_start);
                    }
                }
                else {
                    range_start = i;
                }
            }
        }
        return answer;
    }
};

/*作者：lxc656-z
链接：https://leetcode.cn/problems/longest-valid-parentheses/solution/leetcode32ti-jie-by-lxc656-z-d2x1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/