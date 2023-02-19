// https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/

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
        ListNode dummy(0, head);
        ListNode* cur = &dummy;
        while(cur->next && cur->next->next) {
            int value = cur->next->val;
            if (cur->next->next->val == value) {
                while(cur->next && cur->next->val == value) {
                    auto nxt = cur->next;
                    cur->next = cur->next->next;
                    delete nxt;
                }
            } else {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};