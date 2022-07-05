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
    ListNode* middleNode(ListNode* head) {
        int num = 0;
        for(auto x = head; x; x = x->next) {
            num++;
        }
        int index = num/2 + 1;
        auto ans = head;
        for(int i = 1; i<index; i++) {
            ans = ans->next;
        }
        return ans;
    }
};