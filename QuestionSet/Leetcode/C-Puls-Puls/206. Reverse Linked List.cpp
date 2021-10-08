/*
 * @Author: FANG
 * @Date: 2021-09-11 14:36:54
 * @LastEditTime: 2021-10-08 12:59:38
 * @Description: Reverse Linked List
 * @FilePath: \DSA\QuestionSet\Leetcode\206. Reverse Linked List.cpp
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
// Recursion:
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        // reverseList(head->next);
        ListNode *nhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return nhead;
    }
};
// Iteration
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre, *cur, *next;
        cur = head;
        pre = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};