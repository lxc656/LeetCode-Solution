class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-1;
        //找到出现逆序的位置
        while(i>0 && nums[i]<=nums[i-1]) {
            i--;
        }
        if(i == 0) {
            return reverse(nums.begin(), nums.end());
        } else {
            int j;
            for(j = i; j<nums.size(); j++) {
                if(nums[j] <= nums[i-1]) {
                    break;
                }
            }
            swap(nums[i-1], nums[j-1]); //和右侧最小的比它大的数对换
            reverse(nums.begin()+i, nums.end()); //右侧整体倒置
        }
    }
};

/*作者：lxc656-z
链接：https://leetcode.cn/problems/next-permutation/solution/leetcode-by-lxc656-z-lde5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/