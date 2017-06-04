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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * s = head , *f = head, *pre = NULL;
        for(int i=0;i<n;i++) f = f->next;
        while(f) {
            pre = s;
            s = s->next;
            f = f->next;
        }
        if(!pre) return head->next;
        pre->next = pre->next->next;
        return head;
    }
};