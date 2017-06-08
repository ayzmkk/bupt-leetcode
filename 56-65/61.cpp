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
    int getLen(ListNode *head) {
        int n = 0;
        while(head) {
            n ++;
            head = head->next;
        }
        return n;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int n = getLen(head);
        k = k % n;
        if(k == 0) return head;
        int m = n - k;
        ListNode *pre = head, *p = head;
        while(m--) {
            pre = p;
            p = p->next;
        }
        pre->next = NULL;
        ListNode *t = p;
        while(t->next) {
            t = t->next;
        }
        t->next = head;
        return p;
    }
};