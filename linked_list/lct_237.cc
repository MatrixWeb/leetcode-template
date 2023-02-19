// https://leetcode.cn/problems/delete-node-in-a-linked-list/
// 删除链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* nxt = node->next;
        node->next = node->next->next;
        delete nxt;
    }
};