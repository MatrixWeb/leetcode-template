
// https://leetcode.cn/problems/reorder-list/

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
    // 获取中间节点
    ListNode* get_mid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // 反转链表
    ListNode * reverse(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur) {
            auto nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
    void reorderList(ListNode* head) {
        auto mid = get_mid(head);
        auto head2 = reverse(mid);
        while(head2->next) {
            auto nxt = head->next;
            auto nxt2 = head2->next;
            head2->next = nxt;
            head->next = head2;
            head = nxt;
            head2 = nxt2;
        }
    }
};