class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int mindepth = 0;
        if(root) {
            q.push(root);
            mindepth++;
        }
        while(q.size()) {
            int num = q.size();
            while(num) {
                auto tmp = q.front();
                q.pop();
                if(tmp->left==nullptr&&tmp->right==nullptr&&tmp) { 
                    return mindepth;
                }
                if(tmp->left!=nullptr) q.push(tmp->left); 
                if(tmp->right!=nullptr) q.push(tmp->right);
                if(num==1) mindepth++;
                num--;
            }
        }
        return mindepth;
    }
};