p.s. 本archive参考的是知乎上的一位前辈所总结出的准备算法面试的leetcode刷题清单（[链接在这里](https://zhuanlan.zhihu.com/p/349940945)），以及[acwing](www.acwing.com)上leetcode系列的题解

 关于快速排序和归并排序的知识可以参考笔者的[这篇笔记](https://zhuanlan.zhihu.com/p/472751641)

（在接下来的题目中也基本只会用到这两种排序）

# leetcode 148

题目的大致意思：给你链表的头结点 `head` ，请将其按 **升序** 排列并返回 **排序后的链表**，在 `O(n log n)` 时间复杂度和常数级空间复杂度下，对链表进行排序

首先回顾一下适用于链表的各种排序算法的时空复杂度：

- 快速排序：时间复杂度的期望是O(NlogN)（最坏情况不用考虑），平均空间复杂度是O(logN)（递归平均logN层所需的栈空间）
- 归并排序：时间复杂度是O(NlogN)，空间复杂度有两种情况：如果递归来写的话，因为要递归logN层，所以空间复杂度是O(logN)；如果自底向上迭代写的话，空间复杂度是O(1)

因此本题只适合使用迭代写法的归并排序来完成

自顶向下的递归版本的归并排序的做法是把链表分成左右两个长度相等的子区间，然后递归地把每个子区间用同样的方法排好序，再对它们归并

自底向上的迭代版本的写法是先把链表分成两两一组：第一个节点和第二个节点一组，第三个节点和第四个节点一组，第五个节点和第六个节点一组...然后每次迭代的时候都是从下往上把相邻的两个有序小区间合并成一个更大的有序区间，如下所示

<img src="https://tva1.sinaimg.cn/large/e6c9d24ely1h0l9y0gj4vj20we0fcta3.jpg" style="zoom:33%;" />

这样就不必递归，因此就省去了logN的栈空间

在具体实现的时候，为了方便，我们可以假设链表的长度是2的n次幂，如果实际上的链表长度不是2的n次幂（假设是x），那么直接当链表最后的(2^n-x)个节点不存在就可以了

代码实现如下：

```cpp
/*struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};*/

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int n; //先求链表长度
        for(auto p=head; p; p=p->next) n++;
        auto dummy = new ListNode(-1); //每次迭代中归并后得到的链表的虚拟头节点
        //迭代第i层的时候表明所有长度为i的子区间都已经排好序了
        //然后将两个相邻的长度为i的子区间拼成长度为2i的有序子区间
        //因此迭代终止条件是i==n
        for(int i=1; i<n; i*=2) {
            auto cur = dummy; 
            for(int j=1; j+i<n; j+=i*2){ //j表示的是归并的起点，每次将两段有序段归并为一个大的有序段，故而每次+2i，
                                         //必须保证每段中间序号是小于链表长度的，显然，如果大于表长，就没有元素可以归并了
                auto p=head, q=p;
                for(int k=0; k<i && q; k++) q=q->next; //q往后跳i步
                //先求出下一段归并的开头
                auto o=q;
                for(int k=0; k<i && o; k++) o = o->next;
                //接下来就是二路归并，每次把两个指针所指向的节点里比较小的那个放到cur后面
                int l=0, r=0;
                while(l<i&&r<i&&p&&q) { //左右子区间有可能长度不足i，因此p和q可能为空
                    if(p->val <= q->val) cur = cur->next = p, p = p->next, l++;
                    else cur = cur->next = q, q = q->next, r++;
                }
                while(l<i && p) cur = cur->next = p, p = p->next, l++;
                while(r<i && q) cur = cur->next = q, q = q->next, r++;
                head = o; 
            }
            cur->next = nullptr;
            head = dummy->next;
        }
        return head;
    }
};
```

# leetcode 56

[题目链接](https://leetcode.cn/problems/merge-intervals/)

这是一道模板题，要记住对应的解法

先将所有的区间依照其左端点的大小进行排序，在排完序的区间序列里面，一个区间如果和下一个的区间有交集，像下面这样：

|------------|

​    |----------------|

那么就把这两个区间合并，如果一个区间和下一个区间没有交集，那么和下下个以及其后的区间更不会有交集，那么就不用再管这个区间，因为它不会再参与后续的合并

代码实现如下：

```cpp
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int l = intervals[0][0], r = intervals[0][1];
        for(int i=1; i<intervals.size(); i++) {
            vector<int> tmp = intervals[i];
            if(tmp[0]>r) {
                ans.push_back({l, r});
                l = tmp[0];
                r = tmp[1];
            }
            else {
                r = max(r, tmp[1]);
            }
        }
        ans.push_back({l, r});
        return ans;
    }
};
```

# leetcode 179



# leetcode 75



# leetcode 215



# leetcode 4

