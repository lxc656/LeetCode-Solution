/*作者：lxc656-z
链接：https://leetcode.cn/problems/4sum/solution/leetcode18ti-jie-by-lxc656-z-8smw/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            if(i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            for(int j=i+1; j<nums.size(); j++) {
                if(j>i+1 && nums[j]==nums[j-1]) {
                    continue;
                }
                for(int k=j+1, l=nums.size()-1; k<l; k++) {
                    if(k>j+1 && nums[k]==nums[k-1]) {
                        continue;
                    }
                    while(l-1>k && (long long int)nums[i]+nums[j]+nums[k]+nums[l-1] >=  target) { //注意保证l-1>k
                        l--;
                    }
                    if((long long int)nums[i]+nums[j]+nums[l]+nums[k] == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    }
                }
            }
        }
        return ans;
    }
};
