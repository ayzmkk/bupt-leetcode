#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      int len =0;
      ListNode* p = head;
      while(p!=NULL)
      {
        len++;
        p = p->next;
      }
      p = head;

      int del_pos = len-n+1;
      if(del_pos ==1) return head->next;
      int t =2;
      while(t!=del_pos)
      {
        p = p->next;
        t++;
      }

      p->next = p->next->next;
      return head;
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
  res = s.removeNthFromEnd(head,5);
  while(res!=NULL)
  {
    cout<<res->val<<" ";
    res = res->next;
  }
  cout<<endl;
  return 0;
}
