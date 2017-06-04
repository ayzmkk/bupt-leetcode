/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct node {
    int val;
    ListNode *p;
    node(int _val, ListNode *_p) : val(_val) , p(_p) {}
    bool operator < (const node & a) const {
        return val > a.val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<node> q;
        ListNode *res = new ListNode(0);
        ListNode *build = res;
        for(auto li : lists) {
            if(li) {
                q.push(node(li->val,li));
            }
        }
        while(!q.empty()) {
            auto top = q.top(); q.pop();
            build->next = top.p;
            if(top.p->next) q.push(node(top.p->next->val, top.p->next));
            build = build->next;
        }
        return res->next;
    }
};