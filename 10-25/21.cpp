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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *newHead = new ListNode(0);
        ListNode *build = newHead, *p = l1, *q = l2;
        while(p || q) {
            if(p && q) {
                if(p->val < q->val) {
                    build->next = p;
                    p = p->next;
                }else {
                    build->next = q;
                    q = q->next;
                }
            }else if(p) {
                build->next = p;
                p = p->next;
            }else {
                build->next = q;
                q = q->next;
            }
            build = build ->next;
        }
        return newHead->next;
    }
};