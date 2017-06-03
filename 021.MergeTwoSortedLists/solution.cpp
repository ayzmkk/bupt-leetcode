#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode* head = NULL;
      ListNode* p = NULL;
      ListNode* tmp = NULL;
      while(l1!=NULL && l2!=NULL)
      {
        int flag = 0;
        if(l1->val < l2->val)
        {
          flag=1;
          tmp =l1;
        }
        else tmp = l2;

        if(head==NULL)
        {
          p = head = tmp;
          tmp = tmp->next;
          head->next = NULL;
        }
        else
        {
          p->next = tmp;
          p = p->next;
          tmp = tmp->next;
          p->next = NULL;
        }
        if(flag) l1=tmp;
        else l2=tmp;
      }
      if(head==NULL)
      {
        if(l1) head = l1;
        if(l2) head = l2;
      }
      else
      {
        if(l1) p->next =l1;
        if(l2) p->next = l2;
      }
      return head;
    }
};

int main()
{
  int n1,n2,i;
  int val;
  while(cin>>n1>>n2)
  {
    ListNode *l1=NULL;
    ListNode *l2=NULL;
    ListNode *p=NULL;
    ListNode *l=NULL;
    for(i=0;i<n1+n2;i++)
    {
      cin>>val;
      ListNode *pnode;
      pnode = new ListNode(val);
      //link the new node to the tail of l1 and l2
      if(i<n1)
      {
        if(l1==NULL)
        {
          l1 = pnode;
          p = l1;
        }
        else
        {
          p->next = pnode;
          p = p->next;
        }
      }
      else
      {
        if(l2==NULL)
        {
          l2 = pnode;
          p = l2;
        }
        else
        {
          p->next = pnode;
          p = p->next;
        }
      }
    }

    Solution s;
    l = s.mergeTwoLists(l1,l2);
    while(l!=NULL)
    {
      cout<<l->val<<" ";
      l = l->next;
    }
  }
  return 0;
}

/*
3 3
2 3 4
4 5 6
0 1
0
*/
