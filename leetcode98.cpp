class Solution {
public:
    vector<int> mid_seq_list;
    bool isValidBST(TreeNode* root) {
        mid_seq_traverse(root);
        if(mid_seq_list.size() <= 1) {
            return true;
        }
        for(int i=1, j=0; i<mid_seq_list.size(); i++, j++) {
            if(mid_seq_list[i] <= mid_seq_list[j]) {
                return false;
            }
        }
        return true;
    }
    void mid_seq_traverse(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        mid_seq_traverse(root->left);
        mid_seq_list.push_back(root->val);
        mid_seq_traverse(root->right);
        return;
    }
};