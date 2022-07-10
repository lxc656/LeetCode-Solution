[题目链接](https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/)

感觉要是原地展开的话网上也没有太好的解法，还是yxc老师的解法好一点（虽然y老师在写这道题的时候lc官方还没有给出前序遍历的提示

按照如下的协议进行遍历即可：

1. 如果当前根节点存在左子树，那么将左子树的右链插入当前根节点的右边
2. 如果当前根节点不存在左子树，则遍历根节点的右子树

（什么是右链捏？如下所示：

![IMG_2482.jpg](https://pic.leetcode-cn.com/1657449398-NlhBLq-IMG_2482.jpg)

其实这么做是可以被证明出来正好可以和前序遍历得到相同的结果，因为前序遍历的时候，某一颗子树中最后被遍历到的一定是它的右链里最后一个点，在前序遍历完这个点之后，就会遍历到这颗子树的父节点的右子树，正如下图红色线所展示出的遍历顺序那样：

![IMG_2483.jpg](https://pic.leetcode-cn.com/1657450328-WSitUN-IMG_2483.jpg)

那么我们就让这右链的最后一个点指向这颗子树的父节点的右子树的根节点，并且把右子树和父节点之间的连接抹掉，然后再去递归解决剩下的部分（紫色圆圈所描述的区域），最后就能把二叉树转化成链表，如下所示：

（而且根据协议，我们是从二叉树最外层的外链来进行转化的，一定可以确保正确性）

![IMG_2485.jpg](https://pic.leetcode-cn.com/1657450876-ixTWOF-IMG_2485.jpg)


并且由于前面的协议是可以迭代实现的，能通过迭代达到递归的效果，也没有用栈模拟递归，所以其实空间复杂度可以是O(1)

所以说本质上我们是通过前序遍历的性质来修改二叉树节点的指针，然后把二叉树转变成了符合要求的链表

代码实现：
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
    void flatten(TreeNode* root) {
        while(root) {
            if(root->left) {
                auto left_node = root->left;
                while(left_node->right) {
                    left_node = left_node->right;
                }
                left_node->right = root->right;
                root->right = root->left;
                root->left = nullptr;
                root = root->right;
            }
            else {
                root = root->right;
            }
        }
    }
};
```

参考自:

www.acwing.com

https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/solution/er-cha-shu-zhan-kai-wei-lian-biao-by-leetcode-solu/

