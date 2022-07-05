class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> node_set;
        int index = 1;
        for(auto x = head; x != nullptr; x = x->next) {
            if(node_set[x] == 0) node_set[x] = index;
            else return x;
            index++;
        }
        return nullptr;
    }
};