/*
在翻转的过程中，头节点会发生变化，因此可以使用一个虚拟头节点来让编程更方便
我们维护一个指针，指向所要交换的k个元素的前一个元素，然后根据如下的协议进行操作：
1.先判断这个指针后面有没有不少于k个元素（通过遍历可以解决）
2.如果满足step 1的条件，那么就把指针后面的k个元素构成的子链表反转
具体实现的时候还是有很多坑，因为同一个节点在链表翻转前后位于不同的位置，如果是在翻转前得到了对某个节点的引用
然后完成了翻转之后又去引用这个节点，但没有考虑到这个节点在链表里的相对位置已经发生了改变，那么就会出现各种bug...
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *vhead = new ListNode(-1, nullptr);
        vhead->next = head;
        auto cur = vhead;
        while(cur != nullptr) {
            int cnt = 0;
            auto x = cur;
            while(cnt < k && x!=nullptr) {
                x = x->next;
                cnt++;
            }
            if(x == nullptr) {
                break;
            } else {
                auto l = cur->next;
                auto r = l->next;
                for(int i=0; i<k-1; i++) {
                    auto tmp = r->next;
                    r->next = l;
                    l = r, r = tmp;
                }
                auto y = cur->next;
                y->next = r;
                cur->next = l;
                cur = y;
            }
        }
        return vhead->next;
    }
};