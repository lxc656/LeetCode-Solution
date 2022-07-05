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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int over_flow = 0;
        ListNode* virtual_head, *tmp;
        virtual_head = new ListNode(-1, nullptr);
        tmp = virtual_head;
        while(l1!=nullptr && l2!=nullptr) {
            int num = (l1->val + l2->val + over_flow)%10;
            ListNode *new_node = new ListNode(num, nullptr);
            cout<<num<<endl;
            tmp->next = new_node;
            tmp = new_node;
            over_flow = (l1->val + l2->val + over_flow)/10;
            l1 = l1->next, l2 = l2->next;
        }
        while(l1 != nullptr) {
            tmp->next = l1;
            tmp = tmp->next;
            int sum = l1->val + over_flow;
            l1->val = sum%10;
            over_flow = sum/10;
            l1 = l1->next;
        }
        while(l2 != nullptr) {
            tmp->next = l2;
            tmp = tmp->next;
            int sum = l2->val + over_flow;
            l2->val = sum%10;
            over_flow = sum/10;
            l2 = l2->next;
        }
        if(l1 ==nullptr && l2 == nullptr && over_flow == 1) {
            ListNode* new_node = new ListNode(1, nullptr);
            tmp->next = new_node;
        }
        ListNode* ans = virtual_head->next;
        delete(virtual_head);
        return ans;        
    }
};