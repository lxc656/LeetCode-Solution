/*
这是一道模板题，要记住对应的解法
先将所有的区间依照其左端点的大小进行排序
在排完序的区间序列里面，一个区间如果和下一个的区间有交集，像下面这样：
|------------|
    |----------------|
那么就把这两个区间合并，如果一个区间和下一个区间没有交集，那么和下下个以及其后的区间更
不会有交集，那么就不用再管这个区间，因为它不会再参与后续的合并
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int l = intervals[0][0], r = intervals[0][1];
        for(int i=1; i<intervals.size(); i++) {
            vector<int> tmp = intervals[i];
            if(tmp[0]>r) {
                ans.push_back({l, r});
                l = tmp[0];
                r = tmp[1];
            }
            else {
                r = max(r, tmp[1]);
            }
        }
        ans.push_back({l, r});
        return ans;
    }
};