/*
这个问题也要借助于单调栈来解决
需要借助单调栈来解决的问题一般都是和“找到序列里的每个数左边第一个比它小的数”有关
可以以n^2的数量级来枚举矩形的左右边界，也可以选择枚举所有可选的矩形的上边界
然后找出以某个高度为上边界的情况下，往左/右走最远可以到什么地方
问题也就转化成了找出每个数的左边和右边第一个比它小的数的位置
单调栈问题中每个元素只会进栈一次，出栈一次，因此时间复杂度是O(n)
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int num = heights.size();
        vector<int> LFS(num); //left first smaller
        vector<int> RFS(num); //right first smaller
        stack<int> stk;
        for(int i=0; i<num; i++) {
            while(stk.size() && heights[stk.top()]>=heights[i]) {
                stk.pop();
            }
            if(stk.size()) {
                LFS[i] = stk.top();
            } else {
                LFS[i] = -1;
            }
            stk.push(i);
        }
        stk = stack<int>();
        for(int i=num-1; i>=0; i--) {
            while(stk.size() && heights[stk.top()]>=heights[i]) {
                stk.pop();
            }
            if(stk.size()) {
                RFS[i] = stk.top();
            } else {
                RFS[i] = num;
            }
            stk.push(i);
        }
        for(int i=0; i<num; i++) {
            int size = heights[i]*(RFS[i]-LFS[i]-1);
            ans = max(size, ans);
        }
        return ans;
    }
};