class Solution {
public:
    bool canJump(vector<int>& nums) {
        //j用来表示“当前能跳到的最远的地方”
        for(int i=0, j=0; i<nums.size(); i++) {
            if(i>j) {
                return false; //目前遍历到的i是跳不到的，因此后面的点也跳不到，自然也跳不到终点
            }
            else {
                j = max(j, i+nums[i]); //更新可以跳到的最远的地方
            }
        }
        return true;
    }
};

/*作者：lxc656-z
链接：https://leetcode.cn/problems/jump-game/solution/leetcode-by-lxc656-z-9nah/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/