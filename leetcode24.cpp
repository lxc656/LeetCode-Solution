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

//在交换的过程中，原链表的头节点会发生改变，因此采用一个虚拟头节点来简化操作
//通过迭代的方式来完成，会维护三个指针：指向参与交换的两个节点前面的那个节点的指针，
//指向参与交换的那两个节点的两个指针，具体的实现参考如下的代码

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *virtual_head = new ListNode(-1);
        virtual_head->next = head;
        ListNode *former_node = virtual_head;
        while(former_node && former_node->next && former_node->next->next) {
            ListNode *A = former_node->next;
            ListNode *B = former_node->next->next;
            former_node->next = B;
            A->next = B->next;
            B->next = A;
            former_node = A;
        }
        return virtual_head->next;
    }
};