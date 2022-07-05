/*括号序列合法的条件：
1.任意前缀中'('的数量 >= '('的数量
2.左右括号数量相等
由于左括号和右括号都有n个，所以条件2一定可以满足
合法序列的数目其实是有公式的，就是catalan number
*/
//用dfs来做
//心得：用local variable来维护dfs当中的状态机，相比于访问全局变量，可以很简便的实现dfs
class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return ans;
    }
    void dfs(int n, int left_num, int right_num, string str) {
        if(left_num==n && right_num==n) ans.push_back(str);
        if(left_num < n) {
            dfs(n, left_num+1, right_num, str+"(");
        }
        if(right_num < n && right_num+1 <= left_num) {
            dfs(n, left_num, right_num+1, str+")");
        }
    }
};