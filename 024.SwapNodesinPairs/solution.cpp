#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      if(head == NULL || head->next == NULL) return head;
      ListNode* tmp = head->next;
      head->next = swapPairs(tmp->next);
      tmp->next = head;
      return tmp;
    }
};

int main()
{
  ListNode *head=NULL;
  ListNode *p=NULL;
  ListNode *res=NULL;
  ListNode *pnode;
  pnode = new ListNode(1);
  head = pnode; p=head;
  int val[] = {2,3,4,5};
  for(int i=0;i<4;i++)
  {
    pnode = new ListNode(val[i]);
    p->next = pnode;
    p = p->next;
  }

  Solution s;
  res = s.swapPairs(head);
  while(res!=NULL)
  {
    cout<<res->val<<" ";
    res = res->next;
  }
  cout<<endl;
  return 0;
}
