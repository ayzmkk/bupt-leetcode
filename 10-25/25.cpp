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
    ListNode *reverse(ListNode *head) {
        ListNode *p = head , *q = p->next;
        while(q) {
            ListNode *r = q->next;
            q->next = p;
            if(p == head) p->next = NULL;
            p = q;
            q = r;
        } 
        return p;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode *pre = head;
        int n = k;
        while(--n && pre) pre = pre->next;
        if(pre == NULL) return head;
        
        ListNode *next = pre->next;
        pre->next = NULL;

        ListNode *newHead = reverse(head);
        head->next = reverseKGroup(next,k);
        return newHead;
    }
};