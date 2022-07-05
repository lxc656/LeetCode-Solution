/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<TreeNode*> ans;
        while(root || stk.size()) {
            while(root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            ans.push_back(root);
            stk.pop();
            root = root->right;
        }
        return ans;
    }
};