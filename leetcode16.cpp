//题解链接：https://leetcode.cn/problems/3sum-closest/solution/by-lxc656-z-fv5y/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int distance = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1, k=nums.size()-1; j<nums.size(); j++) {
                while(k-1>j && nums[i]+nums[j]+nums[k-1] >= target) {
                    k--;
                }
                if(k > j) {
                    int sum = nums[i]+nums[j]+nums[k];
                    if(abs(sum-target) < distance) { //sum不一定比target大
                        distance = abs(sum-target);
                        ans = sum;
                        //cout<<"i="<<i<<" j="<<j<<" k="<<k<<endl;
                        //cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                    }
                } else {
                    break;
                }
                if(k-1 > j) {
                    int sum = nums[i]+nums[j]+nums[k-1];
                    if(target-sum < distance) {
                        distance = target-sum;
                        ans = sum;
                        //cout<<"i="<<i<<" j="<<j<<" k="<<k<<endl;
                        //cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k-1]<<endl;
                    }
                }
            } 
        }
        return ans;
    }
};