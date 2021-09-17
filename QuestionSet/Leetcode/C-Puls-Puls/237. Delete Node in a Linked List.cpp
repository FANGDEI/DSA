/*
 * @Author: FANG
 * @Date: 2021-09-11 14:22:02
 * @LastEditTime: 2021-09-11 14:22:03
 * @Description: Delete Node in a Linked List
 * @FilePath: \DSA\QuestionSet\Leetcode\237. Delete Node in a Linked List.cpp
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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
        // delete(node->next);
    }
};