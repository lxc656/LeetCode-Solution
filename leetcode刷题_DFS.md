# 基于树的DFS

# lc 543



# lc 226



# lc 101



# lc 951



# lc 124



# lc 236



# lc 105



# lc 104



# lc 987



# lc 1485



# lc 572



# lc 863



# lc 1110



# 二叉搜索树

# lc 230

## lc 98

[题目链接](https://leetcode.cn/problems/validate-binary-search-tree/)

一个比较简单的方法是得到二叉搜索树中序遍历的结果，然后检测这个结果是不是一个单调递增的序列，因为二叉搜索树的一性质就是它的中序遍历的结果是单调递增的

（也可以使用朴素的完全按照二叉搜索树的定义的方式来完成本题目，想办法得出左子树的最大值和右子树的最小值，然后根据定义来判断，详情可以参考acwing上的题解）

```cpp
class Solution {
public:
    vector<int> mid_seq_list;
    bool isValidBST(TreeNode* root) {
        mid_seq_traverse(root);
        if(mid_seq_list.size() <= 1) {
            return true;
        }
        for(int i=1, j=0; i<mid_seq_list.size(); i++, j++) {
            if(mid_seq_list[i] <= mid_seq_list[j]) {
                cout<<mid_seq_list[i]<<" "<<mid_seq_list[j]<<endl;
                return false;
            }
        }
        return true;
    }
    void mid_seq_traverse(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        mid_seq_traverse(root->left);
        mid_seq_list.push_back(root->val);
        mid_seq_traverse(root->right);
        return;
    }
};
```

## lc 270



# lc 235



# lc 669



# lc 700



# lc 108



# lc 333



# lc 285



# 基于图的DFS

## lc 341

[题目链接](https://leetcode-cn.com/problems/flatten-nested-list-iterator/)

用DFS的思路来解决，递归式写法：

```cpp
class NestedIterator {
public:
    vector<int> buffer;
    int index;
    NestedIterator(vector<NestedInteger> &nestedList) {
        index = 0;
        for(auto x:nestedList) traverse(x);
    }

    void traverse(NestedInteger &x) {
        if(x.isInteger()) {
            buffer.push_back(x.getInteger());
        }
        else {
            for(auto y:x.getList()) traverse(y);
        }
    }
    
    int next() {
        return buffer[index++];
    }
    
    bool hasNext() {
        return index<buffer.size();
    }
};
```

(与之类似的另一道题：[lc385](https://leetcode-cn.com/problems/mini-parser/))

```cpp

```

# lc 394



# lc 51



# lc 291



# lc 126



## lc 93

[题目链接](https://leetcode.cn/problems/restore-ip-addresses/)

暴力搜索即可

假设输入的字符串有n个字符，那么其中就有n-1个位置可以插入"."，复原IP地址的本质就是在这n-1个位置里面选出来3个位置用来放"."，因此所有的方案数，即时间复杂度是
$$
C_{n-1}^3
$$
n最大可以取12，并且在具体实现中，可以通过条件判断使得字符串长度大于12的时候就返回无解，所以时间复杂度最高也就是
$$
C_{11}^{3} * n
$$
这个级别（乘以的n是用来记录方案的开销），可以接受

在DFS的时候可以通过传递参数的方式来保存当前搜索阶段的状态机，这样实现起来很方便，具体代码实现如下：

```cpp
class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0, "");
        return ans;
    }
    /*
    参数说明：
    cnt代表着已经插入了几个“.“，index代表着现在走到了字符串哪个位置
    path是现在为止复原出来的IP地址
    */
    void dfs(string& s, int cnt, int index, string path) {
        //设置边界条件
        if(cnt == 4 && index == s.size()) {
            path.pop_back();
            ans.push_back(path);
            return;
        }
        if(cnt == 4) {
            return;
        }
        //number是接下来要往IP地址里插入的数据
        int number = 0;
        for(int i = index; i<s.size(); i++) {
            if(i>index && s[index] == '0') {
                return;
            }
            number = number*10 + (s[i]-'0');
            if(number > 255) {
                break;
            } else {
                dfs(s, cnt+1, i+1, path+to_string(number)+'.');                
            }
        }
    }
};
```



# lc 22



# lc 856



# lc 301



# lc 37



# lc 212



# lc 1087



# lc 399



# lc 1274



# lc 1376



# lc 694



# lc 131



# 基于排列组合的DFS

## lc 17

[题目链接](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/)

暴力DFS搜索即可，九键的映射关系可以通过字符串数组来巧妙实现，代码如下：

```cpp
class Solution {
public:
    vector<string> ans;
    vector<string> map = {
        "", "",  //故意设置的无效映射
        "abc", "def", "ghi",
        "jkl", "mno", "pqrs",
        "tuv", "wxyz"
    };
    vector<string> letterCombinations(string digits) {
        dfs_traverse(digits, 0, "");
        return ans;
    }
    //dht means "digits have traversed"
    void dfs_traverse(string digits, int dht, string path) {
        if(digits.size() == 0) {
            return;
        } else if(dht == digits.size()) {
            ans.push_back(path);
            return;
        } else {
            int index = digits[dht]-'0';
            for(auto digit:map[index]) {
                dfs_traverse(digits, dht+1, path+digit);
            }
        }
    }
};
```

## lc 39

[题目链接](https://leetcode.cn/problems/combination-sum/)

题目中要我们返回所有方案，因此如果使用背包问题&动态规划没有用，暴力搜索即可

暴力搜索主要考虑搜索的顺序，也就是“按照怎样的一个顺序来搜索可以做到不重不漏”，我们可以依次枚举`candidates[i]`选几个

代码实现如下：

```cpp
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        dfs(path, candidates, target, 0);
        return ans;
    }
    void dfs(vector<int>& path, vector<int>& candidates, int target, int index) {
        if(target == 0) {
            ans.push_back(path);
            return;         
        }
        if(index == candidates.size()) {
            return;
        }
        for(int num=0; num*candidates[index]<=target; num++) {
            for(int i=0; i<num; i++) {
                path.push_back(candidates[index]);
            }
            dfs(path, candidates, target-num*candidates[index], index+1);
            for(int i=0; i<num; i++) {
                path.pop_back();
            }
        }
    }
};
```

## lc 78

[题目链接](https://leetcode.cn/problems/subsets/)

这个题目可以通过迭代来完成，而非基于递归的DFS

我们可以借助位运算

比如说有a1, a2, a3这三个数可选，那么我们就可以用3个bit位来表示它们是否存在，for example，0 1 1表示选a2和a3，但不选a1

推广至有n个数可以选，我们分别以0~2^n-1为bitmap来决定哪些数该选，哪些数不该选，然后就可以得出所有的可行方案

时间复杂度是：(2^n)*n

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0; i<(1<<n); i++) {
            vector<int> tmp;
            for(int j=0; j<n; j++) {
                if(i>>j & 1) {
                    tmp.push_back(nums[j]);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
```

## lc 46

[题目链接](https://leetcode.cn/problems/permutations/)

很基础的DFS属于是

```cpp
class Solution {
public:
    vector<vector<int>> ans;
    bool bitmap[25];
    vector<vector<int>> permute(vector<int>& nums) {
        for(auto x:bitmap) {
            x = false;
        }
        vector<int> path;
        dfs(nums, 0, path);
        return ans;
    }
    void dfs(vector<int>& nums, int num, vector<int>& path) {
        if(num == nums.size()) {
            ans.push_back(path);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(bitmap[nums[i]+10] == false) {
                path.push_back(nums[i]);
                bitmap[nums[i]+10] = true;
                dfs(nums, num+1, path);
                path.pop_back();
                bitmap[nums[i]+10] = false;
            }
        }
    }
};
```



# lc 77



# lc 698



# lc 526



# 记忆化搜素

# lc 139



# lc 72



# lc 377



# lc 1235



# lc 1335



# lc 1216



## lc 97

[题目链接](https://leetcode.cn/problems/interleaving-string/)

本题目使用动态规划来解决，

- 状态表示：

	对于这种涉及到两个字符串的问题，状态表示一般都使用f(i, j)这种二维的形式，它在本题目中所表示的集合是“所有由s1[1~i]和s2[1~j]交错形成s3[1~i+j]的方案”，f(i, j)所对应的属性是“集合是不是空集”，即true or false，更简单地说，f(i, j)所表示的就是“由s1[1~i]和s2[1~j]能否组合形成s3[1~i+j]”

- 状态计算：

	状态计算的过程中需要将状态表示中的集合划分成一个个的子集，这里划分子集的依据是s3[i+j]是来自s1还是s2，我们想判断f(i, j)这个集合是否为非空集合，那么只需判断它的这两个子集是不是至少有一个非空

	因此就实现了从f(i, j)到f(i-1, j)或f(i, j-1)的状态转移

	之所以下标从1开始，也是因为状态转移公式里出现了`i-1`,`j-1`

代码实现如下：

```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        if(l3 != l1+l2) {
            return false;
        }
        s1 = ' '+s1, s2 = ' '+s2, s3 = ' '+s3;
        vector<vector<bool>> f(l1+1, vector<bool>(l2+1));
        for(int i=0; i<=l1; i++) {
            for(int j=0; j<=l2; j++) {
                if(i==0 && j==0) {
                    f[i][j] = true;
                }
                else {
                    if(i && s3[i+j] == s1[i]) {
                        f[i][j] = f[i-1][j];
                    }
                    if(j && s3[i+j] == s2[j]) {
                        f[i][j] = f[i][j-1] | f[i][j];
                    }
                }
            }
        }
        return f[l1][l2];
    }
};
```



# lc 472



# lc 403



# lc 329



