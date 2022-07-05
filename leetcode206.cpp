//Iteration:
class Solution1 {
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
//Recursive:
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        auto real_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return real_head;
    }
};