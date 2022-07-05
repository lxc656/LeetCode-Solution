/*方法1-通过差分完成：
构建差分数组
如果a[l]~a[r]构成等差数列，那么它所对应的差分数组中b[l+1]~b[r]都是相等的
注：a[l]~a[r]对应的差分数组b是指，b[l]=a[l],其他元素b[i] = a[i]-a[i-1]
因此这个问题等价于在差分数组里寻找连续相等的一段
如果差分数组里面连续相等的一段的长度是k，那么就对应原数组中长度为k+1的一个等差数列
在这个长度为k+1的等差数列里，有(k+1)-2，即k-1个长度为3的子等差数列,k-2个长度为4的子等差数列...
因此总共有k-1+k-1+...+1 = (k-1)*k/2个子等差数列*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        for(int i=nums.size()-1; i>0; i--) {
            nums[i] = nums[i]-nums[i-1];
        }
        int length = 1;
        int ans = 0;
        for(int i=1; i<nums.size(); i++) {
            while(i+1<nums.size()&&nums[i+1]==nums[i]) {
                length++;
                i++;
            }
            ans+=(length*(length-1)/2);
            cout<<ans<<" ";
            length = 1;
        }
        return ans;
    }
};
/*方法2-动态规划
以a[i]为结尾（注意，是为结尾）的等差数列的数目是以a[i-1]为结尾的等差数列的数目+1
int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        int counts=0;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                dp[i]=dp[i-1]+1;
                counts+=dp[i];
            }
        }

        return counts;
    }
*/

/*方法3-双指针
想一直满足区间[i, j]是等差数列，随着i往右移动，j也要随之往右移动
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        const int N = A.size();
        int res = 0;
        for (int i = 0; i < N - 2; i++) {
            int d = A[i + 1] - A[i];
            for (int j = i + 1; j < N - 1; j++) {
                if (A[j + 1] - A[j] == d) 
                    res ++;
                else
                    break;
            }
        }
        return res;
    }
};
*/