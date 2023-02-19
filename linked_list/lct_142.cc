// https://leetcode.cn/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// head到环扣为a， 环口到相遇点为b ， 相遇点到环口为c
// slow走了 a + b, fast走了 a + b + k(b + c)
// (a + b) * 2 = a + b + k(b + c)
// a - c = (k - 1) (b + c)
// 说明head走c步， slow也走c步后， 两个相差环的倍数。再继续走下去就可以在环口相遇 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                while(head != slow) {
                    head = head->next;
                    slow = slow->next;
                }
                return head;
            }
        }
        return NULL;
    }
};