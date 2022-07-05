/*
使用单调栈来解决
每根柱子到达之后就把它存到栈里
思路有些过于抽象，难以用语言记录，还是看acwing的讲解吧2333
每次来一个柱子之后就会把栈顶比它矮的柱子弹出直至栈顶的柱子比它高
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stk; 单调栈用来存下标会更方便，这里的好处是用下标能计算水柱的宽度
        for(int i=0; i<height.size(); i++) {
            int last = 0; //用来存“前一个”柱子的高度用
            //从右往左，从上往下，一层一层算水量
            while(stk.size() && height[stk.top()]<height[i]) {
                ans+=(height[stk.top()]-last)*(i-stk.top()-1);
                last = height[stk.top()];
                stk.pop();
            }
            //因为栈顶元素pop掉的时候会把它和高度为last那个柱子之间的水量计入答案里，
            //所以如果不能pop掉栈里所有柱子，还需要再把last和即将入栈的柱子间的水量再算进去
            if(stk.size()) {
                ans+=(height[i]-last)*(i-stk.top()-1);
            }
            stk.push(i);
        }
        return ans;
    }
};