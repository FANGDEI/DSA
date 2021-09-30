/*
 * @Author: FANG
 * @Date: 2021-09-30 22:26:51
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode();
        ListNode *cur = res;
        int carry = 0;
        while (l1 || l2 || carry) {
            int l1_val = l1 != nullptr ? l1->val : 0;
            int l2_val = l2 != nullptr ? l2->val : 0;
            int sum = l1_val + l2_val + carry;
            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            cur->next = node;
            cur = node;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        return res->next;
    }
};