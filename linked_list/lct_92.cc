// https://leetcode.cn/problems/reverse-linked-list-ii/
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);
        // 哨兵节点
        ListNode* p0 = &dummy;
        int i = 0;
        while(i < left - 1) {
            p0 = p0->next;
            i++;
        }
        // 反转链表算法
        ListNode *pre = nullptr;
        ListNode *cur = p0->next;
        i = 0;
        while(i < right - left + 1) {
            auto next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            i++;
        }
        p0->next->next = cur;
        p0->next = pre;
        return dummy.next;
    }
};