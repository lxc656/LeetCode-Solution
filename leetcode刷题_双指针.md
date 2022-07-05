# **背向双指针**

# lc 409



# lc 125



# lc 5

[原题链接](https://leetcode-cn.com/problems/longest-palindromic-substring/)

可以使用相对来说较为暴力但简单的方法来解决，我们依次尝试字符串数组里的任何一个元素，把它当作中心来尝试构建回文串，所有被构建出来的回文串中最长的即为所求

在构建的过程中有两种情况要考虑：回文串的长度是奇数/偶数

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        for(int start_point = 0; start_point < s.size(); start_point++) {
            int l = start_point - 1;
            int r = start_point + 1;
            while(l>=0&&l<s.size()&&s[l]==s[r]) {
                r++;
                l--;
            }
            if(r-l-1 > ans.size()) ans = s.substr(l+1, r-l-1);
            l = start_point, r = start_point+1;
            while(l>=0&&l<s.size()&&s[l]==s[r]) {
                r++;
                l--;
            }
            if(r-l-1 > ans.size()) ans = s.substr(l+1, r-l-1);
        }
        return ans;
    }
};
```



# **相向双指针**

# lc 167



# lc 15

[题目链接](https://leetcode-cn.com/problems/3sum/)

双指针算法一般是基于序列有序的前提条件来进行的，因此先将数组排序，总共会使用3个指针，假设它们对应的索引分别是`i`,`j`,`k`，为了避免出现重复枚举的情况，我们首先规定`i`<`j`<`k`

当`i`被固定住之后，`j`和`k`就可以做双指针了

如果暴力枚举`j`和`k`所有可能的取值，那么时间复杂度是O(n^2)，使用双指针就可以把时间复杂度降低到O(n)：因为数组是有序的，随着`j`向后移动，`nums[j]`增大，能满足`num[i]+num[j]+num[k]>=0`的最小的`k`便也随之减小，指针`k`向前移动。这便是关于这两个指针的单调性，也是双指针算法设计的突破口

代码实现如下：

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            if(i && nums[i]==nums[i-1]) continue;
            for(int j = i+1, k = nums.size()-1; j<k; j++) {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                while(j < k-1 && nums[i]+nums[j]+nums[k-1] >= 0) k--;
                if(nums[i]+nums[j]+nums[k] == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return ans;
    }
};
```

为了实现完全的去重，在枚举到`nums[i+1]`的时候，如果发现`nums[i+1]==mus[i]`，那么就直接跳过，对`j`的处理逻辑也同理

# lc 16

[题目链接](https://leetcode.cn/problems/3sum-closest/)

暴力做法就是把三个数所有可能的选择全都枚举一遍，在暴力法的基础之上可以用双指针算法进行优化

先把数组排好序，然后枚举选择第一个数`nums[i]`，将`i`固定住，然后枚举`j`，找到使得`nums[i]+nums[j]+nums[k]>=target`成立的最小`k`，那么则有`nums[i]+nums[j]+nums[k-1]<target`，则`k-1`是使得`nums[i]+nums[j]+nums[k]<target`成立的最大`k`

双指针的单调性：随着`j`增大，`k`必然不变或减小

代码实现如下：

```cpp
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
                    }
                } else {
                    break; //双指针相遇
                }
                if(k-1 > j) {
                    int sum = nums[i]+nums[j]+nums[k-1];
                    if(target-sum < distance) {
                        distance = target-sum;
                        ans = sum;
                    }
                }
            } 
        }
        return ans;
    }
};
```

# lc 18

[题目链接](https://leetcode.cn/problems/4sum/)

同样是使用双指针算法的思路，不过此处是4数之和，因此需要暴力枚举前两个数的选择方案，然后通过双指针把后两个数的选择方案优化成O(n)，先给数组排个序，然后在扫描的过程中，如果扫描到的数和前面的数相同，那么就把这个方案舍弃掉，从而实现去重复，总体上和leetcode17思路相似，代码实现如下：

```cpp
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
```

btw，如果推广到n数之和那就是背包问题了

# lc 454



# lc 277



# lc 11

[题目链接](https://leetcode.cn/problems/container-with-most-water/)

维护两个指针，左指针最开始指向最左边的柱子，右指针最开始指向最右边的柱子，如果左指针指向的柱子更矮，那就让左指针右移一位，如果右指针指向的柱子更矮，那就让右指针左移一位

关于“为什么这个算法是正确的“的证明其实可以用一句话概括：

”木桶容量由短板决定, 移动长板的话, 水面高度不可能再上升, 而宽度变小了, 所以只有通过移动短板, 才有可能使水位上升“

严格的证明可以参考yxc的讲解（

这也属于是贪心算法的一个应用

代码实现如下：

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        int ans = min(height[l], height[r])*(r-l);
        while(l<r) {
            if(height[l]<height[r]) {
                l++;
                int size = (r-l)*min(height[l], height[r]);
                ans = max(ans, size);
            } else {
                r--;
                int size = (r-l)*min(height[l], height[r]);
                ans = max(ans, size);
            }
        }
        return ans;
    }
};
```



# **同向双指针**

# lc 283



# lc 26



# lc 395



# lc 340



# lc 424



# lc 76

[题目链接](https://leetcode.cn/problems/minimum-window-substring/)



# lc 3

[题目链接](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)

把外层循环的指针设置成子区间的右端点，内层循环的指针设置成区间的左端点，这样能保证内层循环的指针一直不会越过外层循环的指针（

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char, int> count;
        for(int r=0, l=0; r<s.size(); r++) {
            count[s[r]]++;
            while(count[s[r]]==2) {
                count[s[l]]--;
                l++;
            }
            if(r-l+1>ans) ans = r-l+1;
        }
        return ans;
    }
};
```



# lc 1004





References:

www.acwing.com
