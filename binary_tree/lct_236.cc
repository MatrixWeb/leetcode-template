// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 分类讨论

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      // p， q在当前节点，或是当前节点为空，返回当前节点
      if (root == NULL || root == p || root == q) return root;
      TreeNode* left = lowestCommonAncestor(root->left, p, q);
      TreeNode* right = lowestCommonAncestor(root->right, p, q);
      // 左右都存在，返回当前节点，为公共祖先
      if (left && right) return root;
      if (left) return left;
      return right;
    }
};