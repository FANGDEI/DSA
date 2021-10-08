/*
 * @Author: FANG
 * @Date: 2021-10-08 12:55:34
 */
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0), *pre, *cur;
        dummy->next = head;
        pre = dummy, cur = head;
        while (cur != nullptr) {
            if (cur->val == val) {
                pre->next = cur->next;
                delete(cur);
                cur = pre->next;
                pre->next = cur;
            } else {
                pre = cur;
                cur = pre->next;
            }
        }
        return dummy->next;
    }
};