// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      // 哨兵
        ListNode dummy(0, head);
        auto left = &dummy;
        auto right = &dummy;
        for (int i = 0; i < n; i++) right = right->next;
        while(right->next) {
            left = left->next;
            right = right->next;
        }
        auto nxt = left->next;
        left->next = left->next->next;
        delete nxt;
        return dummy.next;
    }
};