class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        if(!nums.size()) {
            return -1;
        }
        if(target == nums[0]) {
            return 0;
        }
        while(l < r) {
            int mid = (l+r+1) >> 1;
            if(nums[mid] >= nums[0]) {
                l = mid;
            } 
            else {
                r = mid-1;
            }
        }
        if(target > nums[0]) {
            l = 0;
        }
        else {
            if(l+1 > nums.size()-1) {
                return -1;
            }
            else {
                l += 1;
            }
            r = nums.size()-1;
        }
        while(l < r) {
            int mid = l+r >> 1;
            if(nums[mid] >= target) {
                r = mid;
            }
            else {
                l = mid+1;
            }
        }
        if(nums[l] == target) {
            return l;
        }
        else {
            return -1;
        }
    }
};

/*作者：lxc656-z
链接：https://leetcode.cn/problems/search-in-rotated-sorted-array/solution/leetcode-by-lxc656-z-8xti/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/