//使用虚拟头节点，这样的话在头节点改变的时候不会受影响
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode virtual_head(-1, head);
        ListNode* vhead = &virtual_head;
        ListNode* tmp = vhead;
        for(int index = 0; index<left-1; index++) {
            tmp = tmp->next;
        }
        auto before = tmp, l = tmp->next, r = tmp->next->next;
        for(int count = 0; count < right-left; count++) {
            tmp = r->next;
            r->next = l;
            l = r;
            r = tmp;
        }
        before->next->next = r;
        before->next = l;
        return vhead->next;
    }
};