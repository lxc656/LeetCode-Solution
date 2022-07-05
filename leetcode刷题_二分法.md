# **显式二分**

## lc 33

[题目链接](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/)

二分的实质是一个区间的前一半满足某个性质，而后一半不满足这个性质，经过旋转后的数组在坐标系中的表示如下图所示，横坐标表示数组下标，纵坐标则表示数组下标处的值

![](https://tva1.sinaimg.cn/large/e6c9d24ely1h3tnzv0c19j209q08v749.jpg)

根据旋转数组的定义可以得出，上图中的前一段满足">=nums[0]"的性质，后一段不满足">=nums[0]"的性质，那么这个数组就符合二分的实质，因此可以用二分方法找出两段的分界点，本题的二分场景当中，这个分界点是满足这个性质的最后一个数

这样的话，就先通过二分把整个大的区间划分成了两段，每一段内部都是单调递增的，因此在每一段内部都可以进行二分，所以接下来就是判断`target`可能在哪个区间里，然后去对应的区间里做二分，判断的方法就是用`target`和`nums[0]`做比较即可

最终代码实现如下：

```cpp
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
```

## lc 34

[题目链接](https://leetcode.cn/problems/search-in-rotated-sorted-array/)

直接以">=target"和"<=target"两个性质进行两次二分搜索即可

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!nums.size()) {
            return {-1, -1};
        }
        int l=0, r=nums.size()-1;
        int L=-1, R=-1;
        while(l < r) {
            int mid = l+r+1 >> 1;
            if(nums[mid] <= target) {
                l = mid;
            } 
            else {
                r = mid-1;
            }
        }
        if(nums[l] != target) {
            return {-1, -1};
        }
        else {
            R = r;
        }
        l = 0, r = nums.size()-1;
        while(l<r) {
            int mid = l+r >> 1;
            if(nums[mid] >= target) {
                r = mid;
            }
            else {
                l = mid+1;
            }
        }
        L = l;
        return {L, R};
    }
};
```



# lc 1095



# lc 162



# lc 278



# lc 74



# lc 240



# **隐式二分**

# lc 69



# lc 540



# lc 644



# lc 528



# lc 1300



# lc 1060



# lc 1062



# lc 1891



Reference:

www.acwing.com
