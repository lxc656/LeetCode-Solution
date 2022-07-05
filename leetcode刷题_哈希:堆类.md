# **哈希类（hashmap/hashset）：**

## leetcode 146

经典LRU

![](https://tva1.sinaimg.cn/large/e6c9d24ely1h0poesyynnj20ze0jy77a.jpg)

为了在O(1)时间内完成`get`和`push`操作，我们可以用哈希表作为索引；为了实现LRU机制，需要使用链表的数据结构，把最近一次使用过的KV放到链表的头部，并且要使用双链表而非单链表，因为单链表无法在O(1)时间内完成删除操作

代码实现如下：

```cpp
class LRUCache {
public:
    struct Node {
        int key, val;
        Node *left, *right;
        Node(int _key, int _val):key(_key), val(_val), left(nullptr), right(nullptr) {}
    }*L, *R; //左端和右端的哨兵节点
    unordered_map<int, Node*> hash;
    int n;

    void remove(Node* p) {
        p->right->left = p->left;
        p->left->right = p->right;
    }

    void insert(Node* p) {
        p->right = L->right;
        p->left = L;
        L->right->left = p;
        L->right = p;
    }    

    LRUCache(int capacity) {
        n = capacity;
        L = new Node(-1, -1), R = new Node(-1, -1);
        L->right = R, R->left = L;
    }
    
    int get(int key) {
        if(hash.count(key)==0) return -1;
        auto p = hash[key];
        remove(p);
        insert(p);
        return p->val;
    }
    
    void put(int key, int value) {
        if(hash.count(key)) {
            auto p = hash[key];
            p->val = value;
            remove(p);
            insert(p);
        } else {
            if(hash.size()==n) {
                auto p = R->left;
                remove(p);
                hash.erase(p->key);
                delete p;
            }
            auto p = new Node(key, value);
            hash[key] = p;
            insert(p);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```



# leetcode 128



# leetcode 73



# leetcode 380

## leetcode 49

[题目链接](https://leetcode.cn/problems/group-anagrams/)

判断两个字符串是“字母异位词”的方式可以是将两个字符串各自进行排序，然后判读两个排好序的字符串是否相同

那么如何将所有的“字母异位词”聚集到一起呢？可以建立一个字符串->字符串集合的哈希表，所有的字符异位词都在这个字符串集合里，具体的代码实现如下：

```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hashmap;
        for(auto x:strs) {
            string y = x;
            sort(y.begin(), y.end());
            hashmap[y].push_back(x);
        }
        for(auto x:hashmap) {
            ans.push_back(x.second);
        }
        return ans;
    }
};
```



# leetcode 350



# leetcode 299



# leetcode 348



# **堆/优先队列类**

## leetcode 973

![](https://tva1.sinaimg.cn/large/e6c9d24ely1h0s0ni11wcj20zc0amgn1.jpg)

如果用排序来做的话，时间复杂度是O(NlogN)，如果用堆来做的话，时间复杂度是O(N+k * logN)，其中O(N)是建堆所需时间，O(k * logN)是从堆顶弹k次所需的时间

但是由于题目中说的是可以按照任何的顺序返回，所以可以使用快速选择算法

（快速选择算法在[这篇文章](https://zhuanlan.zhihu.com/p/472751641)中有介绍，时间复杂度是O(N））

快速选择算法和快速排序比较像，都是一开始就把区间分成两半，如果题中所说的第k大的元素在左侧的子区间，那么就直接递归左侧子区间，如果第k大的元素在右半边，那么左半边就不用管了，因为题目里不要求结果的顺序，直接递归右半边即可

因此时间复杂度大概是O(N+N/2+N/4+...)，近似于O(N)

并且我们不需要自己实现快速选择算法，C++中有相应的库函数可以帮我们完成这件事

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(), points.begin() + k - 1, points.end(), [](vector<int>& a, vector<int>& b) {
            return (a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]);
        });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
```

## leetcode 347

<img src="https://tva1.sinaimg.cn/large/e6c9d24ely1h0tckl7ugij20om0g4my0.jpg" style="zoom:50%;" />

使用计数排序，额外开一个数组（假设这个数组叫`a`，那么`a[x]`就代表出现`x`次的元素的个数），代码实现如下：

```c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(auto x:nums) {
            cnt[x]++;
        }
        int sz = nums.size();
        vector<int> freq(sz+1), ans;
        for(auto [x, c]:cnt) {
            freq[c]++;
        }
        int limit = sz, sum = 0;
        while(sum < k) {
            sum+=freq[limit];
            limit--;
        }
        for(auto [x, c]:cnt) {
            if(c>limit) ans.push_back(x);
        }
        return ans;
    }
};
```

时间复杂度是O(n)

## leetcode 23

[原题链接](https://leetcode-cn.com/problems/merge-k-sorted-lists/)

和归并排序一样，需要为每个链表维护一个指针，指针指向链表中当前最小的元素，为了能够每次尽快找出所有的指针指向的元素里最小的那个，可以使用堆这个数据结构，把各个指针所指向的元素放到堆里，然后每次从堆里取出堆顶的元素，之后把相关的指针向后挪一位，然后把它所指向的元素放入堆中，这样的话，假设有`k`个链表，每个的长度是`n`，那么时间复杂度就是O(n*log(k))

C++ STL中的优先队列是大根堆，因此在创建优先队列时所传入的比较函数需要逆向比较

```cpp
class Solution {
public:
    struct compare {
        bool operator() (ListNode *a, ListNode *b) {
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *virtualhead = new ListNode(-1);
        ListNode *current_position = virtualhead;
        priority_queue<ListNode*, vector<ListNode*>, compare> heap;
        for(auto x:lists) {
            if(x) heap.push(x);
        }
        while(!heap.empty()) {
            ListNode *tmp = heap.top();
            heap.pop();
            current_position->next = tmp;
            current_position = tmp;
            if(tmp->next) heap.push(tmp->next);
        }
        return virtualhead->next;
    }
};
```

## leetcode 264

[题目链接](https://leetcode-cn.com/problems/ugly-number-ii/)

可以把题目中所说的丑数分为三种：包含因子2的，包含因子3的，包含因子5的

![](https://tva1.sinaimg.cn/large/e6c9d24ely1h1wrfxnjjkj20y80kc758.jpg)

对S1~S3这三个有序序列进行归并排序就可以得到我们想要的答案

然而实际上这三个序列都是由如下所示的S序列乘以一定的倍数得到的：

![](https://tva1.sinaimg.cn/large/e6c9d24ely1h1ws7mizp3j217i0kg0tz.jpg)

最终的代码实现：

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> q(1, 1);
        for (int i = 0, j = 0, k = 0; q.size() < n;) {
            int t = min(q[i] * 2, min(q[j] * 3, q[k] * 5));
            q.push_back(t);
            if (q[i] * 2 == t) i ++ ;
            if (q[j] * 3 == t) j ++ ;
            if (q[k] * 5 == t) k ++ ;
        }
        return q.back();
    }
};
```



# leetcode 1086



# leetcode 88



# leetcode 692



# leetcode 378



# leetcode 295



# leetcode 767



# leetcode 1438



# leetcode 895

