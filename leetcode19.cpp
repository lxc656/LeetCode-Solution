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
//用队列维护最近访问过的n个节点，这样的话，
//访问到链表最后一个节点的时候，队列的第二个节点就是要删除的
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        queue<ListNode*> queue;
        int node_traversed = 0;
        ListNode *tmp, *victim;
        for(tmp = head; tmp; tmp = tmp->next) {
            if(tmp->next == nullptr) {
                node_traversed++;
                if(!queue.empty() && node_traversed > n) {
                    victim = queue.front()->next;
                    queue.front()->next = victim->next;
                }
                else if(!queue.empty() && node_traversed == n) {
                    head = head->next;
                }
                else head =nullptr;
            }
            else {
                node_traversed++;
                queue.push(tmp);
                if(node_traversed > n) queue.pop();
            }
        }
        return head;
    }
};