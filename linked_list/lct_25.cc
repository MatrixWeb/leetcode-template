// https://leetcode.cn/problems/reverse-nodes-in-k-group/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 哨兵
        ListNode dummy(0, head);
        int n = 0;
        auto cur = head;
        while(cur) {
            n++;
            cur = cur->next;
        }
        ListNode* p0 = &dummy;
        // 反转链表算法
        cur = head;
        ListNode* pre = nullptr;
        while(n >= k) {
            n -= k;
            for (int i = 0; i < k; i++) {
                auto nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            // 需要记录下一组反转的前一个p0指针
            auto nxt = p0->next;
            p0->next->next = cur;
            p0->next = pre;
            p0 = nxt;
        }
        return dummy.next;
    }
};