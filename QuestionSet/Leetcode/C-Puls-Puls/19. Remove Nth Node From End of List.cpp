/*
 * @Author: FANG
 * @Date: 2021-09-11 14:55:05
 * @LastEditTime: 2021-09-11 14:55:05
 * @Description: Remove Nth Node From End of List
 * @FilePath: \DSA\QuestionSet\Leetcode\19. Remove Nth Node From End of List.cpp
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr) return nullptr;
        ListNode *dummy = new ListNode(0, nullptr);
        dummy->next = head;
        ListNode *fast, *slow;
        fast = head;
        slow = dummy;
        for (int i = 0; i < n; i++) fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        head = dummy->next;
        delete(dummy);
        return head;
    }
};