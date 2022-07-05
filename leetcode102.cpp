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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root != nullptr) q.push(root);
        while(q.size()!=0) {
            vector<int> ans_in_this_level;
            int size = q.size();
            while(size!=0) {
                TreeNode* tmp = q.front();
                q.pop();
                ans_in_this_level.push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                size--;
            }
            ans.push_back(ans_in_this_level);
        }
        return ans;
    }
};