#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      if(head == NULL || k==1) return head;
      // 加了一个冗余的头节点，方便翻转和返回头指针。
      ListNode *redun = new ListNode(0);
      redun->next = head;
      ListNode *pre = redun,*cur = head;
      int cnt =0;
      while(cur)
      {
        cnt++;
        if(cnt%k) cur = cur->next;
        else
        {
          pre = reverseOneGroup(pre,cur->next);
          cur = pre->next;
        }
      }
      return redun->next;
    }

    ListNode* reverseOneGroup(ListNode* pre,ListNode* next){
      ListNode* cur = pre->next;
      ListNode* cur_next = cur->next;

      //相当于使用头插法
      while(cur_next!=next)
      {
        cur->next = cur_next->next;
        cur_next->next = pre->next;
        pre->next = cur_next;
        cur_next = cur->next;
      }
      return cur;
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
  res = s.reverseKGroup(head,3);
  while(res!=NULL)
  {
    cout<<res->val<<" ";
    res = res->next;
  }
  cout<<endl;
  return 0;
}
