# 基于树的BFS

# lc 102

和朴素的BFS遍历树不同的是，这里需要额外维护一下关于每层的信息

```cpp
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
```



# lc 103



# lc 297



# lc 314



# 基于图的BFS

# lc 200



# lc 133



# lc 127



# lc 490



# lc 323



# lc 130



# lc 752



# lc 815



# lc 1091



# lc 542



# lc 1293



# 拓扑排序 

# lc 207



# lc 444



# lc 269



# lc 310



# lc 366

