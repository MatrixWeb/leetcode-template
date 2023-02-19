// https://leetcode.cn/problems/validate-binary-search-tree/

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
// 前序遍历
class Solution {
public:
    bool isBST(TreeNode* root, long left, long right) {
        if (root == nullptr) return true;
        int x = root->val;
        return (left < root->val) && (right > root->val) && isBST(root->left, left, x) && isBST(root->right, x, right);
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
    }
};
// 中序遍历
class Solution {
public:
    long pre = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        if (!isValidBST(root->left)) return false;
        if (root->val <= pre) return false;
        pre = root->val;
        return isValidBST(root->right);
    }
};