#include<iostream>
using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      /*
      尾插法
      头节点head，新增节点pnode，移动节点p
      如果和大于10，进1.  进位标志是flag。
      */
      ListNode *head = NULL;
      ListNode *p = NULL;
      ListNode *pnode = NULL;
      int flag = 0,add;
      while(l1!=NULL || l2!=NULL || flag==1)
      {
        add = flag;
        if(l1!=NULL)
        {
          add += l1->val;
          l1 = l1->next;
        }
        if(l2!=NULL)
        {
          add += l2->val;
          l2 = l2->next;
        }
        if(add>=10)
        {
          add-=10;
          flag=1;
        }
        else
          flag=0;

        pnode = new ListNode(add);
        if(head==NULL)
        {
          head = pnode;
          p = pnode;
        }
        else
        {
          p->next = pnode;
          p = p->next;
        }
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
    l = s.addTwoNumbers(l1,l2);
    cout<<"get the sum: "<<endl;
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
2 4 3
5 6 4
*/s
