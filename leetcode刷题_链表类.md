# leetcode 206

愚人节那天做的这道题，没想到leetcode还有愚人节彩蛋，把整个网页给反转了（当时忘截图了2333）

![](https://tva1.sinaimg.cn/large/e6c9d24ely1h0u53bv6bxj20ow0m2q4c.jpg)

迭代式写法：

（核心是要维护如下代码中的变量`c`，从而实现正确的链表反转）

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return nullptr;
        ListNode *a, *b, *c;
        a = head, b = a->next;
        while(b) {
            c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        head->next = nullptr;
        return a;
    }
};
```

递归式写法：

（假设`reverseList`函数这个"black box"是可以把以参数`head`为头节点的链表反转）

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        auto real_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return real_head;
    }
};
```

# leetcode 160



# leetcode 141



# leetcode 92



# leetcode 328

