// https://leetcode.cn/problems/remove-duplicates-from-sorted-list/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        auto cur = head;
        while(cur->next) {
            if (cur->val == cur->next->val) {
                auto nxt = cur->next;
                cur->next = cur->next->next;
                delete nxt;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};