//link:https://leetcode-cn.com/problems/missing-two-lcci/
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        long sum = 0;
        for(auto x:nums) sum+=x;
        int n = nums.size()+2;
        int two_sum = (1+n)*n/2 - sum;
        int max = two_sum/2;
        sum = 0;
        for(auto x:nums) {
            if(x<=max) {
                sum+=x;
            }
        }
        int first = (1+max)*max/2-sum;
        return {first, two_sum-first};
    }
};