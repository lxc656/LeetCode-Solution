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