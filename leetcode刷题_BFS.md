# 基于树的BFS

## lc 102

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

## lc 103

[题目链接]()

相比于lc102普通的层序遍历，将偶数层的遍历得到的vector翻转一下即可

```c++
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root == nullptr) {
            return {};
        }
        else {
            q.push(root);
        }
        int layer_count = 1;
        while(q.size()) {
            int sum = q.size();
            vector<int> this_layer;
            while(sum--) {
                TreeNode *node = q.front();
                q.pop();
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
                this_layer.push_back(node->val);
            }
            if(layer_count % 2) {
                ans.push_back(this_layer);
            }
            else {
                reverse(this_layer.begin(), this_layer.end());
                ans.push_back(this_layer);
            }
            layer_count++;
        }
        return ans;
    }
};
```

## lc 297

[题目链接]()

对二叉树的序列化与反序列化的方法基本都是基于对二叉树的遍历

本题目可以使用前序遍历二叉树的方法进行序列化，并且需要让前序遍历得到的序列当中包含空节点（因为如果没有空节点，就无法仅通过前序遍历得到的序列来进行反序列化），空节点可以用'#'字符来描述，节点之间用空格间隔开

前序遍历本身通过递归来实现，反序列化亦然

代码实现如下：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) {
            return "#";
        }
        else {
            string root_val = to_string(root->val);
            string left_val = serialize(root->left);
            string right_val = serialize(root->right);
            return (root_val + " " + left_val + " " + right_val);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return recursive_des(data, index);
    }

    TreeNode* recursive_des(string& data, int& index) {
        if(data[index] == '#') {
            index += 2;
            return nullptr;
        }
        else {
            int tmp = index;
            while(data[index] != ' ') {
                index++;
            }
            TreeNode *root_node = new TreeNode(stoi(data.substr(tmp, index-tmp)));
            index++;
            TreeNode *left_child = recursive_des(data, index);
            TreeNode *right_child = recursive_des(data, index);
            root_node->left = left_child;
            root_node->right = right_child;
            return root_node;
        }
    }
};
```

## lc 314



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

