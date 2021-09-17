/*
 * @Author: FANG
 * @Date: 2021-09-12 23:19:00
 * @LastEditTime: 2021-09-12 23:19:01
 * @Description: Linked List Cycle
 * @FilePath: \DSA\QuestionSet\Leetcode\141. Linked List Cycle.cpp
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *slow, *fast;
        slow = fast = head;
        while (fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) return true;
        }
        return false;
    }
};