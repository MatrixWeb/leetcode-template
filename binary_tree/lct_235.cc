// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 最近公共祖先
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int x = root->val;
        if (p->val < x && q->val < x) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (p->val > x && q->val > x) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};