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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *newHead = head->next;
        ListNode *next = newHead->next;
        newHead->next = NULL;
        newHead->next = head;
        head->next = NULL;
        head->next = swapPairs(next);
        return newHead;
    }
};