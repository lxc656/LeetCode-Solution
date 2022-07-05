## lc72

[题目链接](https://leetcode-cn.com/problems/edit-distance/)

从集合角度分析dp问题，要先弄清楚状态的表示和计算

最短编辑距离当中不可能把一个元素插入之后再删除，也不可能把一个元素替换两次（这些都是多余的操作），并且操作之间的顺序对操作的最终结果没什么影响，因此我们可以人为的规定操作的顺序，比如说“操作都是从前往后进行的”

- 状态表示：

f(i, j)这个集合代表：将A[1~i]变成B[1~j]的所有按我们所人为规定的顺序进行的方案；f(i, j)的属性就是这个集合里所有方案对应的操作次数的最小值

- 状态计算；

把f(i, j)分成多个子集，求出每个子集中的最小值

根据把A[1~i]变成B[1~j]的最后一步操作的不同，便可以把f(i, j)分成多个子集

最后一步（或者可以理解成对字符串最后一个元素的修改）可以是增/删/改操作中的一种，可以发生在A字符串上，也可以发生在B字符串上

![](https://tva1.sinaimg.cn/large/e6c9d24ely1h1pinfh856j215v0u0grd.jpg)

代码实现：

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        word1 = " " + word1;
        word2 = " " + word2;
        vector<vector<int>> status(l1+1, vector<int>(l2+1, 1e8));
        for(int i=0; i<=l1; i++) status[i][0] = i;
        for(int i=1; i<=l2; i++) status[0][i] = i;
        for(int i=1; i<=l1; i++) {
            for(int j=1; j<=l2; j++) {
                int tmp;
                status[i][j] = status[i-1][j]+1;
                status[i][j] = min(status[i][j-1]+1, status[i][j]);
                if(word1[i] == word2[j]) {
                    tmp = status[i-1][j-1];
                }
                else tmp = status[i-1][j-1]+1;
                status[i][j] = min(status[i][j], tmp);
            }
        }
        return status[l1][l2];
    }
};
```

## lc32

[题目链接](https://leetcode.cn/problems/longest-valid-parentheses/)

合法括号序列要满足如下两个条件：

1. "("和")"数量相等，
2. 任意前缀中，"("数量大于等于")"的数量

本题当中，从左往右扫描字符串，如果发现被扫描到的")"比"("多，那么就停止扫描，把当前扫描到的这个位置记录下来，然后从它右侧重新开始扫描，最终就完成了对字符串的分段，如下所示：

![](https://tva1.sinaimg.cn/large/e6c9d24ely1h3rg98l16cj21uc0bpt9x.jpg)

每一段中的右括号的数量都比左括号多，并且每个合法的连续括号序列都存在于刚才划分出来的各个段当中，不会跨段存在（也就是说，对应的区间不会跨越段和段之间的分界线），具体的证明使用反证法，如下图所示：

![](https://tva1.sinaimg.cn/large/e6c9d24ely1h3rgudvztmj215a0hm0uh.jpg)

假设有一个合法的连续括号序列跨段存在，由于上文的推论“合法的连续括号序列的任意前缀中左括号的数量大于等于右括号的数量”，那么红色区间内左括号数>=右括号数，又已知橙色区间内左括号数<右括号数，那么紫色区间内左括号应该少于右括号（前面两个不等式做减法得出），那么紫色区间的右端点也应该是段与段之间的分界线，这显然和最初的假设矛盾

好了，终于证明完了（

接下来就是在每一个我们划分出来的段里找出最长的合法连续符号序列，这个可以借助栈来实现（和判断一个含有括号的表达式是否合法的方式差不多）

具体代码实现如下：

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int answer = 0;
        int range_start = -1;
        stack<int> stk; //栈里存的都是index
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                stk.push(i);
            }
            else {
                if(stk.size()) {
                    stk.pop();
                    if(stk.size()) {
                        answer = max(answer, i-stk.top());
                    }
                    else {
                        answer = max(answer, i-range_start);
                    }
                }
                else {
                    range_start = i;
                }
            }
        }
        return answer;
    }
};
```

(其实这个做法不算是DP，使用DP来解决这个问题的话可以参考[这一篇题解](https://leetcode.cn/problems/longest-valid-parentheses/solution/xiang-xi-fen-xi-by-huo-shan-v-c9x2/)

## lc55

[题目链接](https://leetcode.cn/problems/jump-game/)

首先证明能跳跃到达的区间是连续的，也就是如下所示：

|------------AB-----|

如果能从起点跳跃到B点，那么也肯定能从起点跳跃到A点，因为跳跃到B点的时候肯定是从它前面的点跳跃过来的，如果这个“前面的点”是A点的话，那么自然得证，如果不是的话，那这个点就是A点前面的点，既然从这个点能跳到B，那么肯定也能跳到A，少跳一步就行

以此类推，能跳到B就能跳到A，能跳到A就能跳到A前面那一点，...，因此能跳到数组里index为x的点，自然也就能跳到数组里index为0, ..., x-1的点

代码实现如下：

```C++
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
```

和lc55非常接近的还有lc45这道题：

## lc45

[题目链接](https://leetcode.cn/problems/jump-game-ii/)

## lc62

[题目链接](https://leetcode.cn/problems/unique-paths/)

其实很容易就能看出来这个是高中数学排列组合题目了（

答案自然是
$$
C_{n+m}^n
$$
当然也可以用DP来做

定义f(i, j)是从起点到坐标为(i, j)的点有多少种不同的方案，那么f(i, j)在3 x 5的矩阵中的值如下所示：

![截屏2022-07-05 11.48.31.png](https://pic.leetcode-cn.com/1656992934-nfaEjN-%E6%88%AA%E5%B1%8F2022-07-05%2011.48.31.png)

有如下的状态转移方程：

f(i, j) = f(i-1, j) + f(i, j-1) （i, j不为0时）

当i为0时f(i, j) = f(i, j-1)（因为只能从左边过来）

当j为0时f(i, j) = f(i-1, j)（因为只能从上边过来）

f(0, 0) = 1（起点）

最终依据状态转移方程进行递推即可，时间复杂度是O(n^2)，代码实现如下：

```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        int f[m][n];
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!i && !j) {
                    f[i][j] = 1;
                }
                else if(i == 0) {
                    f[i][j] = f[i][j-1];
                }
                else if(j == 0) {
                    f[i][j] = f[i-1][j];
                }
                else {
                    f[i][j] = f[i-1][j] + f[i][j-1];
                }
            }
        }
        return f[m-1][n-1];
    }
};
```

## lc63



## lc64

[题目链接](https://leetcode.cn/problems/minimum-path-sum/)

使用和lc62类似的DP方法即可

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f(m, vector<int>(n, 0x3f3f3f3f));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!i && !j) {
                    f[i][j] = grid[i][j];
                }
                else if(!i) {
                    f[i][j] = f[i][j-1] + grid[i][j];
                }
                else if(!j) {
                    f[i][j] = f[i-1][j] + grid[i][j];
                }
                else {
                    f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
                }
            }
        }
        return f[m-1][n-1];
    }
};
```

Reference:

www.acwing.com
